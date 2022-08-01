#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
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
	ll ans = 0, k = 0;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	rep(i, num) {
		if (d[i] == i + 1)
			k++;
		else if (d[d[i] - 1] == i + 1)
			ans++;
	}
	ans >>= 1;
	ans += k * (k - 1) / 2;
	cout << ans << "\n";
	return 0;
}