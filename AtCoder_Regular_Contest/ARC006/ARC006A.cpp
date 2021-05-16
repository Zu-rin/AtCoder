#include <iostream>

using namespace std;

int main(void) {
	int buf, e = 0, a = 0, b, i, ans = 0;
	for (i = 0; i < 6; i++) {
		scanf_s("%d", &buf);
		e += 1 << buf;
	}
	scanf_s("%d", &buf);
	b = 1 << buf;
	for (i = 0; i < 6; i++) {
		scanf_s("%d", &buf);
		a += 1 << buf;
	}
	buf = a & e;
	while (buf > 0) {
		if (buf & 1)
			ans++;
		buf >>= 1;
	}
	switch (ans) {
	case 6:
		printf("1\n");
		break;
	case 5:
		if ((a & b) > 0)
			printf("2\n");
		else
			printf("3\n");
		break;
	case 4:
		printf("4\n");
		break;
	case 3:
		printf("5\n");
		break;
	default:
		printf("0\n");
	}
	return 0;
}