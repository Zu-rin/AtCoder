#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, ans = 0, b;
	cin >> num;
	vector<int> a(num), c(num - 1);
	for (i = 0; i < num; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (i = 0; i < num; i++) {
		cin >> b;
		ans += b;
	}
	for (i = 0; i < num - 1; i++)
		cin >> c[i];
	for (i = 0; i < num - 1; i++) {
		if (a[i] + 1 == a[i + 1])
			ans += c[a[i]];
	}
	cout << ans << "\n";
	return 0;
}