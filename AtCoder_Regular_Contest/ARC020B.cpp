#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, k, i, j, x, ans = INF;
	vector<int> a(11, 0), b(11, 0);
	cin >> num >> k;
	for (i = 0; i < num; i++) {
		cin >> x;
		if (i & 1)
			a[x]++;
		else
			b[x]++;
	}
	for (i = 1; i <= 10; i++) {
		for (j = 1; j <= 10; j++) {
			if (i == j)
				continue;
			ans = min(ans, num - a[i] - b[j]);
		}
	}
	cout << ans * k << "\n";
	return 0;
}