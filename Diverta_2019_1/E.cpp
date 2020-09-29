#include <iostream>
#include <vector>
#define MOD 1000000009

using namespace std;
typedef long long ll;
int num;

ll Search(const vector<ll> &d, int n, ll k) {
	if (n == num)
		return 1;
	ll xx = 0, sum = 0;
	for (int i = n; i < num; i++) {
		xx ^= d[i];
		if (k == xx) {
			sum += Search(d, i + 1, k);
			sum %= MOD;
		}
	}
	return sum;
}

int main(void) {
	int i = 0;
	ll xx = 0, ans = 0;
	cin >> num;
	vector<ll> d(num);
	for (; i < num; i++)
		scanf_s("%ld", &d[i]);
	for (i = 0; i < num; i++) {
		xx ^= d[i];
		ans += Search(d, i + 1, xx);
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}