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
	int num, i;
	ll sum = 0;
	double ans;
	cin >> num;
	vector<ll> d(num);
	rep(i, num) {
		cin >> d[i];
		sum += d[i];
	}
	ans = sum;
	sort(d.begin(), d.end());
	rep(i, num) {
		chmin(ans, (double)d[i] / 2.0 * num + (double)(sum - (num - i) * d[i]));
		sum -= d[i];
	}
	printf("%.10lf\n", ans / num);
	return 0;
}