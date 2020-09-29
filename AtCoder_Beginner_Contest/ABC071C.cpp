#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, p = 0;
	long long ans[2] = { 0 };
	cin >> num;
	vector<int> d(num);
	for (; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end(), greater<int>());
	for (i = 0; i < num-1; i++) {
		if (d[i] == d[i + 1]) {
			ans[p++] = d[i++];
			if (p == 2)
				break;
		}
	}
	cout << ans[0] * ans[1] << "\n";
	return 0;
}