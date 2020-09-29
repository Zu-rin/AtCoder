#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 1, boss;
	cin >> num;
	vector<int> b(num);
	vector<long int> ma(num, 0), mi(num, 0), inc(num);
	for (; i < num; i++)
		scanf_s("%d", &b[i]);
	for (i = num - 1; i > 0; i--) {
		inc[i] = ma[i] + mi[i] + 1;
		boss = b[i] - 1;
		if (ma[boss] == 0) {
			ma[boss] = inc[i];
			mi[boss] = inc[i];
		}
		else {
			ma[boss] = max(ma[boss], inc[i]);
			mi[boss] = min(mi[boss], inc[i]);
		}
	}
	cout << ma[0] + mi[0] + 1 << "\n";
	return 0;
}