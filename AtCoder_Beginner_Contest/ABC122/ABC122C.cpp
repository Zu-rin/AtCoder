#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	int len, qs, i = 1, l, r, cnt = 0;
	string str;
	cin >> len >> qs >> str;
	vector<int> num(len);
	for (; i < len; i++) {
		if (str[i - 1] == 'A' && str[i] == 'C')
			cnt++;
		num[i] = cnt;
	}
	i = 0;
	for (; i < qs; i++) {
		scanf_s("%d %d", &l, &r);
		printf("%d\n", num[r-1]-num[l-1]);
	}
	return 0;
}