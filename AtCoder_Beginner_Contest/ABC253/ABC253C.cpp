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
	int num, i, q, k, x, c;
	map<int, int> mp;
	cin >> q;
	rep(i, q) {
		cin >> k;
		if (k == 1) {
			cin >> x;
			mp[x]++;
		}
		else if (k == 2) {
			cin >> x >> c;
			if (mp[x] <= c)
				mp.erase(x);
			else
				mp[x] -= c;
		}
		else {
			cout << (*mp.rbegin()).first - (*mp.begin()).first << "\n";
		}
	}
	return 0;
}