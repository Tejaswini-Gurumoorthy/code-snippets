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
    int ele,pos,f=0;
    cout<<"Enter element"<<endl;
    cin>>ele; 
    int first=0,last=n;
    while(first<=last)
    {
        int mid= (first+last)/2;
        if(a[mid]==ele)
        {
            pos=mid;
            f=1;
            break;
        }
        else if(ele<a[mid])
        {
            last=mid-1;
            
        }
        else
        {
            first=mid+1;
        }
    }
    if(f)
    {
        cout<<"Element found at index "<<pos+1<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }
}
