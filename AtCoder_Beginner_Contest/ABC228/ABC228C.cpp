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

int border(int k, vector<int> d) {
	sort(d.begin(), d.end(), greater<int>());
	return d[k - 1];
}

int main(void) {
	int num, k, i, j, x;
	cin >> num >> k;
	vector<int> d(num, 0);
	rep(i, num) {
		rep(j, 3) {
			cin >> x;
			d[i] += x;
		}
	}
	x = border(k, d);
	rep(i, num) {
		if (d[i] + 300 >= x)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}