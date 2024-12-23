#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    public: 
    int V;
    vector<vector<int>> adj;

    Graph(int V){
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int s){
        vector<bool> visited(V, false);

        queue<int> q;

        visited[s] = true;
        q.push(s);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            cout << node << " ";

            for(int neighbor : adj[node]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "BFS travesal starting from node 0: ";
    g.BFS(0);

    return 0;
}