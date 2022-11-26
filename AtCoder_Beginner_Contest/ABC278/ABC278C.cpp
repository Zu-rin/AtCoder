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
    int num, i, k, q;
    ll a, b, n = -1;
    cin >> num;
    vector<ll> d(num);
    map<int, ll> mp;
    rep(i, num)
        cin >> d[i];
    cin >> q;
    rep(i, q) {
        cin >> k >> a;
        if (k == 1) {
            n = a;
            mp = map<int, ll>();
        }
        else if (k == 2) {
            cin >> b;
            mp[a] += b;
        }
        else {
            cout << (n < 0 ? d[a - 1] + mp[a] : n + mp[a]) << "\n";
        }
    }
    return 0;
}