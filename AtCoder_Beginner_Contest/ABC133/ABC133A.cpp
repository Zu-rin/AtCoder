#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void) {
	int num, a, b, ans;
	cin >> num >> a >> b;
	ans = min(num * a, b);
	cout << ans << "\n";
	return 0;
}