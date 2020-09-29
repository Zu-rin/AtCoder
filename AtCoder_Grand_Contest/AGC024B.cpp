#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, a, ans = 1;
	cin >> num;
	vector<int> d(num + 1);
	for (i = 1; i <= num; i++) {
		scanf_s("%d", &a);
		d[a] = i;
	}
	for (a = 1, i = 1; i < num; i++) {
		if (d[i] < d[i + 1]) {
			a++;
			ans = max(a, ans);
		}
		else
			a = 1;
	}
	cout << num - ans << "\n";
	return 0;
}