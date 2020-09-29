#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int n, m, i, j, x, y;
	bool match = false;
	cin >> n >> m;
	vector<string> a(n), b(m);
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < m; i++)
		cin >> b[i];
	for (y = 0; match == false && y <= n - m; y++) {
		for (x = 0; match == false && x <= n - m; x++) {
			if (a[y][x] == b[0][0]) {
				for (i = 0; i < m; i++) {
					for (j = 0; j < m; j++) {
						if (a[i + y][j + x] != b[i][j])
							break;
					}
					if (j != m)
						break;
				}
				if (i == m)
					match = true;
			}
		}
	}
	if (match)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}