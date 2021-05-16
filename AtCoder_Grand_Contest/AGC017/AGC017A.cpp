#include <iostream>

using namespace std;

int main(void) {
	int p, g = 0, k = 0, a, i;
	long long num;
	cin >> num >> p;
	for (i = 0; i < num; i++) {
		scanf("%d", &a);
		if (a & 1)
			k++;
		else
			g++;
	}
	if (k == 0) {
		if (p)
			printf("0\n");
		else
			cout << (1ll << num) << "\n";
		return 0;
	}
	cout << (1ll << (num - 1)) << "\n";
	return 0;
}
