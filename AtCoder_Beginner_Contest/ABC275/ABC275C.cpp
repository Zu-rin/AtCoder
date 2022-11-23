#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int dist(pp a, pp b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int Judge(vector<pp> &d, vector<int> &x) {
    int i, j;
    vector<int> a;
    rep(i, x.size()) {
        for (j = i + 1; j < x.size(); j++) {
            a.push_back(dist(d[x[i]], d[x[j]]));
        }
    }
    sort(a.begin(), a.end());
    rep(i, 3) {
        if (a[i] != a[i + 1])
            return 0;
    }
    if (a[4] != a[5] or a[0] * 2 != a[5])
        return 0;
    return 1;
}

int main(void) {
    int num, i, j, k, l;
    string s;
    vector<pp> d;
    set<vector<int>> st;
    rep(i, 9) {
        cin >> s;
        rep(j, s.size()) {
            if (s[j] == '#')
                d.push_back(pp(i, j));
        }
    }
    rep(i, d.size()) {
        for (j = i + 1; j < d.size(); j++) {
            for (k = j + 1; k < d.size(); k++) {
                for (l = k + 1; l < d.size(); l++) {
                    vector<int> x = {i, j, k, l};
                    if (Judge(d, x))
                        st.insert(x);
                }
            }
        }
    }
    cout << st.size() << "\n";
    return 0;
}