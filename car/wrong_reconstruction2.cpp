#include <bits/stdc++.h>
using namespace std;

const int sum_p = 1e5;
const int maxn = 1e3;

unordered_map<string, int> place2int;

int N, poss[sum_p / 2 + 1], p[maxn], res[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int s = 0;
    poss[0] = 1;
    for(int i = 0; i < N; i++){
        cin >> p[i];
        s += p[i];
        for(int j = sum_p / 2; j >= p[i]; j--){
            poss[j] |= poss[j - p[i]];
        }
    }

    vector<int> perm(N);
    for(int i = 0; i < N; i ++) perm[i] = i;
    sort(perm.begin(), perm.end(), [&](int a, int b){
        return p[a] > p[b];
    });
    int curr = s / 2;
    while(curr != 0){
        int j = -1;
        for(int k: perm){
            if(!res[k] && curr >= p[k] && poss[curr - p[k]]){
                j = k;
                break;
            }
        }
        if(j == -1) break;
        res[j] = 1;
        curr -= p[j];
    }

    for(int i = 0; i < N; i++) cout << (res[i] ? "YES" : "NO") << "\n";

    return 0;
}