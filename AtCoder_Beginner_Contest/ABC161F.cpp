#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
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

void Fact(ll n, map<ll, int> &mp) {
    while (!(n & 1)) {
        mp[2]++;
        n >>= 1;
    }
    for (ll i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 1)
        mp[n]++;
    return;
}

ll Pat(ll n, map<ll, int> &mp) {
    Fact(n, mp);
    ll ans = 1;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans *= (ll)((*it).second + 1);
    }
    return ans;
}

int main(void) {
	ll num, i, ans, ok = true, k = 1;
    map<ll, int> a, b;
	cin >> num;
    ans = Pat(num - 1, b) + 1;
    Fact(num, a);
    for (auto s = a.begin(), it = s; it != a.end(); it++) {
        if ((*s).second == 1 || (*s).second != (*it).second) {
            ok = false;
            break;
        }
    }
    if (ok) {
        for (auto it = a.begin(); it != a.end(); it++) {
            k *= (ll)(*it).first;
        }
        if ((num - 1) % k != 0)
            ans++;
    }
    cout << ans << "\n";
	return 0;
}