#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int k, x, i;
	cin >> k >> x;
	for (i = -1000000; i <= 1000000; i++) {
		if (i > x - k && i < x + k)
			printf("%d ", i);
	}
	cout << "\n";
	return 0;
}