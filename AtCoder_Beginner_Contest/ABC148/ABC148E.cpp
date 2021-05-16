#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	ll num, ans = 0, x = 5;
	cin >> num;
	if (num & 1ll) {
		printf("0\n");
		return 0;
	}
	num >>= 1;
	while (num >= x) {
		ans += num / x;
		x *= 5;
	}
	cout << ans << "\n";
	return 0;
}