#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[],int start,int end, int ele)
{
    int mid=(start+end-1)/2;    
    if(a[mid]==ele)
    {
        return mid;
    }
    if(ele>a[mid])
    {
        binary_search(a,mid+1,end,ele);
    }
    else
    {
        binary_search(a, start, mid-1, ele);
    }
    return 0;



}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }  
    int ele,pos;
    cout<<"Enter element"<<endl;
    cin>>ele; 
    pos= binary_search(a,0,n,ele);
    
    if(pos)
    {
        cout<<"Element found at index "<<pos+1<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }
}
