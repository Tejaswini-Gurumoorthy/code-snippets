#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
vector <int> vis;

void dfs(int vertex)
{
    //1. After entering the vertex
    cout<<vertex<<" ";
    vis.push_back(1);
    for(int child : graph[vertex])
    {
        cout<<"parent : "<<vertex<<"child : "<<child<<endl;
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
    

}
