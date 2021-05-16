#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int a, num, k, i, ans = 0;
	cin >> num >> k;
	for (i = 0; i < num; i++) {
		cin >> a;
		if (a >= k)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}