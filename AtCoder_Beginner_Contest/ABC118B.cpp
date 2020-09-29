#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, menu, i = 0, j, buf, ans = 0;
	cin >> num >> menu;
	vector<int> d(menu, 0);
	for (; i < num; i++) {
		cin >> j;
		for (; j > 0; j--) {
			scanf_s("%d", &buf);
			d[--buf]++;
		}
	}
	for (i = 0; i < menu; i++)
		if (d[i] == num)
			ans++;
	cout << ans << "\n";
	return 0;
}