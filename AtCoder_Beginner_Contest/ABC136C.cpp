#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, i, ok = true;
	cin >> num;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	d[0]--;
	for (i = 1; i < num; i++) {
		if (d[i - 1] < d[i])
			d[i]--;
		else if (d[i - 1] > d[i]) {
			ok = false;
			break;
		}
	}
	if (ok)
		printf("Yes");
	else
		printf("No\n");
	return 0;
}