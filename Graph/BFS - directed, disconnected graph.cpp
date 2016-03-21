/* Author: Aastha Agrawal
 * Graph (Directed, disconnected)- BFS
 */
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    public:
        Graph(int V);
        void addEdge(int u,int v);
        void BFS();
};

Graph::Graph(int V){
    this->V=V;
    adj= new list<int> [V];
}

void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
}

void Graph::BFS(){
    int i,s;
    bool *visited=new bool[V];
    for(i=0;i<V;i++){
        visited[i]=false;
    }
    
    queue<int> q;
    list<int>::iterator it;
    for(i=0;i<V;i++){
        if(visited[i]==false){
            q.push(i);
            visited[i]=true;
            while(q.empty()==false){
                s=q.front();
                q.pop();
                cout<<s<<" ";
                for(it=adj[s].begin();it!=adj[s].end();it++)
                {
                    if(visited[*it]==false)
                    {
                        q.push(*it);
                        visited[*it]=true;
                    }
                }
            }
        }
    }
    
}

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(4,6);
    
    g.BFS();
	return 0;
}
