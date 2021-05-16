#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int Count(int n) {
	int ans = 0;
	if (n < 1000)
		ans = 1;
	while (n) {
		ans |= 1 << (n % 10);
		n /= 10;
	}
	return ans;
}

int main(void) {
	int num, i, o = 0, x = 0, ans = 0;
	string s;
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == 'o')
			o |= 1 << i;
		else if (s[i] == 'x')
			x |= 1 << i;
	}
	for (i = 0; i < 10000; i++) {
		int n = Count(i);
		if ((n & o) == o and (n & x) == 0)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}