#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, m, a, b, i = 0;
	cin >> num >> m;
	vector<bool> s(num + 1, false), g(num + 1, false);
	for (; i < m; i++) {
		scanf("%d%d", &a, &b);
		if (a == 1)
			s[b] = true;
		if (b == num)
			g[a] = true;
	}
	for (i = 1; i <= num; i++) {
		if (s[i] && g[i]) {
			cout << "POSSIBLE\n";
			break;
		}
	}
	if (i == num + 1)
		cout << "IMPOSSIBLE\n";
	return 0;
}