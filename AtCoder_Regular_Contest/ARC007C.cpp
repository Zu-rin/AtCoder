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

int Judge(int v, int s, int num) {
	int a = 0, k = 0, ans = 0;
	while (v > 0) {
		if (v & 1) {
			a |= s >> k;
			ans++;
		}
		k++;
		v >>= 1;
	}
	rep(k, num + 1) {
		if (!(a & (1 << k)))
			return INF;
	}
	return ans;
}

int main(void) {
	int n, i, t = 0, ans = INF;
	string s;
	cin >> s;
	rep(i, s.size()) {
		t <<= 1;
		if (s[i] == 'o')
			t += 1;
	}
	t += t << s.size();
	rep(i, 1 << s.size())
		chmin(ans, Judge(i, t, s.size()));
	cout << ans << "\n";
	return 0;
}