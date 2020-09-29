#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int Sum(int r, int k) {
	int kk, R, ans = 0, a = 0, i;
	kk = k << 1;
	R = r * r;
	if ((r / k) & 1) {
		for (i = k; i < r; i += kk)
			ans += (sqrt(R - i * i) - k) / kk;
		ans = (ans << 2) + 1;
	}
	else {
		for (i = kk; i < r; i += kk)
			ans += sqrt(R - i * i) / kk;
		ans <<= 2;
	}
	return ans;
}

int main(void) {
	int k;
	cin >> k;
	printf("%d %d\n", Sum(200, k), Sum(300, k));
	return 0;
}