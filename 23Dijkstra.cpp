void Dijkstra(Graph &g, int start){
    vector<int> dist(g.V, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});

    while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[node]) continue;

        for(int neighbor : g.adj[node]){
            int new_dist = dist[node] + edge_cost(node, neighbor);
            if(new_dist < dist[neighbor]){
                dist[neighbor] = new_dist;
                pq.push({new_dist, neighbor});
            }
        }
    }
}

int jumSearch(int arr[], int n, int target){
    int step = sqrt(n); // Jum step size
    int prev = 0;

    while(arr[min(step, n) - 1] < target){
        prev = step;
        step += sqrt(n);
        if(prev >= n){
            return -1; // Target not found
        }

        for(int i = prev; i < min(step, n); i++){
            if(arr[i] == target){
                return i; //Target found
            }
        }
        return -1; //Target not found
    }
}

struct Node{
    int id; 
    int g_cost; // Cost from start
    int h_cost; // Heuristic to goal
    int f_cost() const { return g_cost + h_cost;}

    bool operator<(const Node &other) const {
        return f_cost() > other.f_cost();
    }
};

void AStarSearch(Graph &g, int start, int goal){
    priority_queue<Node> pq;
    vector<int> g_costs(g.V, INT_MAX);
    vector<int> came_from(g.V, -1); // To reconstruct the path

    g_costs[start] = 0;
    pq.push({start, 0, heuristic(start, goal)});

    while(!pq.empty()){
        Node current = pq.top();
        pq.pop();

        if(current.id == goal){
            return;
        }

        for(int neighbor : g.adj[current.id]){
            int new_g_cost = g_costs[current.id] + edge_cost(current.id, neighbor);
            if(new_g_cost < g_costs[neighbor]){
                g_costs[neighbor] = new_g_cost;
                pq.push({neighbor, new_g_cost, heuristic(neighbor, goal)});
                came_from[neighbor] = current.id;
            }
        }
    }
}