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

int Judge(pp & a, pp & b) {
	int x, y;
	y = a.first / b.second;
	x = b.first / a.second;
	if (a.first % b.second)
		y++;
	if (b.first % a.second)
		x++;
	return y - x;
}

int main(void) {
	int num, i, ans = 0, db = 0;
	cin >> num;
	vector<pp> d(num);
	rep(i, num)
		cin >> d[i].first >> d[i].second;
	rep(i, num) {
		if (Judge(d[ans], d[i]) < 0)
			ans = i;
	}
	rep(i, num) {
		if (ans == i)
			continue;
		if (Judge(d[ans], d[i]) <= 0) {
			db = 1;
			break;
		}
	}
	if (db)
		printf("-1\n");
	else
		cout << ans + 1 << "\n";
	return 0;
}