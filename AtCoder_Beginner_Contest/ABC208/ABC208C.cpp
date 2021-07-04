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
	ll k, ans;
	cin >> num >> k;
	vector<int> d(num), a;
	rep(i, num)
		cin >> d[i];
	a = d;
	ans = k / num;
	sort(d.begin(), d.end());
	k = d[k % num];
	rep(i, num)
		cout << (a[i] < k ? ans + 1 : ans) << "\n";
	return 0;
}