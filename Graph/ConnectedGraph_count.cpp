#include<bits/stdc++.h>
using namespace std;
const int N = 100  ;
vector<int> graph[N];
bool vis[N];

void dfs(int vertex)
{
    //1. After entering the vertex
    cout<<vertex<<" ";
    vis[vertex]= true;
    for(int child : graph[vertex])
    {
        // cout<<"parent : "<<vertex<<" child : "<<child<<endl;
        //2.Before entering child node
        if(vis[child])
        {
            continue;
        }
        dfs(child);
        //3. After exiting child node
    }
    //4. Before exiting vertex

}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int vert;
    cout<<"Enter vertex to start with : "<<endl;
    cin>>vert;
    dfs(vert);
    

}
