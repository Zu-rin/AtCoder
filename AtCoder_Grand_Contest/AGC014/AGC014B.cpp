#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, q, a, b, i, ok = true;
	cin >> num >> q;
	vector<int> d(num + 1, 0);
	for (i = 0; i < q; i++) {
		scanf_s("%d%d", &a, &b);
		d[a]++;
		d[b]--;
	}
	a = 0;
	for (i = 1; i < num; i++) {
		a += d[i];
		if (a & 1) {
			ok = false;
			break;
		}
	}
	if (ok)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}