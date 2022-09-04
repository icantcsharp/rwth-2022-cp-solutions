#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

unordered_map<string, int> place2int;

int N, M, Q, cnt_comps, comp[maxn];
int target;

bool vis[maxn];
vector<int> vis_array;

vector<int> adj[maxn];

bool dfs(int v){
    if(v == target) return 1;
    if(vis[v]) return 0;
    vis[v] = 1;
    vis_array.push_back(v);

    for(int u: adj[v]) if(dfs(u)) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> Q;

    int cnt = 0;
    for(int i = 0; i < M; i++){
        string a, b;
        cin >> a >> b;

        if(!place2int.count(a)) place2int[a] = cnt++;
        if(!place2int.count(b)) place2int[b] = cnt++;

        int a2 = place2int[a];
        int b2 = place2int[b];

        adj[a2].push_back(b2);
        adj[b2].push_back(a2);
    }

    for(int i = 0; i < Q; i++){
        string a, b;
        cin >> a >> b;
        if(!place2int.count(a)) place2int[a] = cnt++;
        if(!place2int.count(b)) place2int[b] = cnt++;

        target = place2int[a];

        cout << (dfs(place2int[b]) ? "YES" : "NO") << "\n";

        for(int j: vis_array) vis[j] = 0;
        vis_array = {};
    }

    return 0;
}