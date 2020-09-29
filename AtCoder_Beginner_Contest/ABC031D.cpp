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

int Judge(int n, vector<int> &d) {
	int i, buf = n;
	rep(i, d.size()) {
		d[i] = n % 3 + 1;
		n /= 3;
	}
	return 1;
}

int Solve(vector<string>& d, vector<string>& s, vector<int>& l) {
	int i, k;
	vector<string> ans(l.size(), "");
	rep(i, d.size()) {
		k = 0;
		for(auto c = d[i].begin(); c != d[i].end(); c++) {
			if (s[i].size() < k + l[*c - '1'])
				return 0;
			string& a = ans[*c - '1'];
			if (a == "") {
				a = s[i].substr(k, l[*c - '1']);
			}
			else {
				if (a != s[i].substr(k, l[*c - '1']))
					return 0;
			}
			k += l[*c - '1'];
		}
		if (k != s[i].size())
			return 0;
	}
	rep(i, ans.size())
		cout << ans[i] << "\n";
	return 1;
}

int main(void) {
	int num, i, k, lim = 1;
	cin >> k >> num;
	vector<int> l(k);
	vector<string> d(num), s(num);
	rep(i, num)
		cin >> d[i] >> s[i];
	rep(i, k)
		lim *= 3;
	rep(i, lim) {
		Judge(i, l);
		if (Solve(d, s, l)) {
			break;
		}
	}
	return 0;
}