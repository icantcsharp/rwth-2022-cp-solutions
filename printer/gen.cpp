#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    assert(argc == 6);

    int N = stoi(argv[1]);
    int S = stoi(argv[2]);
    int min_a = stoi(argv[3]);
    int max_a = stoi(argv[4]);
    int seed = stoi(argv[5]);

    srand(seed);

    cout << N << " " << S << "\n";
    for(int i = 0; i < N; i++) {
        cout << min_a + (rand() % (max_a + 1 - min_a)) << ((i != N - 1) ? ' ' : '\n');
    }
    return 0;
}