#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int n, i, j, m, b, s;
	cin >> n >> m;
	vector<pair<int, int>> d(2000001, make_pair(-1, -1));
	vector<int> a(n);
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < m; i++) {
		cin >> b;
		for (j = 0; j < n; j++) {
			s = a[j] + b;
			if (d[s].first != -1) {
				printf("%d %d %d %d\n", d[s].first, d[s].second, j, i);
				return 0;
			}
			d[s] = make_pair(j, i);
		}
		if (i * n > 2000000)
			break;
	}
	printf("-1\n");
	return 0;
}