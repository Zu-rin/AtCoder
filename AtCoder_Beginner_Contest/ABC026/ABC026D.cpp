#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
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

int k = 0;
double a, b, c;
double Search(double l, double r) {
	if (k == 1000)
		return l;
	k++;
	double p = (l + r) / 2.0, ans;
	ans = a * p + b * sin(c * PI * p);
	if (ans <= 100)
		return Search(p, r);
	else
		return Search(l, p);
}

int main(void) {
	int num, i;
	cin >> a >> b >> c;
	double ans = Search(0.0, 1000.0);
	printf("%.10lf\n", ans);
	return 0;
}