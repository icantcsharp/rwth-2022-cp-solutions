#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    assert(argc == 9);

    int N = stoi(argv[1]);
    int C = stoi(argv[2]);
    long long min_credits = stoll(argv[3]);
    long long max_credits = stoll(argv[4]);
    long long total_credits = stoll(argv[5]);
    int min_grades = stoi(argv[6]);
    int max_grades = stoi(argv[7]);
    int seed = stoi(argv[8]);

    srand(seed);

    assert(min_credits * N <= total_credits);
    assert(max_credits * N >= total_credits);

    cout << N << " " << C << "\n";
    for(int i = 0; i < N; i++) {
        long long lower = max(total_credits - (N - i - 1) * max_credits, min_credits);
        long long upper = min(total_credits - (N - i - 1) * min_credits, max_credits);
        long long credits = lower + (rand() % (upper + 1 - lower));
        total_credits -= credits;
        cout << credits << " ";
        cout << min_grades + (rand() % (max_grades + 1 - min_grades)) << '\n';
    }

    return 0;
}