#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, ans = 0;
	cin >> num;
	vector<int> d(num);
	for (; i < num; i++) {
		scanf_s("%d", &d[i]);
		ans += d[i];
	}
	sort(d.begin(), d.end());
	if (ans % 10 != 0)
		cout << ans << "\n";
	else {
		i = 0;
		while (i < num && d[i] % 10 == 0)
			i++;
		if (i == num)
			printf("0\n");
		else
			cout << ans - d[i] << "\n";
	}
	return 0;
}