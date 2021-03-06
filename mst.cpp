#include<bits/stdc++.h>

using namespace std;

vector<int>d,parent,mark;
vector< pair<int,int> >edges;
map< pair<int,int> ,int>weight;
vector< vector< pair<int,int> > >graph;

void prim(int s,int n){
    set< pair<int,int> >st;
    pair<int,int>p;
    int u;
    d[s]=0;
    for(int i=1;i<=n;i++)
    st.insert(make_pair(d[i],i));
    while(!st.empty()){
        u=st.begin()->second;
        mark[u]=true;
        st.erase(st.begin());
        for(int i=0;i<graph[u].size();i++){
            p=graph[u][i];
            if(p.second<d[p.first] && mark[p.first]==false){
                st.erase(make_pair(d[p.first],p.first));
                d[p.first]=p.second;
                parent[p.first]=u;
                st.insert(make_pair(d[p.first],p.first));
            }
        }
    }
}

bool cmp(pair<int,int>a,pair<int,int>b){
    if(weight[a]<weight[b])return true;
    else return false;
}

int findset(int s){
    if(parent[s]==s)return s;
    parent[s]=findset(parent[s]);
    return parent[s];
}

void unionset(int x,int y){
    int a,b;
    a=findset(x);
    b=findset(y);
    parent[a]=b;
}

int krushal(int n,int m){
    sort(edges.begin(),edges.end(),cmp);
    int i,u,v,w;
    int c=0,ans=0;
    for(i=0;i<m;i++){
        u=edges[i].first;
        v=edges[i].second;
        w=weight[edges[i]];
        if(findset(u)!=findset(v)){
            unionset(u,v);
            ans+=w;
            c++;
        }
        if(c==n-1)break;
    }
    return ans;
}

int main()
{
    int n,m,u,v,w,i,t,j,a,b;
    cout<<"Enter the no of vertices..";
    cin>>n;

    graph.resize(n+1);
    d.resize(n+1);
    mark.resize(n+1);
    parent.resize(n+1);

    cout<<"\nEnter the number of edges...";
    cin>>m;
    cout<<"\nEnter the edges along with their weights...\n";
    for(i=1;i<=m;i++){
        cin>>u>>v>>w;
        edges.push_back(make_pair(u,v));
        weight[make_pair(u,v)]=w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }

    // Calculating the MST Using Prim's Algorithm...
    fill_n(d.begin(),n+1,INT_MAX);
    fill_n(parent.begin(),n+1,0);
    fill_n(mark.begin(),n+1,false);
    prim(1,n);
    int ans=0;
    for(i=1;i<=n;i++){
        ans+=d[i];
    }
    cout<<"\nThe MST of the graph (Using Prim's) is..."<<ans<<endl;

    // Calculating the MSt Using Krushal's Algorithm...
    fill_n(d.begin(),n+1,INT_MAX);
    for(i=1;i<=n;i++){
        parent[i]=i;
    }
    fill_n(mark.begin(),n+1,false);
    ans=krushal(n,m);
    cout<<"\nThe MST of the graph (Using Krushal's) is..."<<ans<<endl;

    return 0;
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              