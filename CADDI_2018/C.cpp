#include <iostream>
#include <vector>
#include <algorithm>
#define N 1000000

using namespace std;
typedef long long ll;

int main(void) {
	ll i, j, num, k, ans, a = 0;
	cin >> num >> k;
	if (num == 1)
		ans = k;
	else {
		while (!(k & 1)) {
			a++;
			k >>= 1;
		}
		ans = max(1ll, 1ll << (a / num));
		for (i = 3; i < min((ll)N, k); i += 2) {
			a = 0;
			while (k % i == 0) {
				a++;
				k /= i;
			}
			for(j = 0; j < a / num; j++)
				ans *= i;
			if (k == 1)
				break;
		}
	}
	cout << ans << "\n";
	return 0;
}