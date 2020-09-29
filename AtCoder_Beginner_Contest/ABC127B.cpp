#include <iostream>

using namespace std;

int main(void) {
	int r, d;
	long long s;
	cin >> r >> d >> s;
	for (int i = 0; i < 10; i++) {
		s = r * s - d;
		if (s < 0)
			s = 0;
		printf("%d\n", s);
	}
	return 0;
}