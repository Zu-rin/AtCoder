#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
	int num, a, b, i = 0, j, buf, ans = 0;
	cin >> num;
	map<int, vector<int>> d;
	for (; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		if (a > b) {
			buf = a;
			a = b;
			b = buf;
		}
		for (j = 0; j < d[a].size(); j++) {
			if (d[a][j] == b)
				break;
		}
		if (j == d[a].size()) {
			d[a].push_back(b);
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}