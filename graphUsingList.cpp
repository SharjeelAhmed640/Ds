#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
#define INT_MAX 9999
template <typename T>
class Node
{
public:
    T val;
    int weight;
    Node *next;
    Node *prev;

    Node<T>()
    {
        next = NULL;
        prev = NULL;
        val = 0;
        weight = 0;
    }
    Node<T>(T val, int weight)
    {
        next = NULL;
        prev = NULL;
        this->val = val;
        this->weight = weight;
    }
    // ~Node<T>()
    // {
    //     delete next;
    //     delete prev;
    // }
};
template <typename T>
class DoubleList
{

public:
    Node<T> *head;
    DoubleList(Node<T> *n)
    {
        head = n;
    }
    DoubleList()
    {
        head = NULL;
    }
    void insertAtEnd(T val, int weight)
    {

        Node<T> *temp = head;
        Node<T> *ptr = new Node<T>(val, weight);
        if (head == NULL)
        {

            head = ptr;
            return;
        }

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = ptr;
        ptr->next = NULL;
        ptr->prev = temp;
    }
    void insertAtBeg(T val, int weight)
    {
        Node<T> *temp = head;
        Node<T> *ptr = new Node<T>(val, weight);
        if (head == NULL)
        {
            head = ptr;
            return;
        }
        temp->prev = ptr;
        ptr->next = temp;
        ptr->prev = NULL;
        head = ptr;
    }
    void insertAtKey(T val, int weight, int key)
    {
        Node<T> *temp = head;
        Node<T> *ptr = new Node<T>(val, weight);
        if (head == NULL)
        {
            head = ptr;
            return;
        }
        int i = 0;
        if (key == 0)
        {
            this->insertAtBeg(val, weight);
            return;
        }
        while (temp != NULL)
        {
            if ((i + 1) == key)
                break;

            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            this->insertAtEnd(val, weight);
            return;
        }
        ptr->next = temp->next;
        temp->next->prev = ptr;
        temp->next = ptr;
        ptr->prev = temp;
    }
    void delHead()
    {
        Node<T> *temp = head;
        Node<T> *ptr = head;
        temp = temp->next;
        temp->prev = NULL;
        delete (ptr);
        head = temp;
    }
    void delTail()
    {
        Node<T> *temp = head;
        Node<T> *ptr = head;
        temp = temp->next;

        while (temp->next != NULL)
        {
            temp = temp->next;
            ptr = ptr->next;
        }
        ptr->next = NULL;
        delete temp;
    }
    void delAtindex(int index)
    {
        if (head == NULL)
            return;
        if (index == 0)
        {
            this->delHead();
            return;
        }
        Node<T> *temp = head;
        Node<T> *ptr = head;
        temp = temp->next;
        int i = 0;
        while (temp != NULL)
        {
            if ((i + 1) == index)
                break;
            temp = temp->next;
            ptr = ptr->next;
            i++;
        }
        if (temp->next == NULL)
        {
            this->delTail();
            return;
        }
        if ((i + 1) == index)
        {
            temp->next->prev = ptr;
            ptr->next = temp->next;
            delete (temp);
            return;
        }

        {
            cout << "Unvalid index" << endl;
        }
    }
    void triversal()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};
template <typename T>
class graph
{
    DoubleList<T> *vertices;
    int Totalvertices;
    int highestnode;

public:
    graph()
    {
        highestnode = 0;
        vertices = NULL;
        Totalvertices = 0;
    }
    graph(int n)
    {

        highestnode = 0;
        Totalvertices = n;
        vertices = new DoubleList<T>[Totalvertices];
    }

    // true for directed  false for undirected
    void Addvertics(int u, T val, int weight, bool direction)
    {
        if (highestnode < u)
            highestnode = u;
        if (highestnode < val)
            highestnode = val;

        if (u >= Totalvertices)
        {
            DoubleList<T> *temp;
            temp = vertices;
            vertices = new DoubleList<T>[u + 1];
            for (int i = 0; i < Totalvertices; i++)
            {

                vertices[i] = temp[i];
            }

            Totalvertices = u + 1;
            delete[] temp;
        }
        vertices[u].insertAtEnd(val, weight);

        if (!direction)
        {
            if (val >= Totalvertices)
            {
                DoubleList<T> *temp;
                temp = vertices;
                vertices = new DoubleList<T>[val + 1];
                for (int i = 0; i < Totalvertices; i++)
                {

                    vertices[i] = temp[i];
                }

                Totalvertices = val + 1;
                delete[] temp;
            }
            vertices[val].insertAtEnd(u, weight);
        }
    }
    void showGraph()
    {
        cout << "*********Displaying*********" << endl;
        if (vertices != NULL)
        {
            for (int i = 0; i < Totalvertices; i++)
            {
                if (vertices[i].head != NULL)
                {
                    cout << i << "-->";
                    vertices[i].triversal();
                }
            }
        }
    }
    void bfs(T s)
    {
        bool *isvisited = new bool[Totalvertices]{false};
        queue<int> track;
        track.push(s);
        isvisited[s] = true;
        cout << endl
             << "********* BFS *********" << endl;
        while (!track.empty())
        {
            s = track.front();
            cout << s << " ";
            track.pop();
            if (s < Totalvertices)
                for (Node<T> *ptr = this->vertices[s].head; ptr != NULL; ptr = ptr->next)
                {
                    if (!isvisited[ptr->val])
                    {
                        isvisited[ptr->val] = true;
                        track.push(ptr->val);
                    }
                }
        }
    }
    void dfs(T s)
    {
        bool *isvisited = new bool[Totalvertices]{false};
        stack<int> track;
        track.push(s);
        isvisited[s] = true;
        cout << endl
             << "********* DFS *********" << endl;
        while (!track.empty())
        {
            s = track.top();
            cout << s << " ";
            track.pop();

            if (s < Totalvertices)
            {
                for (Node<T> *ptr = this->vertices[s].head; ptr != NULL; ptr = ptr->next)
                {
                    if (!isvisited[ptr->val])
                    {
                        isvisited[ptr->val] = true;
                        track.push(ptr->val);
                    }
                }
            }
        }
    }
    bool isCyclic(int s, bool visited[], bool track[])
    {
        if (!visited[s])
        {
            visited[s] = true;
            track[s] = true;
            if (s < Totalvertices)
                for (Node<T> *i = vertices[s].head; i != NULL; i = i->next)
                {
                    if (!visited[i->val] && isCyclic(i->val, visited, track))
                        return true;
                    else if (track[i->val])
                        return true;
                }
            track[s] = false;
            return false;
        }
    }
    bool CycleDetectionDirected(T s)
    {
        bool *visited = new bool[Totalvertices];
        bool *track = new bool[Totalvertices];
        for (int i = 0; i < Totalvertices; i++)
        {
            visited[i] = false;
            track[i] = false;
        }
        for (int i = s; i < Totalvertices; i++)
        {
            if (isCyclic(i, visited, track))
                return true;
        }
        return false;
    }

    bool ifduplicate(queue<int> track, int val)
    {
        while (!track.empty())
        {
            int t = track.front();
            if (t == val)
                return true;
            track.pop();
        }
        return false;
    }
    bool CycleDetectionUndirected(T s)
    {

        bool *isvisited = new bool[Totalvertices]{false};
        queue<int> track;
        track.push(s);

        while (!track.empty())
        {
            s = track.front();
            isvisited[s] = true;
            track.pop();
            if (s < Totalvertices)
                for (Node<T> *ptr = this->vertices[s].head; ptr != NULL; ptr = ptr->next)
                {
                    if (!isvisited[ptr->val])
                    {

                        if (ifduplicate(track, ptr->val))
                            return true;
                        track.push(ptr->val);
                    }
                }
        }
        return false;
    }
    void topologicalDFS(vector<bool> &visited, stack<int> &ans, int v)
    {
        visited[v] = true;
        if (v < Totalvertices)
            for (Node<T> *ptr = this->vertices[v].head; ptr != NULL; ptr = ptr->next)
            {
                if (!visited[ptr->val])
                {
                    topologicalDFS(visited, ans, ptr->val);
                }
            }
        ans.push(v);
    }
    void topological_sort()
    {
        vector<bool> visited{false};
        stack<int> ans;
        for (int i = 0; i < Totalvertices; ++i)
        {
            if (!visited[i])
                topologicalDFS(visited, ans, i);
        }

        cout << endl
             << "******* Topological sort ******" << endl;
        while (!ans.empty())
        {
            int d = ans.top();
            ans.pop();
            cout << d << " ";
        }
        cout << endl;
    }
    void shortestpath(int s)
    {
        vector<bool> visited{false};
        stack<int> ans;
        int *dist = new int[Totalvertices];
        for (size_t i = 0; i < Totalvertices; i++)
        {
            dist[i] = INT_MAX;
        }
        for (int i = 0; i < Totalvertices; i++)
            if (!visited[i])
                topologicalDFS(visited, ans, i);

        dist[s] = 0;
        while (!ans.empty())
        {
            int u = ans.top();
            ans.pop();
            if (dist[u] != INT_MAX)
                for (Node<T> *ptr = this->vertices[u].head; ptr != NULL; ptr = ptr->next)
                {
                    if (dist[ptr->val] > dist[u] + ptr->weight)
                        dist[ptr->val] = dist[u] + ptr->weight;
                }
        }
        cout << "Shortest distance from source : " << char(65 + s) << endl;
        for (int i = 0; i < Totalvertices; i++)
        {
            cout << char(65 + i) << "\t\t";
            if (dist[i] == INT_MAX)
                cout << "INF"
                     << " ";
            else
                cout << dist[i] << " ";
            cout << endl;
        }
        delete dist;
    }
    void Floyd_Warshall()
    {
        for (int i = 0; i < Totalvertices; i++)
        {
            shortestpath(i);
        }
    }
};

int main()
{
    graph<int> g;
    // g.Addvertics(0, 2, 0, true);
    // g.Addvertics(0, 2, 0, true);
    // g.Addvertics(0, 2, 0, true);
    // g.Addvertics(1, 0, 0, true);
    // g.Addvertics(1, 2, 0, true);
    // g.Addvertics(2, 0, 0, true);
    // g.Addvertics(2, 1, 0, true);
    // g.Addvertics(2, 3, 0, true);
    // g.Addvertics(2, 4, 0, true);
    // g.Addvertics(3, 5, 0, true);
    // g.Addvertics(3, 4, 0, true);
    // g.Addvertics(3, 2, 0, true);
    // g.Addvertics(4, 3, 0, true);
    // g.Addvertics(4, 2, 0, true);
    // g.Addvertics(5, 3, 0, true);
    // g.Addvertics(5, 0, 0, true);
    // g.Addvertics(1, 2, 0, true);
    // g.Addvertics(1, 3, 0, false);
    // g.Addvertics(2, 3, 0, false);

    // g.Addvertics(0, 1, 5, true);
    // g.Addvertics(0, 2, 3, true);
    // g.Addvertics(1, 3, 6, true);
    // g.Addvertics(1, 2, 2, true);
    // g.Addvertics(2, 4, 4, true);
    // g.Addvertics(2, 5, 2, true);
    // g.Addvertics(2, 3, 7, true);
    // g.Addvertics(3, 4, -1, true);
    // g.Addvertics(4, 5, -2, true);
    // g.Addvertics(0, 1, 1, false);
    // g.Addvertics(1, 2, 2, false);
    // g.Addvertics(1, 4, 2, false);
    // g.Addvertics(4, 5, 2, false);
    // g.Addvertics(1, 6, 2, false);
    // g.Addvertics(2, 3, 2, false);
    // g.Addvertics(3, 4, 2, false);
    // g.Addvertics(4, 0, 2, false);
    // g.Addvertics(2, 0, 2, false);
    g.Addvertics(0, 1, 1, false);
    g.Addvertics(2, 1, 2, false);
    g.Addvertics(2, 3, 2, false);
    g.Addvertics(3, 0, 2, false);

    g.showGraph();
    g.bfs(1);
    g.dfs(1);
    // cout << endl
    //      << g.CycleDetectionDirected(1);
    cout << endl;
    cout << "CYCLE DETECTION(DIRECTED) : ";
    (g.CycleDetectionDirected(0) == 1) ? cout << "Cycle exist" << endl : cout << "Cycle does not exist" << endl;
    cout << "CYCLE DETECTION(UNDIRECTED) : ";
    (g.CycleDetectionUndirected(0) == 1) ? cout << "Cycle exist" << endl : cout << "Cycle does not exist" << endl;
    g.topological_sort();
    cout << endl;
    g.Floyd_Warshall();;
    return 0;
}