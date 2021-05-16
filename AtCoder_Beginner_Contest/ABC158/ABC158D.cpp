#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, t, h = 1;
	string s, c, a = "";
	cin >> s >> num;
	rep(i, num) {
		cin >> t;
		if (t & 1)
			h = !h;
		else {
			cin >> t >> c;
			if (h ^ (t & 1))
				s += c;
			else
				a += c;
		}
	}
	if (h) {
		for (i = a.size() - 1; i >= 0; i--)
			cout << a[i];
		cout << s;
	}
	else {
		for (i = s.size() - 1; i >= 0; i--)
			cout << s[i];
		cout << a;
	}
	cout << "\n";
	return 0;
}