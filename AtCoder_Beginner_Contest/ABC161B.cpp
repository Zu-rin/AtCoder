#include <iostream>
#include <vector>
#include <string>
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
	int num, m, i, sum = 0, ok = true, k;
	cin >> num >> m;
	vector<int> d(num);
	rep(i, num) {
		cin >> d[i];
		sum += d[i];
	}
	sort(d.begin(), d.end(), greater<int>());
	k = sum / (4 * m);
	if (sum % (4 * m) == 0)
		k--;
	if (d[m - 1] <= k)
		ok = false;
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}