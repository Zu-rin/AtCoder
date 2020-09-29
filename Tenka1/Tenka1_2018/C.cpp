#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i;
	long long a = 0, b = 0;
	cin >> num;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	for (i = 0; i < (num - 2) >> 1; i++) {
		a -= d[i] << 1;
		b += d[num - 1 - i] << 1;
	}
	for (i = 0; i < ((num - 2) >> 1) + (num & 1); i++) {
		a += d[num - 1 - i] << 1;
		b -= d[i] << 1;
	}
	if (num & 1) {
		a -= d[i] + d[i - 1];
		b += d[i] + d[i + 1];
	}
	else {
		a += d[i + 1] - d[i];
		b += d[i + 1] - d[i];
	}
	cout << max(a, b) << "\n";
	return 0;
}
