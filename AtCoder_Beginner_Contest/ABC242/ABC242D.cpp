#include <iostream>
#include <vector>
#include <string>
#include <list>
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
	int num, i;
	ll a, b;
	string s;
	cin >> s >> num;
	rep(i, num) {
		ll k = 0;
		cin >> a >> b;
		b--;
		while (a and b) {
			k += (b & 1) ? -1 : 1;
			b >>= 1;
			a--;
		}
		k = (k + a) % 3;
		if (k < 0)
			k += 3;
		cout << (char)('A' + (s[b] - 'A' + k) % 3) << "\n";
	}
	return 0;
}