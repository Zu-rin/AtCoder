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
	int num, i, q, k = -1, t, a, b;
	cin >> num >> q;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	rep(i, q) {
		cin >> t >> a >> b;
		a = (a + k) % num;
		if (t == 1) {
			b = (b + k) % num;
			swap(d[a], d[b]);
		}
		else if (t == 2) {
			k--;
			if (k < 0)
				k += num;
		}
		else {
			cout << d[a] << "\n";
		}
	}
	return 0;
}