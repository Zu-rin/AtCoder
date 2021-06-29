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
struct seg { 
	int l, r;
};

int main(void) {
	int num, i, j, k, ans = 0;
	cin >> num;
	vector<seg> d(num);
	rep(i, num) {
		cin >> k >> d[i].l >> d[i].r;
		d[i].l <<= 1;
		d[i].r <<= 1;
		if (k >= 3)
			d[i].l++;
		if (!(k & 1))
			d[i].r--;
	}
	rep(i, num) {
		rep(j, i)
			if (max(d[j].l, d[i].l) <= min(d[j].r, d[i].r))
				ans++;
	}
	cout << ans << "\n";
	return 0;
}