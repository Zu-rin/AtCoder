#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

typedef struct {
	ll x, y;
} point;

int main(void) {
	int num, i, j, k, ans = 0;
	ll s;
	cin >> num;
	vector<point> d(num);
	for (i = 0; i < num; i++) {
		cin >> d[i].x >> d[i].y;
	}
	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			for (k = j + 1; k < num; k++) {
				s = abs((d[i].x - d[k].x) * (d[j].y - d[k].y) - (d[i].y - d[k].y) * (d[j].x - d[k].x));
				if (s > 0 && !(s & 1))
					ans++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}