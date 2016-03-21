/* Author: Aastha Agrawal
 * Graph (Directed, Connected)- DFS
 */
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void DFSUtil(int v,bool *visited);
    public:
        Graph(int V);
        void addEdge(int u,int v);
        void DFS(int s);
};

Graph::Graph(int V){
    this->V=V;
    adj= new list<int> [V];
}

void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
}

void Graph::DFSUtil(int v,bool *visited){
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator it=adj[v].begin();
    for(;it!=adj[v].end();it++){
        if(visited[*it]==false)
            DFSUtil(*it,visited);
    }
}

void Graph::DFS(int s){
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
        
    DFSUtil(s,visited);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.DFS(2);
	return 0;
}
