#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
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

void Eratos(map<int, int> & mp, vector<int> & p) {
	int i, j;
	if (mp.count(1)) {
		p = vector<int>(1000001, 0);
		p[1] = 1;
		return;
	}
	for(auto it = mp.begin(); it != mp.end(); it++) {
		for (j = (*it).first << 1; j < p.size(); j += (*it).first)
			p[j] = 0;
	}
	return;
}

int main(void) {
	int num, i, a, ans = 0;
	cin >> num;
	vector<int> p(1000001, 1);
	map<int, int> mp;
	rep(i, num) {
		cin >> a;
		mp[a]++;
	}
	Eratos(mp, p);
	for(auto it = mp.begin(); it != mp.end(); it++) {
		if ((*it).second == 1 && p[(*it).first])
			ans++;
	}
	cout << ans << "\n";
	return 0;
}