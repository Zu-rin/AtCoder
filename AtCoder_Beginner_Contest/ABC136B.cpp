#include <iostream>

using namespace std;

int main(void) {
	int i = 1, n, ans = 0;
	cin >> n;
	while (i <= n) {
		if (i < 10)
			ans++;
		else if (i >= 100 && i < 1000)
			ans++;
		else if (i >= 10000 && i < 100000)
			ans++;
		i++;
	}
	printf("%d\n", ans);
	return 0;
}