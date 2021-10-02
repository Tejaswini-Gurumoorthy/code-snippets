#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }   
    int min,temp,pos;
    for(int i=0;i<n;i++)
    {
        min=a[i];
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                pos=j;
            }

        }
        temp= a[pos]; 
        a[pos]=a[i];
        a[i]=temp;
    }
    cout<<"THE SORTED ARRAY IS: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
