#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int Anum, Bnum, Cnum, i, j, k;
	cin >> Anum >> Bnum >> Cnum >> k;
	vector<ll> a(Anum), b(Bnum), c(Cnum), ab(Anum * Bnum), abc(min(k, Anum * Bnum) * Cnum);
	for (i = 0; i < Anum; i++)
		scanf_s("%lld", &a[i]);
	for (i = 0; i < Bnum; i++)
		scanf_s("%lld", &b[i]);
	for (i = 0; i < Cnum; i++)
		scanf_s("%lld", &c[i]);
	for (i = 0; i < Anum; i++) {
		for (j = 0; j < Bnum; j++) {
			ab[i * Bnum + j] = a[i] + b[j];
		}
	}
	sort(ab.begin(), ab.end(), greater<ll>());
	for (i = 0; i < Cnum; i++) {
		for (j = 0; j < min(k, Anum * Bnum); j++) {
			abc[i + j * Cnum] = c[i] + ab[j];
		}
	}
	sort(abc.begin(), abc.end(), greater<ll>());
	for (i = 0; i < k; i++)
		printf("%lld\n", abc[i]);
	return 0;
}