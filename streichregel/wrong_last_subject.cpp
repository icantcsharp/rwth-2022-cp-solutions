#include <bits/stdc++.h>
using namespace std;

int N, C;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> C;

    vector<pair<double, int>> grades(N);

    for(int i = 0; i < N; i++) cin >> grades[i].second;
    for(int i = 0; i < N; i++) cin >> grades[i].first;

    sort(grades.begin(), grades.end());
    reverse(grades.begin(), grades.end());

    double sum_grades = 0;
    long long sum_credits = 0;

    for(int i = 0; i < N; i++){
        if(C >= 0){
            C -= grades[i].second;
            grades[i].second = 0;
        }

        sum_grades += grades[i].first * grades[i].second;
        sum_credits += grades[i].second;
    }

    cout << setprecision(2) << fixed << sum_grades / sum_credits - .005 << "\n";

    return 0;
}