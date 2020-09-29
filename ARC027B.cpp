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

int isnum(char s) {
	return '0' <= s && s <= '9';
}

int main(void) {
	int num, i, j, ng = 0;
	ll ans = 1;
	cin >> num;
	string s, t;
	vector<char> d(30);
	cin >> s >> t;
	rep(i, d.size()) {
		d[i] = 'A' + i;
	}
	rep(j, s.size()) {
		rep(i, s.size()) {
			if (isnum(s[i])) {
				if (isnum(t[i])) {
					if(s[i] != t[i])
						ng = 1;
				}
				else {
					d[t[i] - 'A'] = s[i];
				}
			}
			else {
				if (isnum(t[i])) {
					d[s[i] - 'A'] = t[i];
				}
				else {
					d[max(s[i], t[i]) - 'A'] = min(d[s[i] - 'A'], d[t[i] - 'A']);
				}
			}
		}
		rep(i, s.size()) {
			if(!isnum(s[i]))
				s[i] = d[s[i] - 'A'];
			if (!isnum(t[i]))
				t[i] = d[t[i] - 'A'];
		}
	}
	vector<int> k(30, 1);
	if (!isnum(s[0]))
		k[s[0] - 'A'] = 9;
	rep(i, s.size()) {
		if (!isnum(s[i]) && k[s[i] - 'A'] == 1)
			k[s[i] - 'A'] = 10;
	}
	rep(i, k.size()) {
		ans *= k[i];
	}
	if (ng)
		printf("0\n");
	else
		cout << ans << "\n";
	return 0;
}