#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, q, i = 0, l, r, ans = 0;
	cin >> num >> q;
	vector<int> data(num + 1, 0);
	for (; i < q; i++) {
		scanf_s("%d%d", &l, &r);
		data[l - 1]++;
		data[r]--;
	}
	for (i = 0; i < num; i++) {
		ans += data[i];
		ans = ans & 1;
		if (ans)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	return 0;
}