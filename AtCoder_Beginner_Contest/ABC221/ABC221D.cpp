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
	int num, i, a, b, n = 0, pre = 0;
	vector<int> ans(2e5 + 1, 0);
	map<int, int> mp;
	cin >> num;
	rep(i, num) {
		cin >> a >> b;
		mp[a]++;
		mp[a + b]--;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		ans[n] += (*it).first - pre;
		pre = (*it).first;
		n += (*it).second;
	}
	for (i = 1; i < num; i++)
		cout << ans[i] << " ";
	cout << ans[i] << "\n";
	return 0;
}