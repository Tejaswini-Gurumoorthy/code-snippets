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
    int temp;
    for(int j=1;j<n;j++)
    {
        int i=j-1;
        temp=a[j];
        while(i>=0 && a[i]>temp)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=temp;
    }
    cout<<"THE SORTED ARRAY IS: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
