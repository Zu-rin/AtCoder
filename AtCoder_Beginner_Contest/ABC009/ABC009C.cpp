// ‚Þ‚¸‚¢
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

int Judge(string & s, string & t, int k) {
	int i;
	rep(i, s.size()) {
		if (s[i] != t[i])
			k--;
		if (k < 0)
			return 0;
	}
	return 1;
}

int main(void) {
	int num, i, j, k;
	string s, t;
	cin >> num >> k >> s;
	t = s;
	rep(i, s.size()) {
		int a = i;
		for (j = i + 1; j < s.size(); j++) {
			if (s[a] > s[j]) {
				swap(s[i], s[j]);
				if (Judge(s, t, k))
					a = j;
				swap(s[i], s[j]);
			}
		}
		swap(s[i], s[a]);
	}
	cout << s << "\n";
	return 0;
}