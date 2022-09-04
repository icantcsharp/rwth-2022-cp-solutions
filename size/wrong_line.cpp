#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

using ld = long double;

const int maxn = 1e6;

using pdd = pair<ld, ld>;

pdd operator-(const pdd& l, const pdd& r) {
	return pdd(l.fi - r.fi, l.se - r.se);
}

ld cross(const pdd& a, const pdd& b){
    return a.fi * b.se - a.se * b.fi;
}

ld ccw(const pdd& p, const pdd& a, const pdd& b){
    ld cro = cross(a - p, b - p);
    if(cro > 0) return 1;
    if(cro < 0) return -1;
    return 0;
}

ld norm(const pdd& p){
    return sqrt(p.fi * p.fi + p.se * p.se);
}

int N;
pdd points[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) cin >> points[i].fi >> points[i].se;

    int m = min_element(points, points + N) - points;

    swap(points[m], points[0]);

    vector<int> cand;
    for(int i = 1; i < N; i++) cand.push_back(i);

    sort(cand.begin(), cand.end(), [&](int a, int b){
        int d = ccw(points[0], points[a], points[b]);
        if(d > 0) return true;
        if(d < 0) return false;
        return norm(a) > norm(b);
    });

    cand.push_back(0);

    deque<int> hull = {0};

    for(int c: cand){
        while(hull.size() >= 2 && ccw(points[hull[hull.size() - 2]], points[hull.back()], points[c]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(c);
    }

    ld sz = 0;
    ld len = 0;
    for(int i = 0; i < hull.size() - 1; i++){
        len += norm(points[hull[i]] - points[hull[i + 1]]);
        sz += points[hull[i]].fi * points[hull[i + 1]].se - points[hull[i]].se * points[hull[i + 1]].fi;
    }
    sz /= 2;

    cout << setprecision(12) << len << " " << sz << "\n";

    return 0;
}