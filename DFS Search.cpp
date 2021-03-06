#include<bits/stdc++.h>

using namespace std;

vector< vector<int> >graph;
vector<int>vertices;
vector<bool>vis;

void dfsvisit(int s){
    vis[s]=true;
    cout<<s<<" ";
    for(int i=0;i<graph[s].size();i++){
        if(!vis[graph[s][i]]){
            dfsvisit(graph[s][i]);
        }
    }
}

void dfsvisit2(int s){
    stack<int>sk;
    int t;
    sk.push(s);
    while(!sk.empty()){
        t=sk.top();
        sk.pop();
        if(vis[t])continue;
        vis[t]=true;
        cout<<t<<" ";
        for(int i=0;i<graph[t].size();i++){
            if(!vis[graph[t][i]]){
                sk.push(graph[t][i]);
            }
        }
    }
}

int main()
{
    int n,i,t,j,a;
    cout<<"Enter the no of vertices..";
    cin>>n;
    cout<<"\nEnter the vertices..";
    vertices.resize(n+1);
    vis.resize(n+1);
    graph.resize(n+1);
    for(i=1;i<=n;i++){
        cin>>vertices[i];
    }
    for(i=1;i<=n;i++){
        cout<<"\nEnter the no of adjacent vertexes to the vertex "<<vertices[i]<<endl;
        cin>>t;
        cout<<"\nEnter the vertices..";
        for(j=1;j<=t;j++){
            cin>>a;
            graph[vertices[i]].push_back(a);
        }
    }
    // Doing DFS Search...( Implicitly )
    fill_n(vis.begin(),n+1,false);
    cout<<"\nThe DFS Traversal done implicitly is ... ";
    for(i=1;i<=n;i++){
        if(!vis[vertices[i]]){
            dfsvisit(vertices[i]);
        }
    }
    // Doing DFS Search...( Explicitly )
    fill_n(vis.begin(),n+1,false);
    cout<<"\nThe DFS Traversal done explicitly is ...";
    for(i=1;i<=n;i++){
        if(!vis[vertices[i]]){
            dfsvisit2(vertices[i]);
        }
    }
    return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           