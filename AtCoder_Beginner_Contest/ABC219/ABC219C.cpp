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

string x;

struct Str {
	string s;

	bool operator<(const Str& r) {
		for (int i = 0; i < min(s.size(), r.s.size()); i++) {
			if (x.find(s[i]) < x.find(r.s[i]))
				return true;
			if (x.find(s[i]) > x.find(r.s[i]))
				return false;
		}
		if (s.size() <= r.s.size())
			return true;
		return false;
	}
};

int main(void) {
	int num, i;
	cin >> x >> num;
	vector<Str> d(num);
	rep(i, num)
		cin >> d[i].s;
	sort(d.begin(), d.end());
	rep(i, num)
		cout << d[i].s << "\n";
	return 0;
}