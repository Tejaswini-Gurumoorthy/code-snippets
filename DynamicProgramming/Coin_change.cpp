#include <bits/stdc++.h>
using namespace std;

int coin_change(int coins[], int coin_num,int amt)
{
    int a[coin_num+1][amt+1];

    for(int i=0;i<=coin_num;i++)
    {
        a[i][0]=1;
    }
    for(int i=0;i<=amt;i++)
    {
        a[0][i]=0;
    }

    for(int i=1;i<=coin_num;i++)
    {
        for(int j=1;j<=amt;j++)
        {
           if(j<coins[i])
           {
               a[i][j]=a[i-1][j];
           } 
           else
           {
               a[i][j]=a[i-1][j]+a[i][j-coins[i]];
           }
        }
    }
    return a[coin_num][amt]; 
}

int main()
{
    int coin_num, amt;
    cout<<"Enter the number of denominations :"<<endl;
    cin>>coin_num;
    int coins[coin_num];
    cout<<"Enter the denominations :"<<endl;
    for(int i=0;i<coin_num;i++)
    {
        cin>>coins[i];
    }
    cout<<"Enter the amount :"<<endl;
    cin>>amt;
    int res= coin_change(coins,coin_num,amt);
    cout<<"Total number of ways : "<<res<<endl;


    
}
