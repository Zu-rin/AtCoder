#include <iostream>
#include <vector>
#include <algorithm>
#define INF 200000000000000

using namespace std;

int main(void) {
	int num, i = 0;
	long long ans = INF, dif = 0;
	cin >> num;
	vector<int> d(num);
	for (; i < num; i++) {
		scanf_s("%d", &d[i]);
		dif += d[i];
	}
	for (i = 0; i < num - 1; i++) {
		dif -= 2 * d[i];
		ans = min(ans, abs(dif));
	}
	cout << ans << "\n";
	return 0;
}