#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i;
	double a, b;
	vector<int> ans(6, 0);
	cin >> num;
	for (i = 0; i < num; i++) {
		cin >> a >> b;
		if (a >= 35.0)
			ans[0]++;
		else if (a >= 30.0)
			ans[1]++;
		else if (a >= 25.0)
			ans[2]++;
		if (b >= 25.0)
			ans[3]++;
		if (b < 0.0) {
			if (a >= 0.0)
				ans[4]++;
			else
				ans[5]++;
		}
	}
	cout << ans[0];
	for (i = 1; i < 6; i++)
		printf(" %d", ans[i]);
	cout << "\n";
	return 0;
}