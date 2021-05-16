#include <iostream>

using namespace std;

int main(void) {
	int m, n, num, ans = 0, buf = 0;
	cin >> m >> n >> num;
	while(num > 0){
		ans += num;
		buf += num;
		num = n * (buf / m);
		buf %= m;
	}
	cout << ans << "\n";
	return 0;
}