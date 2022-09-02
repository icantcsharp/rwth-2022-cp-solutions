#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    assert(argc == 5);

    int N = stoi(argv[1]);
    int M = stoi(argv[2]);
    int Q = stoi(argv[3]);
    int seed = stoi(argv[4]);

    assert(N > 1);
    assert(M <= 2 * N);

    srand(seed);

    vector<bool> seen(N);

    int cnt = 0;
    cout << N << " " << M << "\n";
    for(int i = 0; i < M; i++) {
        int a, b;
        if(2 * (M - i) - 1 >= N - cnt){
            a = rand() % N;
        } else {
            do{
                a = rand() % N;
            } while(seen[a]);
        }
        if(!seen[a]){
            seen[a] = 1;
            cnt++;
        }
        if(2 * (M - i) - 2 >= N - cnt){
            b = (a + 1 + rand() % (N - 1)) % N;
        } else {
            do{
                b = (a + 1 + rand() % (N - 1)) % N;
            } while(seen[b]);
        }
        if(!seen[b]){
            seen[b] = 1;
            cnt++;
        }
        cout << a << " " << b << "\n";
    }
    cout << Q << "\n";
    for(int i = 0; i < Q; i++){
        int a = rand() % N;
        int b = (a + 1 + rand() % (N - 1)) % N;
        cout << a << " " << b << "\n";
    }

    return 0;
}