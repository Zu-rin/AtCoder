#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, i, a, t = 0;
	vector<int> d(100001, 0);
	cin >> num;
	for (i = 0; i < num; i++) {
		scanf_s("%d", &a);
		d[a]++;
	}
	for (i = 1; i <= 100000; i++) {
		if (d[i] & 1)
			num -= d[i] - 1;
		else if (d[i] > 0) {
			t++;
			num -= d[i] - 2;
		}
	}
	num -= t + (t & 1);
	cout << num << "\n";
	return 0;
}