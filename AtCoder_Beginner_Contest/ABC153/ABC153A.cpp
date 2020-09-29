#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int n, a, ans = 0;
	cin >> n >> a;
	ans = n / a;
	n %= a;
	if (n > 0)
		ans++;
	cout << ans << "\n";
	return 0;
}