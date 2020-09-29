#include <iostream>

using namespace std;

int main(void) {
	int num, i = 0, buf, ans = 0;;
	cin >> num;
	for (; i < num; i++) {
		scanf_s("%d", &buf);
		ans += buf;
	}
	printf("%d\n", ans - num);
	return 0;
}