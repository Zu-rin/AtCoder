#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	ll num, ans = 0;
	cin >> num;
	ans = (num + 1) * num / 2;
	ans -= num;
	cout << ans << "\n";
	return 0;
}