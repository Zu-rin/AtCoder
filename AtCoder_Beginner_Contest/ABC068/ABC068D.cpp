#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void) {
	ll k, n, p = 0;
	cin >> k;
	n = k / 50;
	k %= 50;
	vector<ll> a(50);
	for (ll i = 0; i < 50; i++)
		a[i] = i + n;
	while (p < k) {
		for (int i = 0; i < 50; i++)
			a[i]--;
		a[p++] += 51;
	}
	printf("50\n");
	for (int i = 0; i < 50; i++)
		printf("%lld ", a[i]);
	printf("\n");
	return 0;
}