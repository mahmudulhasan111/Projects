#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
              GRAPH ALGORITHM CONTEST TEMPLATE
===========================================================

INDEX:
    01. BFS
    02. Graph Shortest Path Reconstruction
    03. Multi-Source BFS
    04. DFS
    05. Connected Components
    06. Grid DFS
    07. Grid BFS
    08. Grid Multi-Source BFS
    09. Grid Shortest Path Reconstruction
    10. Cycle Detection - Undirected
    11. Cycle Detection - Directed
    12. Bipartite Check - BFS
    13. Bipartite Check - DFS
    14. Topological Sort - DFS
    15. Topological Sort - Kahn / BFS
    16. Dijkstra
    17. 0-1 BFS
    18. Bellman-Ford
    19. Floyd-Warshall
    20. DSU / Union-Find
    21. Kruskal MST
    22. Prim MST
    23. DAG Shortest Path
    24. SCC - Kosaraju
    25. Bridges
    26. Articulation Points
    27. LCA - Binary Lifting
    28. Tree Diameter
    29. Path Reconstruction
    30. Euler Path / Circuit - Directed
    31. Euler Path / Circuit - Undirected

Graph:
    adj_list          -> Unweighted graph
    weighted_adj_list -> Weighted graph {to, weight}

Notation:
    V = Vertices
    E = Edges
===========================================================
*/

#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

const int N = 2e5 + 5;
const int LOG = 20;
const ll INF = 1e18;

// Graph Variables
vector<vector<int>> adj_list;
vector<vector<pair<int,int>>> weighted_adj_list;

vector<bool> visited;
vector<bool> path_visited;
vector<int> dist;  
vector<int> parent;

// Grid Variables
int n, m; 
vector<vector<bool>> grid_visited;
vector<vector<int>> grid_dist;
vector<vector<pii>> grid_parent;
vector<pair<int,int>> direction = {{-1,0}, {1,0}, {0,-1}, {0,1}};

// Boundary Check Function
bool valid(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return false;
    return true;
}


// ---------------------------------------------------------
// 01. BFS
// TASK: Shortest distance in an unweighted graph.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
void bfs(int source) {
    queue<int> q;

    visited[source] = true;
    dist[source] = 0;
    q.push(source);

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]) {
            if(!visited[child]) {
                visited[child] = true;
                dist[child] = dist[par] + 1;
                parent[child] = par;
                q.push(child);
            } 
        }
    }
}

// ---------------------------------------------------------
// 02. Graph Shortest Path Reconstruction
// TASK: Reconstruct shortest path from source to destination.
// COMPLEXITY: O(V)
// depend on bfs
// ---------------------------------------------------------
vector<int> get_bfs_path(int destination) {
    if (dist[destination] == -1) return {}; // Path doesn't exist

    vector<int> path;
    int curr = destination;

    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());
    return path;
}

// ---------------------------------------------------------
// 03. Multi-Source BFS
// TASK: Shortest distance from the nearest source.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
void bfs_multi_source(vector<int> sources) {
    queue<int> q;

    for(int source : sources) {
        if(!visited[source]) {
            visited[source] = true;
            dist[source] = 0;
            q.push(source);
        }
    }

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]) {
            if(!visited[child]) {
                visited[child] = true;
                dist[child] = dist[par] + 1;
                parent[child] = par;
                q.push(child);
            }
        }
    }
}

// ---------------------------------------------------------
// 04. DFS
// TASK: Traverse all vertices reachable from a starting vertex.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
void dfs(int par) {
    visited[par] = true;

    for(int child : adj_list[par]) {
        if(!visited[child]) {
            dfs(child);
        }
    }
}

// ---------------------------------------------------------
// 05. Connected Components
// TASK: Count connected components in an undirected graph.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
int connected_components(int n) {
    int components = 0;

    visited.assign(n, false);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            components++;
            dfs(i);
        }
    }

    return components;
}

// ---------------------------------------------------------
// 06. Grid DFS
// TASK: Traverse all reachable grid cells using DFS.
// COMPLEXITY: O(R * C)
// ---------------------------------------------------------
void grid_dfs(int r, int c) {
    grid_visited[r][c] = true;

    for (auto [dr, dc] : direction) {
        int nr = r + dr;
        int nc = c + dc;

        if (valid(nr, nc) && !grid_visited[nr][nc]) {
            grid_parent[nr][nc] = {r, c};
            grid_dfs(nr, nc);
        }
    }
}

// ---------------------------------------------------------
// 07. Grid BFS
// TASK: Find shortest 4-directional distance from a grid cell.
// COMPLEXITY: O(R * C)
// ---------------------------------------------------------
void grid_bfs(int sr, int sc) {
    queue<pii> q;

    grid_visited[sr][sc] = true;
    grid_dist[sr][sc] = 0;
    grid_parent[sr][sc] = {-1, -1};
    q.push({sr, sc});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (auto [dr, dc] : direction) {
            int nr = r + dr;
            int nc = c + dc;

            if (valid(nr, nc) && !grid_visited[nr][nc]) {
                grid_visited[nr][nc] = true;
                grid_dist[nr][nc] = grid_dist[r][c] + 1;
                grid_parent[nr][nc] = {r, c};
                q.push({nr, nc});
            }
        }
    }
}

// ---------------------------------------------------------
// 08. Grid Multi-Source BFS
// TASK: Find distance from every cell to the nearest source.
// COMPLEXITY: O(R * C)
// ---------------------------------------------------------
void grid_multi_source_bfs(vector<pii> sources) {
    queue<pii> q;

    for (auto [r, c] : sources) {
        if (valid(r, c) && !grid_visited[r][c]) {
            grid_visited[r][c] = true;
            grid_dist[r][c] = 0;
            grid_parent[r][c] = {-1, -1};
            q.push({r, c});
        }
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (auto [dr, dc] : direction) {
            int nr = r + dr;
            int nc = c + dc;

            if (valid(nr, nc) && !grid_visited[nr][nc]) {
                grid_visited[nr][nc] = true;
                grid_dist[nr][nc] = grid_dist[r][c] + 1;
                grid_parent[nr][nc] = {r, c};
                q.push({nr, nc});
            }
        }
    }
}

// ---------------------------------------------------------
// 09. Grid Shortest Path Reconstruction
// TASK: Reconstruct shortest path from source to destination in a 2D Grid.
// COMPLEXITY: O(R * C)
// ---------------------------------------------------------
vector<pii> get_grid_path(pii destination) {
    auto [r, c] = destination;
    if (grid_dist[r][c] == -1) return {}; // Path doesn't exist

    vector<pii> path;
    pii curr = destination;

    while (curr != make_pair(-1, -1)) {
        path.push_back(curr);
        curr = grid_parent[curr.first][curr.second];
    }

    reverse(path.begin(), path.end());
    return path;
}

// ---------------------------------------------------------
// 10. Cycle Detection - Undirected
// TASK: Detect cycle in an undirected graph using BFS or DFS.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
bool cycle_det_undirect_bfs(int src) {
    queue<int> q;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par]) {
            if (visited[child] && parent[par] != child) {
                return true; // Cycle detected
            }
            if (!visited[child]) {
                visited[child] = true;
                parent[child] = par;
                q.push(child);
            }
        }
    }
    return false;
}

bool cycle_det_undirect_dfs(int par) {
    visited[par] = true;

    for (int child : adj_list[par]) {
        if (visited[child] && parent[par] != child) {
            return true; // Cycle detected
        }
        if (!visited[child]) {
            parent[child] = par;
            if (cycle_det_undirect_dfs(child)) return true;
        }
    }
    return false;
}

// ---------------------------------------------------------
// 11. Cycle Detection - Directed
// TASK: Detect cycle in a directed graph using DFS or BFS (Kahn's).
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
bool cycle_det_direct_dfs(int par) {
    visited[par] = true;
    path_visited[par] = true;

    for (int child : adj_list[par]) {
        if (path_visited[child]) {
            return true;
        }
        if (!visited[child]) {
            if (cycle_det_direct_dfs(child)) return true;
        }
    }

    path_visited[par] = false;
    return false;
}

bool has_cycle_directed_dfs(int n) {
    visited.assign(n, false);
    path_visited.assign(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cycle_det_direct_dfs(i)) {
            return true;
        }
    }
    return false;
}

bool cycle_det_direct_bfs(int n) {
    vector<int> indegree(n, 0);

    for (int u = 0; u < n; u++) {
        for (int v : adj_list[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int par = q.front();
        q.pop();
        count++;

        for (int child : adj_list[par]) {
            if (--indegree[child] == 0) {
                q.push(child);
            }
        }
    }

    return count != n; // Processed nodes != total nodes means Cycle exists
}

vector<int> color;

// ---------------------------------------------------------
// 12. Bipartite Check - BFS
// TASK: Check whether the graph can be colored with 2 colors.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
bool bipartite_bfs(int n) {
    color.assign(n, -1);

    for(int s = 0; s < n; s++) {
        if(color[s] != -1) continue;

        queue<int> q;
        q.push(s);
        color[s] = 0;

        while(!q.empty()) {
            int par = q.front();
            q.pop();

            for(int child : adj_list[par]) {
                if(color[child] == -1) {
                    color[child] = color[par] ^ 1;
                    q.push(child);
                }
                else if(color[child] == color[par]) {
                    return false;
                }
            }
        }
    }

    return true;
}

// ---------------------------------------------------------
// 13. Bipartite Check - DFS
// TASK: Color adjacent vertices with opposite colors.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
bool bipartite_dfs(int par) {
    for(int child : adj_list[par]) {
        if(color[child] == -1) {
            color[child] = color[par] ^ 1;

            if(!bipartite_dfs(child)) return false;
        }
        else if(color[child] == color[par]) {
            return false;
        }
    }

    return true;
}

bool is_bipartite(int n) {
    color.assign(n, -1);

    for(int i = 0; i < n; i++) {
        if(color[i] != -1) continue;

        color[i] = 0;

        if(!bipartite_dfs(i)) return false;
    }

    return true;
}

vector<int> topo_order;

// ---------------------------------------------------------
// 14. Topological Sort - DFS
// TASK: Process vertices in DFS finishing order.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
void dfs_topological(int par) {
    visited[par] = true;

    for(int child : adj_list[par]) {
        if(!visited[child]) {
            dfs_topological(child);
        }
    }

    topo_order.push_back(par);
}

vector<int> topological_sort_dfs(int n) {
    visited.assign(n, false);
    topo_order.clear();

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs_topological(i);
        }
    }

    reverse(topo_order.begin(), topo_order.end());

    return topo_order;
}

// ---------------------------------------------------------
// 15. Topological Sort - Kahn / BFS
// TASK: Topologically sort using indegrees and BFS.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
vector<int> topological_sort_kahn(int n) {
    vector<int> indegree(n, 0);
    vector<int> order;
    queue<int> q;

    for(int u = 0; u < n; u++) {
        for(int v : adj_list[u]) {
            indegree[v]++;
        }
    }

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        order.push_back(par);

        for(int child : adj_list[par]) {
            if(--indegree[child] == 0) {
                q.push(child);
            }
        }
    }

    if((int)order.size() != n) return {};

    return order;
}

// ---------------------------------------------------------
// 16. Dijkstra
// TASK: Shortest paths from one source with non-negative weights.
// COMPLEXITY: O((V + E) log V)
// ---------------------------------------------------------
vector<ll> dijkstra(int source) {
    int n = weighted_adj_list.size();

    vector<ll> distance(n, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d != distance[u]) continue;

        for(auto [v, w] : weighted_adj_list[u]) {
            if(distance[v] > d + w) {
                distance[v] = d + w;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

// ---------------------------------------------------------
// 17. 0-1 BFS
// TASK: Shortest paths when every edge weight is 0 or 1.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
vector<int> zero_one_bfs(int source) {
    int n = weighted_adj_list.size();

    vector<int> distance(n, 1e9);
    deque<int> dq;

    distance[source] = 0;
    dq.push_front(source);

    while(!dq.empty()) {
        int par = dq.front();
        dq.pop_front();

        for(auto [child, w] : weighted_adj_list[par]) {
            if(distance[child] > distance[par] + w) {
                distance[child] = distance[par] + w;

                if(w == 0) dq.push_front(child);
                else dq.push_back(child);
            }
        }
    }

    return distance;
}

struct Edge {
    int u, v, w;
};

// ---------------------------------------------------------
// 18. Bellman-Ford
// TASK: Shortest paths with negative edge weights.
// COMPLEXITY: O(VE)
// ---------------------------------------------------------
vector<ll> bellman_ford(int n, int source, vector<Edge>& edges) {
    vector<ll> distance(n, INF);
    distance[source] = 0;

    for(int i = 1; i < n; i++) {
        bool changed = false;

        for(auto [u, v, w] : edges) {
            if(distance[u] == INF) continue;

            if(distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                changed = true;
            }
        }

        if(!changed) break;
    }

    return distance;
}

// ---------------------------------------------------------
// 19. Floyd-Warshall
// TASK: Find shortest paths between every pair of vertices.
// COMPLEXITY: O(V^3)
// ---------------------------------------------------------
vector<vector<ll>> floyd_warshall(int n) {
    vector<vector<ll>> distance(n, vector<ll>(n, INF));

    for(int i = 0; i < n; i++) {
        distance[i][i] = 0;
    }

    for(int u = 0; u < n; u++) {
        for(auto [v, w] : weighted_adj_list[u]) {
            distance[u][v] = min(distance[u][v], (ll)w);
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            if(distance[i][k] == INF) continue;

            for(int j = 0; j < n; j++) {
                if(distance[k][j] == INF) continue;

                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    return distance;
}

// ---------------------------------------------------------
// 20. DSU / Union-Find
// TASK: Maintain components and support fast merge/connectivity queries.
// COMPLEXITY: O(alpha(V)) amortized
// ---------------------------------------------------------
struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if(parent[u] == u) return u;

        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if(u == v) return false;

        if(sz[u] < sz[v]) swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];

        return true;
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    int size(int u) {
        return sz[find(u)];
    }
};

// ---------------------------------------------------------
// 21. Kruskal MST
// TASK: Find a minimum spanning tree using sorted edges.
// COMPLEXITY: O(E log E)
// ---------------------------------------------------------
ll kruskal(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    ll cost = 0;
    int edges_taken = 0;

    for(auto [u, v, w] : edges) {
        if(!dsu.unite(u, v)) continue;

        cost += w;
        edges_taken++;

        if(edges_taken == n - 1) break;
    }

    if(edges_taken != n - 1) return INF;

    return cost;
}

// ---------------------------------------------------------
// 22. Prim MST
// TASK: Find a minimum spanning tree using a priority queue.
// COMPLEXITY: O(E log V)
// ---------------------------------------------------------
ll prim(int n) {
    vector<int> used(n, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    ll cost = 0;
    int taken = 0;

    pq.push({0, 0});

    while(!pq.empty()) {
        auto [w, par] = pq.top();
        pq.pop();

        if(used[par]) continue;

        used[par] = 1;
        taken++;
        cost += w;

        for(auto [child, wt] : weighted_adj_list[par]) {
            if(!used[child]) {
                pq.push({wt, child});
            }
        }
    }

    if(taken != n) return INF;

    return cost;
}

// ---------------------------------------------------------
// 23. DAG Shortest Path
// TASK: Find shortest paths in a weighted DAG.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
vector<int> dag_shortest_path(int n, int source) {
    vector<int> indegree(n, 0);
    vector<int> order;
    queue<int> q;

    for(int u = 0; u < n; u++) {
        for(auto [v, w] : weighted_adj_list[u]) {
            indegree[v]++;
        }
    }

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        order.push_back(par);

        for(auto [child, w] : weighted_adj_list[par]) {
            if(--indegree[child] == 0) q.push(child);
        }
    }

    vector<int> distance(n, 1e9);
    distance[source] = 0;

    for(int par : order) {
        if(distance[par] == 1e9) continue;

        for(auto [child, w] : weighted_adj_list[par]) {
            distance[child] = min(distance[child], distance[par] + w);
        }
    }

    return distance;
}

vector<vector<int>> reverse_adj_list;

// ---------------------------------------------------------
// 24. SCC - Kosaraju
// TASK: Find all strongly connected components.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
vector<vector<int>> scc_kosaraju(int n) {
    vector<int> order;
    vector<int> used(n, 0);

    function<void(int)> dfs1 = [&](int par) {
        used[par] = 1;

        for(int child : adj_list[par]) {
            if(!used[child]) dfs1(child);
        }

        order.push_back(par);
    };

    for(int i = 0; i < n; i++) {
        if(!used[i]) dfs1(i);
    }

    reverse_adj_list.assign(n, {});

    for(int par = 0; par < n; par++) {
        for(int child : adj_list[par]) {
            reverse_adj_list[child].push_back(par);
        }
    }

    vector<vector<int>> components;
    fill(used.begin(), used.end(), 0);
    reverse(order.begin(), order.end());

    function<void(int, vector<int>&)> dfs2 = [&](int par, vector<int>& component) {
        used[par] = 1;
        component.push_back(par);

        for(int child : reverse_adj_list[par]) {
            if(!used[child]) dfs2(child, component);
        }
    };

    for(int par : order) {
        if(used[par]) continue;

        vector<int> component;
        dfs2(par, component);
        components.push_back(component);
    }

    return components;
}

vector<int> tin, low;
vector<int> bridges;
vector<int> articulation;
int timer;

// ---------------------------------------------------------
// 25. Bridges
// TASK: Find all edges whose removal disconnects the graph.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
void bridge_dfs(int par, int prev) {
    tin[par] = low[par] = timer++;

    for(int child : adj_list[par]) {
        if(child == prev) continue;

        if(tin[child] != -1) {
            low[par] = min(low[par], tin[child]);
        }
        else {
            bridge_dfs(child, par);

            low[par] = min(low[par], low[child]);

            if(low[child] > tin[par]) {
                bridges.push_back(par);
                bridges.push_back(child);
            }
        }
    }
}

vector<pii> find_bridges(int n) {
    tin.assign(n, -1);
    low.assign(n, -1);
    bridges.clear();
    timer = 0;

    for(int i = 0; i < n; i++) {
        if(tin[i] == -1) {
            bridge_dfs(i, -1);
        }
    }

    vector<pii> answer;

    for(int i = 0; i < (int)bridges.size(); i += 2) {
        answer.push_back({bridges[i], bridges[i + 1]});
    }

    return answer;
}

// ---------------------------------------------------------
// 26. Articulation Points
// TASK: Find all vertices whose removal disconnects the graph.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
void articulation_dfs(int par, int prev) {
    tin[par] = low[par] = timer++;

    int children = 0;

    for(int child : adj_list[par]) {
        if(child == prev) continue;

        if(tin[child] != -1) {
            low[par] = min(low[par], tin[child]);
        }
        else {
            articulation_dfs(child, par);

            low[par] = min(low[par], low[child]);

            if(prev != -1 && low[child] >= tin[par]) {
                articulation[par] = 1;
            }

            children++;
        }
    }

    if(prev == -1 && children > 1) {
        articulation[par] = 1;
    }
}

vector<int> articulation_points(int n) {
    tin.assign(n, -1);
    low.assign(n, -1);
    articulation.assign(n, 0);
    timer = 0;

    for(int i = 0; i < n; i++) {
        if(tin[i] == -1) {
            articulation_dfs(i, -1);
        }
    }

    vector<int> answer;

    for(int i = 0; i < n; i++) {
        if(articulation[i]) answer.push_back(i);
    }

    return answer;
}

vector<vector<int>> up;
vector<int> depth;

// ---------------------------------------------------------
// 27. LCA - Binary Lifting
// TASK: Precompute ancestors and find LCA of tree nodes.
// COMPLEXITY: O(V log V) precomputation, O(log V) query
// ---------------------------------------------------------
void lca_dfs(int par, int prev) {
    up[par][0] = prev;

    for(int j = 1; j < LOG; j++) {
        up[par][j] = up[up[par][j - 1]][j - 1];
    }

    for(int child : adj_list[par]) {
        if(child == prev) continue;

        depth[child] = depth[par] + 1;
        lca_dfs(child, par);
    }
}

void build_lca(int n, int root = 0) {
    up.assign(n, vector<int>(LOG));
    depth.assign(n, 0);

    lca_dfs(root, root);
}

int kth_ancestor(int u, int k) {
    for(int j = 0; j < LOG; j++) {
        if(k & (1 << j)) {
            u = up[u][j];
        }
    }

    return u;
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);

    u = kth_ancestor(u, depth[u] - depth[v]);

    if(u == v) return u;

    for(int j = LOG - 1; j >= 0; j--) {
        if(up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

int tree_distance(int u, int v) {
    int w = lca(u, v);

    return depth[u] + depth[v] - 2 * depth[w];
}

// ---------------------------------------------------------
// 28. Tree Diameter
// TASK: Find tree diameter using two BFS runs.
// COMPLEXITY: O(V + E)
// ---------------------------------------------------------
pair<int, int> farthest_node(int source, int n) {
    vector<int> distance(n, -1);
    queue<int> q;

    distance[source] = 0;
    q.push(source);

    int farthest = source;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        if(distance[par] > distance[farthest]) {
            farthest = par;
        }

        for(int child : adj_list[par]) {
            if(distance[child] != -1) continue;

            distance[child] = distance[par] + 1;
            q.push(child);
        }
    }

    return {farthest, distance[farthest]};
}

int tree_diameter(int n) {
    auto [a, x] = farthest_node(0, n);
    auto [b, diameter] = farthest_node(a, n);

    return diameter;
}

// ---------------------------------------------------------
// 29. Path Reconstruction
// TASK: Reconstruct a path using the parent array.
// COMPLEXITY: O(V)
// ---------------------------------------------------------
vector<int> find_path(int destination) {
    if (dist[destination] == -1) {
        return {}; 
    }

    vector<int> path;
    int curr = destination;

    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());
    return path;
}

vector<int> reconstruct_path(int source, int target) {
    if(dist[target] == -1) return {};

    vector<int> path;

    for(int u = target; u != -1; u = parent[u]) {
        path.push_back(u);
    }

    reverse(path.begin(), path.end());

    if(path[0] != source) return {};

    return path;
}

// ---------------------------------------------------------
// 30. Euler Path / Circuit - Directed
// TASK: Find an Euler path or circuit in a directed graph.
// COMPLEXITY: O(E)
// ---------------------------------------------------------
vector<int> euler_directed(int n) {
    vector<int> indegree(n, 0), outdegree(n, 0);

    for(int par = 0; par < n; par++) {
        outdegree[par] = adj_list[par].size();

        for(int child : adj_list[par]) {
            indegree[child]++;
        }
    }

    int start = -1;
    int plus = 0, minus = 0;

    for(int i = 0; i < n; i++) {
        if(outdegree[i] - indegree[i] == 1) {
            plus++;
            start = i;
        }
        else if(indegree[i] - outdegree[i] == 1) {
            minus++;
        }
        else if(indegree[i] != outdegree[i]) {
            return {};
        }
    }

    if(!((plus == 0 && minus == 0) || (plus == 1 && minus == 1))) {
        return {};
    }

    if(start == -1) {
        for(int i = 0; i < n; i++) {
            if(outdegree[i] > 0) {
                start = i;
                break;
            }
        }
    }

    if(start == -1) return {0};

    vector<int> path;

    function<void(int)> dfs = [&](int par) {
        while(!adj_list[par].empty()) {
            int child = adj_list[par].back();
            adj_list[par].pop_back();
            dfs(child);
        }

        path.push_back(par);
    };

    dfs(start);
    reverse(path.begin(), path.end());

    int edges = 0;

    for(int x : outdegree) {
        edges += x;
    }

    if((int)path.size() != edges + 1) return {};

    return path;
}

struct UndirectedEdge {
    int to;
    int id;
};

// ---------------------------------------------------------
// 31. Euler Path / Circuit - Undirected
// TASK: Find an Euler path or circuit in an undirected graph.
// COMPLEXITY: O(E)
// ---------------------------------------------------------
vector<int> euler_undirected(int n, vector<vector<UndirectedEdge>>& adj, int total_edges) {
    vector<int> degree(n, 0);

    for(int i = 0; i < n; i++) {
        degree[i] = adj[i].size();
    }

    int odd = 0;
    int start = -1;

    for(int i = 0; i < n; i++) {
        if(degree[i] % 2) {
            odd++;
            start = i;
        }

        if(degree[i] > 0 && start == -1) {
            start = i;
        }
    }

    if(odd != 0 && odd != 2) return {};
    if(total_edges == 0) return {0};

    vector<int> path;
    vector<bool> used_edge(total_edges, false);

    function<void(int)> dfs = [&](int par) {
        while(!adj[par].empty()) {
            auto [child, id] = adj[par].back();
            adj[par].pop_back();

            if(used_edge[id]) continue;
            used_edge[id] = true;

            dfs(child);
        }

        path.push_back(par);
    };

    dfs(start);
    reverse(path.begin(), path.end());

    if((int)path.size() != total_edges + 1) return {};

    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}

/*
===============================================
DECLARED GLOBALLY:
===============================================
vector<vector<int>> adj_list;
vector<vector<pair<int,int>>> weighted_adj_list;

vector<bool> visited;
vector<bool> path_visited;
vector<int> dist;
vector<int> parent;

int n, m; 
vector<vector<bool>> grid_visited;
vector<vector<int>> grid_dist;
vector<vector<pii>> grid_parent;
vector<pair<int,int>> direction = {{-1,0}, {1,0}, {0,-1}, {0,1}};

IN THE MAIN/SOLVE FUNCTION INITIALIZATION:
====================================================
1. Graph Initialization:
----------------------------------------------------
int n, e;
cin >> n >> e;

adj_list.assign(n, {});
visited.assign(n, false);
path_visited.assign(n, false);
dist.assign(n, -1);
parent.assign(n, -1);

for(int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

2. Grid Initialization:
----------------------------------------------------
cin >> n >> m;
grid_visited.assign(n, vector<bool>(m, false));
grid_dist.assign(n, vector<int>(m, -1));
grid_parent.assign(n, vector<pii>(m, {-1, -1}));
====================================================
*/



/*
===========================================================
GRID DIRECTIONS
===========================================================

4 Directions:
vector<pii> dir_4={{-1,0},{1,0},{0,-1},{0,1}};

8 Directions:
vector<pii> dir_8={
    {-1,-1},{-1,0},{-1,1},
    {0,-1},{0,1},
    {1,-1},{1,0},{1,1}
};

Diagonal:
vector<pii> dir_diagonal={{-1,-1},{-1,1},{1,-1},{1,1}};

Knight:
vector<pii> dir_knight={
    {-2,-1},{-2,1},
    {-1,-2},{-1,2},
    {1,-2},{1,2},
    {2,-1},{2,1}
};

Horizontal:
vector<pii> dir_horizontal={{0,-1},{0,1}};

Vertical:
vector<pii> dir_vertical={{-1,0},{1,0}};

2-Cell Jump:
vector<pii> dir_jump2={{-2,0},{2,0},{0,-2},{0,2}};

2-Cell Diagonal Jump:
vector<pii> dir_diagonal2={{-2,-2},{-2,2},{2,-2},{2,2}};

All Cells within Distance 2:
vector<pii> dir_24={
    {-2,-2},{-2,-1},{-2,0},{-2,1},{-2,2},
    {-1,-2},{-1,-1},{-1,0},{-1,1},{-1,2},
    {0,-2},{0,-1},{0,1},{0,2},
    {1,-2},{1,-1},{1,0},{1,1},{1,2},
    {2,-2},{2,-1},{2,0},{2,1},{2,2}
};

===========================================================
*/
