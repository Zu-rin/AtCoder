#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int a, b, num, i, ans = 0;
	cin >> num >> b;
	vector<int> d(num - 1, 0);
	for (i = 0; i < num - 1; i++) {
		scanf_s("%d", &a);
		d[i] = a - b;
		b = a;
	}
	for (i = 0; i < num - 1; i++) {
		if (d[i] == 0)
			continue;
		if (d[i] > 0) {
			while (i < num - 1 && d[i] >= 0)
				i++;
			if (i < num - 1)
				ans++;
		}
		else {
			while (i < num - 1 && d[i] <= 0)
				i++;
			if (i < num - 1)
				ans++;
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}