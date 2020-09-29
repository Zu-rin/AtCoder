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
	int num, i, k, ans;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	sort(d.begin(), d.end());
	cin >> num;
	rep(i, num) {
		cin >> k;
		k = d.size() - k;
		if (k == d.size())
			ans = d[k - 1] + 1;
		else if (k <= 0)
			ans = 0;
		else if (d[k - 1] == d[k])
			ans = d[k] + 1;
		else
			ans = d[k - 1] + 1;
		if (ans == 1)
			ans = 0;
		cout << ans << "\n";
	}
	return 0;
}