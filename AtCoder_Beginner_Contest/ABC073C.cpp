#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, c, ans = 0;
	cin >> num;
	vector<int> d(num);
	for (; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	for (i = 0; i < num - 1; i++) {
		c = 0;
		while (i < num - 1 && d[i] == d[i + 1]) {
			c++;
			i++;
		}
		if ((c & 1) == 0)
			ans++;
	}
	if (d[num - 2] != d[num - 1])
		ans++;
	cout << ans << "\n";
	return 0;
}