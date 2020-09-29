#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, m, i = 0, ans = 0;
	cin >> num >> m;
	vector<int> dis(m - 1), pos(m);
	for (; i < m; i++)
		scanf_s("%d", &pos[i]);
	sort(pos.begin(), pos.end());
	for (i = 0; i < m - 1; i++)
		dis[i] = pos[i + 1] - pos[i];
	sort(dis.begin(), dis.end());
	for (i = 0; i < m - num; i++)
		ans += dis[i];
	cout << ans << "\n";
	return 0;
}