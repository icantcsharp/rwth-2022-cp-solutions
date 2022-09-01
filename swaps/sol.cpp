#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

int N, a[maxn], bit[maxn + 1];

unordered_map<int, deque<int>> students;

void inc(int i, int x){
    for(; i <= N; i += i & -i) bit[i] += x;
}

int get(int i){
    int res = 0;
    for(; i > 0; i -= i & -i) res += bit[i];
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a[i];
        students[a[i]].push_back(i + 1);
    }

    long long total = 0;
    for(int i = 0; i < N; i++) {
        int b;
        cin >> b;
        int index = students[b].front();
        students[b].pop_front();
        total += index - get(index) - 1;
        inc(index, 1);
    }

    cout << total << "\n";

    return 0;
}