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
	int num, k, i;
	map<int, int> mp;
	cin >> num >> k;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	rep(i, k)
		mp[d[i]]++;
	int ans = mp.size();
	rep(i, num - k) {
		mp[d[i + k]]++;
		if (mp[d[i]] == 1)
			mp.erase(d[i]);
		else
			mp[d[i]]--;
		chmax(ans, (int)mp.size());
	}
	cout << ans << "\n";
	return 0;
}