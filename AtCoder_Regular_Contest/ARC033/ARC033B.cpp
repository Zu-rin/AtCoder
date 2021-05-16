#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int n, m, i, a;
	map<int, int> mp;
	cin >> n >> m;
	double x = 0.0, y = (double)(n + m);
	for (i = 0; i < n; i++) {
		cin >> a;
		mp[a] = 1;
	}
	for (i = 0; i < m; i++) {
		cin >> a;
		if (mp[a])
			x += 1.0;
	}
	y -= x;
	printf("%.10lf\n", x / y);
	return 0;
}