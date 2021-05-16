#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, ans;
	cin >> num;
	vector<int> data(num);
	for (; i < num; i++) {
		scanf_s("%d", &ans);
		while ((ans & 1) == 0)
			ans >>= 1;
		data[i] = ans;
	}
	sort(data.begin(), data.end());
	for (i = 1, ans = 1; i < num; i++) {
		if (data[i - 1] < data[i])
			ans++;
	}
	cout << ans << "\n";
	return 0;
}