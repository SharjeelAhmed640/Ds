#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;
void searchright(char **arr, int n, int m, string search)
{
    int i, j, k = 0, l;
    int counter = 0;
    bool found = false;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] == search[0] || arr[i][j] == '*' || arr[i][j] == '+')
            {
                for (k = 0; k < search.length(); k++)
                {
                    found = false;
                    if (arr[i][j + k] == '+' || arr[i][j + k] == '?')
                    {
                        found = true;
                        continue;
                    }
                    if (arr[i][j + k] == '*')
                    {

                        if (arr[i][j + k + 1] == search[search.length() - 1] || arr[i][j + k + 3] == search[search.length() - 1] || arr[i][j + k + 2] == search[search.length() - 1] || arr[i][j + k + 4] == search[search.length() - 1])
                        {
                            found = true;
                            break;
                        }
                    }
                    if (arr[i][j + k] == search[k])
                    {
                        found = true;
                    }
                    if (found == false)
                    {
                        break;
                    }
                }
                if (found)
                {
                    cout << i << " " << j << " R";
                    goto end;
                }
            }
        }
    }
end:
    if (found)
        cout << endl;
}
void searchdown(char **arr, int n, int m, string search)
{
    int i, j = 0, k = 0, l;
    int counter = 0;
    bool found = false;
    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            //	cout << "i : " << i << "    j : " << j << endl;
            if (arr[i][j] == search[0] || arr[i][j] == '+' || arr[i][j] == '*')
                for (k = 0; k < search.length(); k++)
                {
                    //cout << "k : " << k << endl;
                    {
                        found = false;
                        if(k+i==search.length() || k+i==search.length()-1)
                        {
                            goto end;
                        }
                        if (arr[i + k][j] == '+')
                        {

                            found = true;
                            continue;
                        }
                        if ((arr[i + k + 1][j] != search[k + 1] && k + 1 < search.length()) || k + 1 >= search.length())
                        {
                            found = false;
                            goto end;
                        }
                        else if (arr[i + k][j] == '*')
                        {

                            if (arr[i + k + 1][j] == search[search.length() - 1] || arr[i + k + 3][j] == search[search.length() - 1] || arr[i + k + 2][j] == search[search.length() - 1])
                            {
                                found = true;
                                break;
                            }
                        }
                        else if (arr[i + k][j] == search[k])
                        {
                            found = true;
                        }
                        if (found == false)
                        {
                            break;
                        }
                        //cout<<"found : "<<found<<endl;
                    }
                    //b:
                    if (found)
                    {
                        cout << i << " " << j << " D";
                        goto end;
                    }
                }
        }
    }
end:
    if (found)
        cout << endl;
}

void search(char **arr, int n, int m, string *search, int Ns)
{

    for (int i = 1; i < Ns; i++)
    {
        searchright(arr, n, m, search[i]);

        searchdown(arr, n, m, search[i]);

        //cout << search[i] << endl;
    }
}
void input(char **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << "[" << i << "][" << j << "]  :  ";
            cin >> arr[i][j];
        }
    }
}
void print(char **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, m, Ns;
    cin >> n >> m;
    char **arr = new char *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[m];
    }
    input(arr, n, m);
    cin >> Ns;
    Ns++;
    string str[Ns];
    char c;
    int count = 0;
    for (int i = 0; i < Ns; i++)
    {
        count = 0;

        count = 0;
        while (1)
        {
            c = getchar();
            if (c == 10)
                break;
            if (c != ' ')
            {
                str[i] += c;
                count++;
            }
        }
        str[i][count] = '\0';
    }

    // searchright(arr, n, m, "mango");
    //searchdown(arr,n,m,"mango");
    search(arr, n, m, str, Ns);
    return 0;
}