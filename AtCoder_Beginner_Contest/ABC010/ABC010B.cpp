#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, a, ans = 0, d[10] = { 0, 0, 1, 0, 1, 2, 3, 0, 1, 0 };
	cin >> num;
	for (i = 0; i < num; i++) {
		cin >> a;
		ans += d[a];
	}
	cout << ans << "\n";
	return 0;
}