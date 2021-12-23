#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    char fileindex;
    fstream my_file;
    string s, word;
    int flag = 0;
    cin >> word;
    fileindex = word[0];
    for_each(word.begin(), word.end(), [](char &c)
             { c = ::toupper(c); });
    if (fileindex == 'a')
    {
        my_file.open("c:\\a.txt", ios::in);
    }
    if (fileindex == 'b')
    {
        my_file.open("c:\\b.txt", ios::in);
    }
    if (fileindex == 'c')
    {
        my_file.open("c:\\c.txt", ios::in);
    }
    if (fileindex == 'd')
    {
        my_file.open("c:\\d.txt", ios::in);
    }
    if (fileindex == 'e')
    {
        my_file.open("c:\\e.txt", ios::in);
    }
    if (fileindex == 'f')
    {
        my_file.open("c:\\f.txt", ios::in);
    }
    if (fileindex == 'g')
    {
        my_file.open("c:\\g.txt", ios::in);
    }
    if (fileindex == 'h')
    {
        my_file.open("c:\\h.txt", ios::in);
    }
    if (fileindex == 'i')
    {
        my_file.open("c:\\i.txt", ios::in);
    }
    if (fileindex == 'j')
    {
        my_file.open("c:\\j.txt", ios::in);
    }
    if (fileindex == 'k')
    {
        my_file.open("c:\\k.txt", ios::in);
    }
    if (fileindex == 'l')
    {
        my_file.open("c:\\l.txt", ios::in);
    }
    if (fileindex == 'm')
    {
        my_file.open("c:\\m.txt", ios::in);
    }
    if (fileindex == 'n')
    {
        my_file.open("c:\\n.txt", ios::in);
    }
    if (fileindex == 'o')
    {
        my_file.open("c:\\o.txt", ios::in);
    }
    if (fileindex == 'p')
    {
        my_file.open("c:\\p.txt", ios::in);
    }
    if (fileindex == 'q')
    {
        my_file.open("c:\\q.txt", ios::in);
    }
    if (fileindex == 'r')
    {
        my_file.open("c:\\r.txt", ios::in);
    }
    if (fileindex == 's')
    {
        my_file.open("c:\\s.txt", ios::in);
    }
    if (fileindex == 't')
    {
        my_file.open("c:\\t.txt", ios::in);
    }
    if (fileindex == 'u')
    {
        my_file.open("c:\\u.txt", ios::in);
    }
    if (fileindex == 'v')
    {
        my_file.open("c:\\v.txt", ios::in);
    }
    if (fileindex == 'w')
    {
        my_file.open("c:\\w.txt", ios::in);
    }
    if (fileindex == 'x')
    {
        my_file.open("c:\\x.txt", ios::in);
    }
    if (fileindex == 'y')
    {
        my_file.open("c:\\y.txt", ios::in);
    }
    if (fileindex == 'z')
    {
        my_file.open("c:\\z.txt", ios::in);
    }
    if (!my_file.is_open())
    {
        cout << "Unable to open" << endl;
    }
    while (getline(my_file, s))
    {
        // cout << s << endl;
        if (s == word)
        {
            flag = 1;
        }
    }
    cout << flag;

    return 0;
}