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

int main(void) {
	int num, i, b;
	double sum = 0.0, ans = 0.0;
	cin >> num;
	vector<int> a(num);
	vector<double> c(num);
	rep(i, num) {
		cin >> a[i] >> b;
		sum += c[i] = (double)a[i] / b;
	}
	sum /= 2.0;
	rep(i, num) {
		if (sum < c[i]) {
			ans += (double)a[i] * sum / c[i];
			break;
		}
		ans += a[i];
		sum -= c[i];
	}
	printf("%.9lf\n", ans);
	return 0;
}