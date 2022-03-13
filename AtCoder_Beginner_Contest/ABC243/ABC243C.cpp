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

typedef struct Point_Coordinates {
	int x, y;
} point;

int main(void) {
	int num, i, ok = 0;
	cin >> num;
	vector<point> d(num);
	string s;
	map<int, pp> mp;
	rep(i, num)
		cin >> d[i].x >> d[i].y;
	cin >> s;
	rep(i, num) {
		if (!mp.count(d[i].y))
			mp[d[i].y] = pp(INF, -1);
		if (s[i] == 'R') {
			chmin(mp[d[i].y].first, d[i].x);
		}
		else {
			chmax(mp[d[i].y].second, d[i].x);
		}
	}
	for (auto it : mp) {
		if (it.second.first < it.second.second)
			ok = 1;
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}