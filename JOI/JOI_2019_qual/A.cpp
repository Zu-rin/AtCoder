#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, ans, a, b, c;
	cin >> a >> b >> c;
	ans = c / (7 * a + b);
	ans *= 7;
	c %= 7 * a + b;
	ans += min(c / a + min(1, c % a), 7);
	cout << ans << "\n";
	return 0;
}