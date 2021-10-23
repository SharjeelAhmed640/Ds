#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class Date{
        int month,year,day;
  public:
  Date()
  {
      day=0;
      month=0;
      year=0;
  }
  void setDate(int day,int month,int year)
  {
      this->day=day;
      this->month=month;
      this->year=year;
  }
  void insertionSort(Date *arr,int n)
  {
      int temp,j,minindex;
      for (int i = 0; i < n-1; i++)
      {
          minindex=i;
          for (j = i+1 ; j<n-1; j++)
          {
              if(arr[minindex].year>arr[j].year)
              minindex=j;
          }
          temp=arr[minindex].year;
          arr[minindex].year=arr[i].year;
          arr[i].year=temp;
      }
      
  }
  void print(Date  *arr,int n)
  {
      for (int i = 0; i < n; i++)
      {
          cout<<arr[i].day<<"//"<<arr[i].month<<"//"<<arr[i].year<<endl;
      }
      
  }
};

int main(){
int n,d,m,y;
cout<<"Enter size : : ";
cin>>n;
Date *arr=new Date[n];
for(int i=0;i<n;i++)
{
    cout<<"Enter day : ";
    cin>>d;
    cout<<"Enter month : ";
    cin>>m;
    cout<<"Enter year : ";
    cin>>y;
    arr[i].setDate(d,m,y);
    
}
arr->insertionSort(arr,n);
arr->print(arr,n);
return 0;
}