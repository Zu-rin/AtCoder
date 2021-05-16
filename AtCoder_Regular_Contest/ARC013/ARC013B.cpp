#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j;
	vector<int> d(3), ans(3);
	cin >> num;
	for (i = 0; i < num; i++) {
		for (j = 0; j < 3; j++)
			cin >> d[j];
		sort(d.begin(), d.end());
		for (j = 0; j < 3; j++)
			ans[j] = max(ans[j], d[j]);
	}
	cout << ans[0] * ans[1] * ans[2] << "\n";
	return 0;
}