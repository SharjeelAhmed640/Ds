#include<iostream>
using namespace std;
void print(string &str);
void BubbleSort(string &arr)
{
	char temp;
	bool check=false;
	int count=1;
	for(int i=0;i<arr.length()-i;i++)
	{	check=true;
		for(int j=0;j<arr.length()-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				cout<<"Working on pass "<<count++<<endl;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				check=false;
				
			}
			print(arr);
		}
		if(check)
		{
			break;
		}
	}
}
void print(string &str)
{
	for(int i=0;i<str.length();i++)
	{
	cout<<str[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	string arr;
	cout<<"Enter string : ";
	getline(cin,arr);
	BubbleSort(arr);
	
}