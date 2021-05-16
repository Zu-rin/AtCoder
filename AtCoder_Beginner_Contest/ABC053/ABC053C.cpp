#include<iostream>

using namespace std;

int main(void) {
	long long k, ans;
	cin >> k;
	ans = (k / 11) * 2;
	k %= 11;
	if (k != 0 && k <= 6)
		ans++;
	else if(k > 6)
		ans += 2;
	cout << ans << "\n";
	return 0;
}