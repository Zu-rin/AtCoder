#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <stack>
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
	int num, i, j, ok;
	string s, ans;
	stack<char> st;
	cin >> num;
	vector<vector<int>> d(num, vector<int>(26, 0));
	rep(i, num) {
		cin >> s;
		rep(j, s.size())
			d[i][s[j] - 'a']++;
	}
	rep(i, num >> 1) {
		ok = false;
		rep(j, 26) {
			if (d[i][j] && d[num - 1 - i][j]) {
				ans += 'a' + j;
				st.push('a' + j);
				ok = true;
				break;
			}
		}
		if (!ok) {
			printf("-1\n");
			return 0;
		}
	}
	if (num & 1) {
		ok = false;
		rep(i, 26) {
			if (d[num >> 1][i]) {
				ans += 'a' + i;
				ok = true;
				break;
			}
		}
		if (!ok) {
			printf("-1\n");
			return 0;
		}
	}
	cout << ans;
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	printf("\n");
	return 0;
}