#include <iostream>
#include <vector>

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

    void DFS(int s){
        vector<bool> visited(V, false);

        DFSUtil(s, visited);
    }
private:
    void DFSUtil(int node, vector<bool>& visited){
        visited[node] = true;

        cout << node << " ";

        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                DFSUtil(neighbor, visited);
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

    g.DFS(0);

    return 0;
}