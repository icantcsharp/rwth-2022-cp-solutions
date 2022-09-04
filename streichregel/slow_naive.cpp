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

    while(C > 0){
        double highest = 0;
        int j = -1;

        for(int i = 0; i < N; i++){
            if((j == -1 || highest < grades[i].first) && grades[i].second > 0){
                highest = grades[i].first;
                j = i;
            }
        }

        if(C >= grades[j].second){
            C -= grades[j].second;
            grades[j].second = 0;
        } else if(C > 0){
            grades[j].second -= C;
            C = 0;
        }
    }

    double sum_grades = 0;
    long long sum_credits = 0;

    for(int i = 0; i < N; i++){
        sum_grades += grades[i].first * grades[i].second;
        sum_credits += grades[i].second;
    }

    cout << setprecision(2) << fixed << sum_grades / sum_credits - .005 << "\n";

    return 0;
}