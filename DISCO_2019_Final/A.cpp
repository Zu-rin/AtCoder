#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

double Sum(int a) {
	a++;
	double ans = 0.0;
	while (a >= 2) {
		ans += 1.0 / (double)a;
		a--;
	}
	return ans;
}

int main(void) {
	int n, i, a = 0, k = 0;
	double ans = 0.0;
	string s;
	cin >> n >> s;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == '-') {
			ans += 1.0;
			k = max(a, k);
			ans += Sum(a);
			a = 0;
		}
		else
			a++;
	}
	ans -= 1.0;
	ans += 1.0 / (double)(k + 2);
	printf("%.9lf\n", ans);
	return 0;
}