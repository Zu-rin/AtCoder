#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, c, m, ans = 0;
	cin >> num >> c;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	for (i = num - 1, m = 0; i >= m; i--) {
		if (d[i] + d[m] < c)
			m++;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}