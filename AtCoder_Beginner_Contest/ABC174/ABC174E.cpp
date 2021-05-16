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

int Search(vector<double> & d, const int k, double l, double r) {
	if (ceil(l) == ceil(r))
		return ceil(l);
	int i, a = 0;
	double p = (l + r) / 2.0;
	rep(i, d.size()) {
		a += ceil(d[i] / p) - 1;
	}
	if (a <= k)
		return Search(d, k, l, p);
	else
		return Search(d, k, p, r);
}

int main(void) {
	int num, i, k;
	cin >> num >> k;
	vector<double> d(num);
	rep(i, num)
		cin >> d[i];
	cout << Search(d, k, 0.0, 1e10) << "\n";
	return 0;
}