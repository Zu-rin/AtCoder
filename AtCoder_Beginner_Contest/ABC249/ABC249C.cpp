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

int k;

int judge(vector<string> &s, int a) {
	int ans = 0, i;
	vector<int> d(27, 0);
	for(i = 0; (1 << i) <= a; i++) {
		if (a & (1 << i)) {
			for (char c : s[i]) {
				d[c - 'a']++;
			}
		}
	}
	rep(i, d.size()) {
		if (d[i] == k)
			ans++;
	}
	return ans;
}

int main(void) {
	int num, i, ans = 0;
	cin >> num >> k;
	vector<string> s(num);
	rep(i, num)
		cin >> s[i];
	rep(i, 1 << num) {
		chmax(ans, judge(s, i));
	}
	cout << ans << "\n";
	return 0;
}