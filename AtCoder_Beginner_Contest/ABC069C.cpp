#include <iostream>

using namespace std;

int main(void) {
	int num, i = 0, buf, data[3] = { 0 };
	cin >> num;
	for (; i < num; i++) {
		scanf_s("%d", &buf);
		if ((buf & 1) == 1)
			data[0]++;
		else if ((buf & 2) == 2)
			data[1]++;
		else
			data[2]++;
	}
	if (data[2] >= data[0])
		cout << "Yes\n";
	else if (data[1] == 0 && data[2] == data[0] - 1)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}