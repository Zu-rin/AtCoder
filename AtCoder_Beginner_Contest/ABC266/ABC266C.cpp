#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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
	int num, i, ok = true;
	vector<int> x(4), y(4);
	rep(i, 4)
		cin >> x[i] >> y[i];
	rep(i, 4) {
		int ax, ay, bx, by;
		ax = x[(i + 1) % 4] - x[i];
		ay = y[(i + 1) % 4] - y[i];
		bx = x[(i + 3) % 4] - x[i];
		by = y[(i + 3) % 4] - y[i];
		if (ax * by - ay * bx <= 0) {
			ok = false;
			break;
		}
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}