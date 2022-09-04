#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

unordered_map<string, int> place2int;

int N, M, Q, cnt_comps, comp[maxn];

vector<int> adj[maxn];

void dfs(int v){
    if(comp[v] > 0) return;
    comp[v] = cnt_comps;

    for(int u: adj[v]) dfs(u);
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
    }

    for(int i = 0; i < N; i++){
        if(comp[i] == 0){
            cnt_comps++;
            dfs(i);
        }
    }

    for(int i = 0; i < Q; i++){
        string a, b;
        cin >> a >> b;
        if(!place2int.count(a)) place2int[a] = cnt++;
        if(!place2int.count(b)) place2int[b] = cnt++;

        cout << (comp[place2int[a]] == comp[place2int[b]] ? "YES" : "NO") << "\n";
    }

    return 0;
}