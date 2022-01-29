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
	int num, i, q, x, k;
	cin >> num >> q;
	map<int, vector<int>> mp;
	rep(i, num) {
		cin >> x;
		mp[x].push_back(i + 1);
	}
	rep(i, q) {
		cin >> x >> k;
		if (mp.count(x) && k <= mp[x].size())
			cout << mp[x][k - 1] << "\n";
		else
			printf("-1\n");
	}
	return 0;
}