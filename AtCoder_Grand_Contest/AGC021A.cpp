#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	long long h, n, len = -1, sum = 0;
	cin >> n;
	while (n > 0) {
		sum += n % 10;
		len++;
		h = n;
		n /= 10;
	}
	cout << max(h + 9 * len - 1, sum) << "\n";
	return 0;
}