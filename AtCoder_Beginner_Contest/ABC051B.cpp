#include <iostream>

using namespace std;

int main(void) {
	int k, s, x, y, z, ans = 0;
	cin >> k >> s;
	for (x = 0; x <= k; x++) {
		for (y = 0; y <= k; y++) {
			z = s - x - y;
			if (0 <= z && z <= k)
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}