#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

vector<int> groups[maxn];
int par[maxn];

int find(int i){
    if(i == par[i]) return i;
    return par[i] = find(par[i]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(groups[a].size() > groups[b].size()) swap(a, b);
    for(int x: groups[a]) groups[b].push_back(x);
    groups[a] = {};
    par[a] = b;
}

int random_element(vector<int>& x){
    return x[rand() % x.size()];
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    assert(argc == 6);

    int N = stoi(argv[1]);
    int M = stoi(argv[2]);

    assert(M >= N - 1);

    int min_c = stoi(argv[3]);
    int max_c = stoi(argv[4]);
    int seed = stoi(argv[5]);

    vector<set<int>> unique(N);

    srand(seed);

    for(int i = 0; i < N; i++) {
        groups[i].push_back(i);
        par[i] = i;
    }

    cout << N << " " << M << "\n";
    for(int i = 0; i < N - 1; i++){
        int j = rand() % N;
        int k;
        do{
            k = rand() % N;
        } while(find(k) == find(j));
        unique[j].insert(k);
        unique[k].insert(j);
        merge(j, k);
        cout << j << " " << k << " " << min_c + (rand() % (max_c - min_c + 1)) << "\n";
    }

    for(int i = 0; i < M - (N - 1); i++) {
        int j, k;
        do{
            j = rand() % N;
            k = (j + 1 + rand() % (N - 1)) % N;
        } while(unique[j].count(k));
        unique[j].insert(k);
        unique[k].insert(j);
        cout << j << " " << k << " " << min_c + (rand() % (max_c - min_c + 1)) << "\n";
    }

    return 0;
}