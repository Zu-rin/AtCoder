#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num, NG[3], i = 0, limit = 100;
	cin >> num >> NG[0] >> NG[1] >> NG[2];
	sort(NG, NG + 3, greater<int>());
	if (num > NG[0] && NG[1] + 1 == NG[0] && NG[2] + 1 == NG[1] || NG[0] == num || NG[1] == num || NG[2] == num) {
		cout << "NO\n";
		return 0;
	}
	while (i < 3) {
		while (NG[i] > num)
			i++;
		num -= 3;
		limit--;
		while (num == NG[0] || num == NG[1] || num == NG[2])
			num++;
	}
	if (num <= limit * 3)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}