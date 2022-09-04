#include <bits/stdc++.h>
using namespace std;

using tiii = tuple<int, int, int>;

const int maxn = 1e6;
const int inf = 1e9 + 1;

int N, M;

unordered_map<string, int> place2int;
int dist[maxn];
vector<pair<string, string>> edges;

vector<tiii> adj[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int place_counter = 0;
    for(int i = 0; i < M; i++){
        string a, b;
        int c;
        cin >> a >> b >> c;

        if(!place2int.count(a)){
            place2int[a] = place_counter++;
        }
        if(!place2int.count(b)){
            place2int[b] = place_counter++;
        }
        int a2 = place2int[a];
        int b2 = place2int[b];

        adj[a2].push_back({c, b2, i});
        adj[b2].push_back({c, a2, i});

        edges.push_back({a, b});
    }

    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

    for(int i = 0; i < N; i++) dist[i] = inf;

    dist[0] = 0;
    for(auto p: adj[0]){
        if(get<0>(p) < dist[get<1>(p)]){
            dist[get<1>(p)] = get<0>(p);
            pq.push(p);
        }
    }

    long long total = 0;
    vector<int> chosen;
    while(!pq.empty()){
        int v, d, i;

        tie(d, v, i) = pq.top();
        pq.pop();

        if(d > dist[v]) continue;
        total += dist[v];
        dist[v] = 0;

        chosen.push_back(i);

        for(auto p: adj[v]){
            if(get<0>(p) < dist[get<1>(p)]){
                dist[get<1>(p)] = get<0>(p);
                pq.push(p);
            }
        }
    }

    cout << chosen.size() << "\n";
    cout << total << "\n";
    for(int x: chosen) cout << edges[x].first << " "  << edges[x].second << "\n";
    cout << "\n";

    return 0;
}