#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, a = 0;
	ll ans = 0;
	string s;
	cin >> s;
	num = s.size();
	vector<int> d(num + 1, -1);
	rep(i, num) {
		if (s[i] == '<') {
			d[i] = a++;
			d[i + 1] = a;
		}
		else
			a = 0;
	}
	if (s[num - 1] == '>')
		d[num] = 0;
	a = 0;
	for (i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '>')
			chmax(d[i], d[i + 1] + 1);
	}
	rep(i, num + 1)
		ans += d[i];
	cout << ans << "\n";
	return 0;
}