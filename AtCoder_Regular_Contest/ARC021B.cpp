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
	cin >> num;
	vector<int> d(num), ans(num, 0);
	for (i = 0; i < num; i++) {
		cin >> d[i];
	}
	for (i = 0; i < num - 1; i++) {
		ans[i + 1] = ans[i] ^ d[i];
	}
	if ((ans[0] ^ ans[num - 1]) == d[num - 1]) {
		for (i = 0; i < num; i++) {
			cout << ans[i] << "\n";
		}
	}
	else
		printf("-1\n");
	return 0;
}