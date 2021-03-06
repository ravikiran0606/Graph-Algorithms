#include<bits/stdc++.h>

using namespace std;

vector<int>vertices,d;
vector< vector< pair<int,int> > >graph;
vector<bool>mark;

void dijkstra1(int s){          // O(n^2) implementation..
    int dis,u,i;
    pair<int,int>p;
    d[s]=0;
    while(1){
        dis=INT_MAX;
        u=-1;
        for(i=1;i<vertices.size();i++){
            if(!mark[vertices[i]] && d[vertices[i]]<dis){
                dis=d[vertices[i]];
                u=i;
            }
        }
        if(u==-1)break;
        mark[u]=true;
        for(i=0;i<graph[u].size();i++){
            p=graph[u][i];
            if(d[u]+p.second<d[p.first]){
                d[p.first]=d[u]+p.second;
            }
        }
    }
}

void dijkstra2(int s,int n){          // O(n logn) implementation..
    int u,i;
    d[s]=0;
    pair<int,int>p;
    set< pair<int,int> >st;
    for(int i=1;i<=n;i++)
    st.insert(make_pair(d[i],i));
    while(!st.empty()){
        u=st.begin()->second;
        mark[u]=true;
        st.erase(st.begin());
        for(i=0;i<graph[u].size();i++){
            p=graph[u][i];
            if(d[u]+p.second<d[p.first] && mark[p.first]==false){
                st.erase(make_pair(d[p.first],p.first));
                d[p.first]=d[u]+p.second;
                st.insert(make_pair(d[p.first],p.first));
            }
        }
    }
}

int main()
{
    int n,i,t,j,a,b;
    cout<<"Enter the no of vertices..";
    cin>>n;
    vertices.resize(n+1);
    mark.resize(n+1);
    graph.resize(n+1);
    d.resize(n+1);
    cout<<"\nEnter the vertices..";
    for(i=1;i<=n;i++){
        cin>>vertices[i];
    }
    for(i=1;i<=n;i++){
        cout<<"\nEnter the no of adjacent vertexes to the vertex "<<vertices[i]<<endl;
        cin>>t;
        cout<<"\nEnter the vertices and the corresponding edge weights..";
        for(j=1;j<=t;j++){
            cin>>a>>b;
            graph[vertices[i]].push_back(make_pair(a,b));
        }
    }


    // Calculating the single source shortest paths...
    fill_n(mark.begin(),n+1,false);
    fill_n(d.begin(),n+1,INT_MAX);
    dijkstra1(vertices[1]);
    cout<<"\nThe shortest paths are as follows.. ( O(n^2) implementation )..";
    for(i=1;i<vertices.size();i++){
        cout<<vertices[i]<<" "<<d[vertices[i]]<<endl;
    }


    // Calculating the single source shortest paths...
    fill_n(mark.begin(),n+1,false);
    fill_n(d.begin(),n+1,INT_MAX);
    dijkstra2(vertices[1],n);
    cout<<"\nThe shortest paths are as follows.. ( O(n logn) implementation )..";
    for(i=1;i<vertices.size();i++){
        cout<<vertices[i]<<" "<<d[vertices[i]]<<endl;
    }
    return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      