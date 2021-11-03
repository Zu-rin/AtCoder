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

int Judge(int a, int b, int c, vector<ll> &x, vector<ll> &y) {
	if (x[a] == x[b])
		return x[a] != x[c];
	return (y[b] - y[a]) * (x[c] - x[a]) != (y[c] - y[a]) * (x[b] - x[a]);
}

int main(void) {
	int num, i, ans = 0;
	cin >> num;
	vector<ll> x(num), y(num);
	rep(i, num)
		cin >> x[i] >> y[i];
	rep(i, num) {
		for (int j = i + 1; j < num; j++) {
			for (int k = j + 1; k < num; k++) {
				if (Judge(i, j, k, x, y))
					ans++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}