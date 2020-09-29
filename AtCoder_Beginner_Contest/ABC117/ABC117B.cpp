#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, sum = 0, buf, ma = 0;
	cin >> num;
	for (; i < num; i++) {
		scanf_s("%d", &buf);
		ma = max(ma, buf);
		sum += buf;
	}
	if (ma < sum - ma)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}