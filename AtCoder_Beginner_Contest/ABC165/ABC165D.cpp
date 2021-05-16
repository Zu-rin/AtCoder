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
	ll a, b, n, ans;
	//double a, b, n;
	cin >> a >> b >> n;
	ans = (a * n / b) - a * (n / b);
	n = n - (n % b) - 1;
	ans = max(ans, (a * n / b) - a * (n / b));
	cout << ans << "\n";
	return 0;
}