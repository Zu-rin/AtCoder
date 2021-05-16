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

int Judge(int n) {
	string s = to_string(n);
	if ((int)s.find("7") >= 0)
		return 0;
	while (n) {
		if ((n % 8) == 7)
			return 0;
		n /= 8;
	}
	return 1;
}

int main(void) {
	int num, i, ans = 0;
	cin >> num;
	for (i = 1; i <= num; i++) {
		if (Judge(i))
			ans++;
	}
	cout << ans << "\n";
	return 0;
}