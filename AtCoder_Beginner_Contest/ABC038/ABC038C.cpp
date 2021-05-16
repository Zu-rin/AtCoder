#include <iostream>
#include <vector>

using namespace std;

long long Cho2(long long a) {
	return a * (a - 1) / 2;
}

int main(void) {
	int num, i = 0;
	long long ans = 0, len = 1;
	cin >> num;
	vector<int> data(num);
	for (; i < num; i++)
		scanf_s("%d", &data[i]);
	for (i = 0; i < num - 1; i++) {
		if (data[i] < data[i + 1])
			len++;
		else {
			ans += Cho2(len);
			len = 1;
		}
	}
	ans += Cho2(len);
	cout << ans + num << "\n";
	return 0;
}