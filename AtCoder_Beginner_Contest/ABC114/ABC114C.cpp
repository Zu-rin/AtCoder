#include <iostream>
#define T true
#define F false

using namespace std;
typedef long long ll;

int ans = 0;

bool Judge(int n, const int N) {
	if (n > N)
		return F;
	int a;
	bool t = F, f = F, s = F;
	while (n > 0) {
		a = n % 10;
		if (a == 3) {
			t = T;
			n /= 10;
			continue;
		}
		if (a == 5) {
			f = T;
			n /= 10;
			continue;
		}
		if (a == 7) {
			s = T;
			n /= 10;
			continue;
		}
		return F;
	}
	if (t && f && s)
		return T;
	return F;
}

void Search(ll n, const int N) {
	n *= 10;
	if (n > N)
		return;
	if (Judge(n + 3, N))
		ans++;
	Search(n + 3, N);
	if (Judge(n + 5, N))
		ans++;
	Search(n + 5, N);
	if (Judge(n + 7, N))
		ans++;
	Search(n + 7, N);
	return;
}

int main(void) {
	ll n;
	scanf_s("%ld", &n);
	Search(3, n);
	Search(5, n);
	Search(7, n);
	printf("%d\n", ans);
	return 0;
}