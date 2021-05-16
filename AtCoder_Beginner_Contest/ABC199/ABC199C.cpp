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
	int num, Q, q, i, t, a, b, f = 0;
	vector<string> x(2);
	string s;
	cin >> num >> s >> Q;
	rep(q, Q) {
		cin >> t >> a >> b;
		if (t == 1) {
			a = (a + f * num - 1) % s.size();
			b = (b + f * num - 1) % s.size();
			swap(s[a], s[b]);
		}
		else {
			f++;
			f %= 2;
		}
	}
	if (f)
		cout << s.substr(num) << s.substr(0, num) << "\n";
	else
		cout << s.substr(0, num) << s.substr(num) << "\n";
	return 0;
}