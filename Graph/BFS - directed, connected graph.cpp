/* Author: Aastha Agrawal
 * Graph (Directed, connected) - BFS
 */

#include<bits/stdc++.h>
using namespace std;

//Graph class
class Graph{
    int V;
    list<int> *adj;
    public:
        Graph(int V);
        void addEdge(int u,int v);
        void BFS(int s);
};

Graph::Graph(int V){
    this->V=V;
    adj= new list<int> [V];
}

void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
}

void Graph::BFS(int s){
    bool *visited=new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    
    queue<int> q;
    q.push(s);
    visited[s]=true;
    list<int>::iterator it;
    
    while(q.empty()==false){
        s=q.front();
        q.pop();
        cout<<s<<" ";
        for(it=adj[s].begin();it!=adj[s].end();it++){
            if(visited[*it]==false){
                q.push(*it);
                visited[*it]=true;
            }
        }
    }
    
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.BFS(2);
	return 0;
}
