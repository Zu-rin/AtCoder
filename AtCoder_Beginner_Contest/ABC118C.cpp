#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, j = 0, ans;
	cin >> num;
	vector<int> d(num);
	for (; i < num; i++)
		scanf_s("%d", &d[i]);
	while (j < num - 1) {
		sort(d.begin(), d.end());
		while (d[j] == 0)
			j++;
		ans = d[j];
		for (i = j + 1; i < num; i++)
			d[i] %= ans;
	}
	cout << ans << "\n";
	return 0;
}