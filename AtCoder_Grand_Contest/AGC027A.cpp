#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int num, i, x, ans = 0;
	cin >> num >> x;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	i = 0;
	while (i < num) {
		x -= d[i++];
		if (x >= 0)
			ans++;
		else
			break;
	}
	if (x > 0)
		ans--;
	cout << ans << "\n";
	return 0;
}