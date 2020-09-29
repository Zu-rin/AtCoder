#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, t, i, ans;
	cin >> num >> t;
	vector<int> d(t);
	for (i = 0; i < t; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end(), greater<int>());
	for (ans = d[0], i = 1; i < t; i++)
		ans = abs(ans - d[i]);
	if (ans > 0)
		ans--;
	cout << ans << "\n";
	return 0;
}