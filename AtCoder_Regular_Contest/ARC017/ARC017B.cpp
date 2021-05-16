#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, k, ans = 0, a;
	cin >> num >> k;
	vector<int> d(num);
	for (i = 0; i < num; i++) {
		cin >> d[i];
	}
	a = 2 - k;
	for (i = 0; i < num - 1; i++) {
		if (d[i] < d[i + 1])
			a++;
		else {
			ans += max(0, a);
			a = 2 - k;
		}
	}
	ans += max(0, a);
	cout << ans << "\n";
	return 0;
}