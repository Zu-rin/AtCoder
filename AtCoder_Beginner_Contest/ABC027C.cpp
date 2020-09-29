#include <iostream>
#define W true
#define L false
using namespace std;

int main(void) {
	bool res = L;
	long int l, r;
	cin >> r;
	l = (r + 1) / 2 + ((r + 1) & 1);
	while (1 < l) {
		if (res == W) {
			l = (l / 2) + (l & 1);
			r = (r - 1) / 2;
		}
		else {
			l = (l - 1) / 2 + ((l - 1) & 1);
			r /= 2;
		}
		res = !res;
	}
	if (res == W)
		cout << "Takahashi\n";
	else
		cout << "Aoki\n";
	return 0;
}