#include <bits/stdc++.h>
using namespace std;

const int sum_p = 1e5;
const int maxn = 1e3;

unordered_map<string, int> place2int;

int N, poss[sum_p / 2 + 1], last[sum_p / 2 + 1], p[maxn], res[maxn];

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
            if(poss[j]) continue;
            if(poss[j - p[i]]) {
                poss[j] = 1;
                last[j] = i;
            }
        }
    }


    int curr = s / 2;
    while(curr != 0){
        res[last[curr]] = 1;
        curr -= p[last[curr]];
    }

    for(int i = 0; i < N; i++) cout << res[i] << "\n";

    return 0;
}