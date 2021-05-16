#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, a, x = 1, ans;
	cin >> num;
	ans = num;
	for (i = 0; i < num; i++) {
		cin >> a;
		if (a == x) {
			ans--;
			x++;
		}
	}
	if (ans == num)
		printf("-1\n");
	else
		cout << ans << "\n";
	return 0;
}