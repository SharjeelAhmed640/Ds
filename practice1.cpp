#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class array{
    int **arr;
    int row;
    int *col;
    public:
    array(int n)
    {
        row=n;
        arr=new int*[n];
        col=new int[n];
        int c;
        for(int i=0;i<n;i++){
            cout<<"For row "<<i<<" enter col size : ";
            cin>>c;
            arr[i]=new int[c];
            col[i]=c;
        }
    }
    void print()
    {
        for (int i = 0; i < row; i++)
        {
            for(int j=0;j<col[i];j++)
            cout<<arr[i][j]<<" ";
            cout<<endl;
        }
        
    }
    int getval(int r,int c)
    {
        if(r>=0 && r<row)
        {
            if(c>=0 && c<col[r])
            return arr[r][c];
        }
        cout<<"Out of bound"<<endl;
        return -999;
    }
};

int main(){

return 0;
}