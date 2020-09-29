#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main(void) {
	int r, k, kk, R, ans = 0, a = 0, i;
	cin >> r >> k;
	r = r << 1;
	kk = k << 1;
	R = r * r;
	for (i = kk; i < r; i += kk)
		ans += sqrt(R - i * i) / kk;
	/*for (i = k; i < r; i += kk)
		a += (sqrt(R - i * i) - k) / kk;
	ans = max(ans << 2, (a << 2) + 1);*/
	cout << (ans << 2) << "\n";
	return 0;
}