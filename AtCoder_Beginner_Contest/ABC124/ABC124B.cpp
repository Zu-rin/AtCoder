#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int num, i = 0, j, ans = 1;
	bool ok;
	cin >> num;
	vector<int> h(num);
	for (; i < num; i++)
		cin >> h[i];
	for (i = 1; i < num; i++) {
		ok = true;
		for (j = i - 1; j >= 0; j--) {
			if (h[i] < h[j]) {
				ok = false;
				break;
			}
		}
		if (ok)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}