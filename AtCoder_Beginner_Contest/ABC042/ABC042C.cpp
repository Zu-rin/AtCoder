#include <iostream>
#include <vector>

using namespace std;

int Judge(int n, vector<int> &d) {
	do {
		if (d[n % 10])
			return false;
		n /= 10;
	}while (n > 0);
	return true;
}

int main(void) {
	int ans, k, i, a;
	vector<int> d(10, false);
	cin >> ans >> k;
	for (i = 0; i < k; i++) {
		scanf_s("%d", &a);
		d[a] = true;
	}
	while (!Judge(ans, d)) {
		ans++;
	}
	cout << ans << "\n";
	return 0;
}