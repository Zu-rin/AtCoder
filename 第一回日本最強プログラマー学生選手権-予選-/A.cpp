#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int i, j, m, d, ans = 0;
	cin >> m >> d;
	for (i = 1; i <= m; i++) {
		for (j = 20; j <= d; j++) {
			if (i == (j / 10) * (j % 10) && (j % 10) > 1)
				ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}