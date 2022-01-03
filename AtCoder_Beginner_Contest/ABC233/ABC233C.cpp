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

int main(void) {
	int num, m, i, j;
	ll x, a;
	cin >> num >> x;
	vector<map<ll, ll>> mp(num + 1);
	mp[0][x] = 1;
	rep(i, num) {
		cin >> m;
		rep(j, m) {
			cin >> a;
			for (auto& p : mp[i]) {
				if (p.first % a == 0)
					mp[i + 1][p.first / a] += p.second;
			}
		}
	}
	cout << mp[num][1] << "\n";
	return 0;
}