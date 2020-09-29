#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, i, ans = 0;
	cin >> num;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	for (i = 1; i < num - 1; i++) {
		if (d[i - 1] < d[i] && d[i] < d[i + 1])
			ans++;
		else if (d[i - 1] > d[i] && d[i] > d[i + 1])
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}