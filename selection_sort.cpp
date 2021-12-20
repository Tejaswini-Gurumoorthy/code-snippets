#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n],idx;
    cout<<"Enter array elements : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int temp;
    for(int i=0;i<n-1;i++)
    {
        idx=i;
        for(int j=i;j<5;j++)
        {   
            if(arr[j]<arr[idx])
            {
                idx=j;
            }
        }
        temp=arr[idx];
        arr[idx]=arr[i];
        arr[i]=temp;
    }
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


}

