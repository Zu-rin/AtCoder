#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

string s;

ll Sum(int pre, int now, ll sum) {
	ll ans = 0;
	for (int i = 0; i < now - pre; i++)
		ans += (s[now - i] - '0')*ll(pow(10, i));
	if (now == s.size() - 1)
		return ans + sum;
	return Sum(pre, now + 1, sum) + Sum(now, now + 1, sum + ans);
}

int main(void) {
	cin >> s;
	cout << Sum(-1, 0, 0) << "\n";
	return 0;
}