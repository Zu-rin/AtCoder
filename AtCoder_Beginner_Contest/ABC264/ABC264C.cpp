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

int main(void) {
    int num, i, ans = 0;
    string s, a = "atcoder";
    cin >> s;
    rep(i, a.size()) {
        int p = s.find(a[i]);
        ans += p - i;
        s = a.substr(0, i + 1) + s.substr(i, p - i) + s.substr(p + 1);
    }
    cout << ans << "\n";
    return 0;
}