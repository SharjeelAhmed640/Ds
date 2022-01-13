#include <iostream>
#include <iomanip>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
#define INT_MAX 999999
class Graph
{
    int **matrix;
    int size;

public:
    Graph()
    {
        matrix = NULL;
        size = -1;
    }
    Graph(int s)
    {
        size = s;
        *matrix = new int[size];
        for (int i = 0; i < size; i++)
        {
            matrix[i] = new int[size]{0};
        }
    }
    void Addvertics(int s, int d, int weight, bool directed)
    {
        if (s >= size || d >= size || d < 0 || s < 0)
        {
            cout << "Invalid vertice" << endl;
            return;
        }
        matrix[s][d] = weight;
        if (!directed)
        {
            matrix[d][s] = weight;
        }
    }
    void print()
    {
        for (size_t i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    int MinDistanceIndex(int dist[], bool visited[])
    {
        int min = INT_MAX, index;
        for (int i = 0; i < size; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                index = i;
            }
        }
        return index;
    }
    void PrimsMST()
    {
        int totalweight=0;
        int x, y, min;
        bool *visited = new bool[size]{false};
        visited[0] = true;
        for (int counter = 0; counter < size; counter++)
        {
            x = 0, y = 0, min = INT_MAX;
            for (size_t i = 0; i < size; i++)
            {
                if (visited[i])
                {
                    for (int j = 0; j < size; j++)
                    {
                        if (!visited[j] && matrix[i][j] > 0)
                        {
                            if (min > matrix[i][j])
                            {
                                min = matrix[i][j];
                                x = i, y = j;
                            }
                        }
                    }
                }
            }
            cout<<x<<" - "<<y<<"   :   "<<matrix[x][y]<<endl;
            visited[y]=true;
            totalweight+=matrix[x][y];
        }
        cout<<"Total weight of MST : "<<totalweight<<endl;
    }
    void DijkstraAlgo(int source)
    {
        int *dist = new int[size];
        bool *visited = new bool[size];
        for (int i = 0; i < size; i++)
        {
            dist[i] = INT_MAX;
            visited[i] = false;
        }
        dist[source] = 0;
        for (int i = 0; i < size; i++)
        {
            int m = MinDistanceIndex(dist, visited);
            visited[m] = true;
            for (int j = 0; j < size; j++)
            {
                if (!visited[j] && matrix[m][j] != 0 && dist[m] != INT_MAX && dist[m] + matrix[m][j] < dist[j])
                {
                    dist[j] = dist[m] + matrix[m][j];
                }
            }
        }
        cout << "Shortest distance from source : " << (char)(source + 65) << endl;
        for (int i = 0; i < size; i++)
        {
            cout << (char)(65 + i) << "\t\t";
            (dist[i] == INT_MAX) ? cout << "INF" << endl : cout << dist[i] << endl;
        }
        delete dist;
    }
    void Floyd_Warshall()
    {
        for (int i = 0; i < size; i++)
        {
            DijkstraAlgo(i);
        }
    }
    void DFS(int source)
    {
        stack<int> track;
        bool *visit = new bool[size]{false};
        visit[source] = true;
        track.push(source);

        cout << "******** DFS *******" << endl;
        while (!track.empty())
        {
            source = track.top();
            cout << (char)(65 + source) << " ";
            track.pop();
            for (int i = 0; i < size; i++)
            {
                if (!visit[i] && matrix[source][i] != 0)
                {
                    visit[i] = true;
                    track.push(i);
                }
            }
        }
        cout << endl;
    }
    void BFS(int source)
    {
        queue<int> track;
        bool *visit = new bool[size]{false};
        visit[source] = true;
        track.push(source);

        cout << "******** BFS *******" << endl;
        while (!track.empty())
        {
            source = track.front();
            cout << (char)(65 + source) << " ";
            track.pop();
            for (int i = 0; i < size; i++)
            {
                if (!visit[i] && matrix[source][i] != 0)
                {
                    visit[i] = true;
                    track.push(i);
                }
            }
        }
        cout << endl;
    }
    void TopologicalSort()
    {
        bool *visited = new bool[size]{false};
        int *indeg = new int[size]{0};
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (matrix[i][j] != 0)
                    indeg[i]++;
            }
        }
        cout << endl
             << "TOPOLOGICAL SORT" << endl;
        for (int count = 0; count < size; count++)
        {
            for (int j = 0; j < size; j++)
            {
                if (indeg[j] == 0 && visited[j] == false)
                {
                    cout << j << " ";
                    visited[j] = true;
                }
                for (int i = 0; i < size; i++)
                {
                    if (matrix[i][j] != 0)
                        indeg[j]--;
                }
            }
        }
    }
    bool isDuplicate(queue<int> track, int val)
    {
        while (!track.empty())
        {
            int d = track.front();
            if (d == val)
                return true;
            track.pop();
        }
        return false;
    }
    bool CycleDetectionUndircted(int s)
    {
        bool *visit = new bool[size];
        queue<int> track;
        int parent = -1;

        visit[s] = true;
        track.push(s);

        while (!track.empty())
        {
            s = track.front();
            track.pop();
            for (int i = 0; i < size; i++)
            {
                // cout << i << " ";
                if (parent != i && matrix[s][i] != 0)
                {
                    // cout << "   in if   ";
                    if (isDuplicate(track, i))
                        return true;
                    if (!visit[i])
                    {
                        track.push(i);
                        parent = s;
                    }
                }
            }
        }
        return false;
    }
    bool CycleDetectionDirected(int s)
    {
        bool *visit = new bool[size];
        bool *inpath = new bool[size];
        for (int i = 0; i < size; i++)
        {
            visit[i] = false;
            inpath[i] = false;
        }

        stack<int> track;
        track.push(s);

        while (!track.empty())
        {
            s = track.top();
            track.pop();
            visit[s] = true;
            inpath[s] = true;
            for (int i = 0; i < size; i++)
            {
                if (matrix[s][i] != 0)
                {
                    if (inpath[i])
                        return true;
                    if (!visit[i])
                    {
                        track.push(i);
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    /*       0  1  2  3  4  5
        0   {0, 1, 2, 0, 0, 0},
        1   {1, 0, 0, 5, 1, 0},
        2   {2, 0, 0, 2, 3, 0},
        3   {0, 5, 2, 0, 2, 2},
        4   {0, 1, 3, 2, 0, 1},
        5   {0, 0, 0, 2, 1, 0}};*/
    Graph g(9);
    /*
            0------1
                   |
                   |
                   2
    */
    g.Addvertics(0, 1, 4, false);
    g.Addvertics(0, 7, 8, false);

    g.Addvertics(1, 2, 8, false);
    g.Addvertics(1, 7, 11, false);

    g.Addvertics(2, 3, 7, false);
    g.Addvertics(2, 8, 2, false);
    g.Addvertics(2, 5, 4, false);

    g.Addvertics(3, 4, 9, false);
    g.Addvertics(3, 5, 14, false);

    g.Addvertics(4, 5, 10, false);

    g.Addvertics(5, 6, 2, false);

    g.Addvertics(6, 7, 1, false);
    g.Addvertics(6, 8, 6, false);

    g.Addvertics(8, 8, 7, false);


    // g.Addvertics(2, 0, 2, false);
    g.print();
    // g.print();
    g.DijkstraAlgo(0);
    g.Floyd_Warshall();
    g.DFS(0);
    g.BFS(0);
    g.TopologicalSort();
    cout << endl
         << "Cycle Detection Undirected   :     ";
    (g.CycleDetectionUndircted(0)) ? cout << "Cycle exist" << endl : cout << "Cycle does not exist" << endl;
    cout << endl
         << "Cycle Detection Directed     :     ";
    (g.CycleDetectionDirected(0)) ? cout << "Cycle exist" << endl : cout << "Cycle does not exist" << endl;
    cout << "******** MST **********" << endl;
    g.PrimsMST();
    return 0;
}