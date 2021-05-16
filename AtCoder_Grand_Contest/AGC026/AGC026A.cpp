#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, i, len, ans = 0;
	cin >> num;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	for (i = 0; i < num - 1; i++) {
		len = 1;
		while (i < num - 1 && d[i] == d[i + 1]) {
			len++;
			i++;
		}
		ans += len >> 1;
	}
	cout << ans << "\n";
	return 0;
}