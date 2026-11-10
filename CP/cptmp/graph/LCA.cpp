#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, LG = 18;

vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N];


// এই ফাংশনটির কাজ হলো ট্রির নোডগুলোর ডেপথ, সাবট্রি সাইজ এবং বাইনারি লিফটিং টেবিল (par[u][i]) প্রাক-প্রসেস করে তৈরি করে রাখা।
void dfs(int u, int p = 0)
{
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1]; //binary lifting 2^3-->4+4
  for (auto v: g[u]) if (v != p) {
    dfs(v, u);
    sz[u] += sz[v];
  }
}

// এই ফাংশনটির কাজ হলো নোড u এবং v-এর সর্বনিম্ন সাধারণ পূর্বপুরুষ (Lowest Common Ancestor) বের করা।
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
  if (u == v) return u;
  for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
  return par[u][0];
}




//এই ফাংশনটির কাজ হলো নোড u থেকে ঠিক k ধাপ উপরে (তার Ancestors-এর দিকে) গেলে কোন নোডটি পাওয়া যাবে, তা দ্রুত বের করা।
int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
  return u;
}



//এই ফাংশনটি গাছের যেকোনো দুটি নোড u এবং v-এর মধ্যকার সর্বনিম্ন দূরত্ব (Path-এ মোট কতটি এজ বা লাইন আছে) হিসাব করে।  

int dist(int u, int v) {
  int l = lca(u, v);
  return dep[u] + dep[v] - (dep[l] << 1);
}


//kth node from u to v, 0th node is u
int go(int u, int v, int k) {
  int l = lca(u, v);
  
  
  int d = dep[u] + dep[v] - (dep[l] << 1);
  assert(k <= d);
  if (dep[l] + k <= dep[u]) return kth(u, k);
  k -= dep[u] - dep[l];
  return kth(v, dep[v] - dep[l] - k);
}
int32_t main() {
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  int q; cin >> q;
  while (q--) {
    int u, v; cin >> u >> v;
    cout << dist(u, v) << '\n';
  }
  return 0;
}
