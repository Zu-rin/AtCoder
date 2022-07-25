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

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll culc(ll n, ll k = 1) {
	return n / k * (1 + n / k) / 2 * k;
}

int main(void) {
	ll num, i, a, b;
	cin >> num >> a >> b;
	cout << culc(num) - culc(num, a) - culc(num, b) + culc(num, a * b / gcd(a, b)) << "\n";
	return 0;
}