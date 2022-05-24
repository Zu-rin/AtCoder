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
	int num, i, x;
	pp ans = pp(-1, 0);
	string s;
	map<string, pp> mp;
	cin >> num;
	rep(i, num) {
		cin >> s >> x;
		if (!mp.count(s))
			mp[s] = pp(x, i);
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		pp score = (*it).second;
		if (score.first > ans.first)
			ans = score;
		else if (score.first == ans.first and score.second < ans.second)
			ans = score;
	}
	cout << ans.second + 1 << "\n";
	return 0;
}