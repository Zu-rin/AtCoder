#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int num, i = 0, j, k, n, ans = -2048, buf1, buf2, fir, sec;
	cin >> num;
	vector<int> s(num);
	for (; i < num; i++)
		scanf_s("%d", &s[i]);

	for (i = 0; i < num; i++) {
		buf2 = -2048;
		for (j = 0; j < num; j++) {
			if (j == i)
				continue;
			fir = 0;
			sec = 0;
			for (k = min(i, j), n = 0; k <= max(i, j); k++, n++) {
				if (n % 2)
					sec += s[k];
				else
					fir += s[k];
			}
			if (buf2 < sec) {
				buf2 = sec;
				buf1 = fir;
			}
		}
		ans = max(ans, buf1);
	}
	cout << ans << "\n";
	return 0;
}