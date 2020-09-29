#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, ans;
	double n, a;
	cin >> n;
	a = n;
	a /= 1.08;
	ans = (int)a;
	if (a - ans > 0.0) {
		ans++;
	}
	if (ans * 108 / 100 == n)
		cout << ans << "\n";
	else
		printf(":(\n");
	return 0;
}