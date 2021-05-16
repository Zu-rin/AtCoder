#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int num, k, i, n;
	ll ans = 1e20;
	cin >> num >> k;
	vector<pair<int, int>> d(num);
	vector<ll> x(num), y(num);
	for (i = 0; i < num; i++) {
		scanf_s("%d%d", &d[i].first, &d[i].second);
		x[i] = d[i].first;
		y[i] = d[i].second;
	}
	sort(d.begin(), d.end());
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for (int xl = 0; xl < num; xl++) {
		for (int xr = xl + k - 1; xr < num; xr++) {
			for (int yl = 0; yl < num; yl++) {
				for (int yr = yl + k - 1; yr < num; yr++) {
					n = 0;
					for (i = xl; i <= xr; i++) {
						if (d[i].second >= y[yl] && d[i].second <= y[yr])
							n++;
					}
					if (n >= k)
						ans = min(ans, (x[xr] - x[xl]) * (y[yr] - y[yl]));
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}