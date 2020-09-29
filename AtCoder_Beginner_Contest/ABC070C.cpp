#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	if (a < b)
		return gcd(a, b % a);
	else
		return gcd(b, a % b);
}

int main(void) {
	int num, i = 1;
	ll t1, t2;
	cin >> num >> t1;
	for (; i < num; i++) {
		cin >> t2;
		t1 *= t2 / gcd(t1, t2);
	}
	cout << t1 << "\n";
	return 0;
}