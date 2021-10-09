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
    int pos,ele;
    cout<<"Position to be inserted : ";
    cin>>pos;
    cout<<"Element to be inserted : ";
    cin>>ele;
    for(int i=n;i>=pos;i--)
    {
        a[i+1]=a[i];
    }
    a[pos]=ele;
    for(int i=0;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
