#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, i, ans = 0;
	cin >> num;
	vector<int> d(num + 1);
	for (i = 1; i <= num; i++)
		scanf_s("%d", &d[i]);
	for (i = 1; i <= num; i++) {
		if (d[d[i]] == i)
			ans++;
	}
	ans >>= 1;
	cout << ans << "\n";
	return 0;
}