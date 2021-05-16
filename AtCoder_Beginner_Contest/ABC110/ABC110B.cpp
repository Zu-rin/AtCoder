#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int n, m, kx, ky, x, i;
	cin >> n >> m >> kx >> ky;
	for (i = 0; i < n; i++) {
		cin >> x;
		kx = max(x, kx);
	}
	for (i = 0; i < m; i++) {
		cin >> x;
		ky = min(x, ky);
	}
	if (kx < ky)
		printf("No War\n");
	else
		printf("War\n");
	return 0;
}