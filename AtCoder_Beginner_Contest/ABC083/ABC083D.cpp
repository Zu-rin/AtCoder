#include <iostream>
#include <vector>
#include <string>
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

int main(void) {
	int i, ans;
	string s;
	cin >> s;
	ans = s.size();
	for(i = 1; i < s.size(); i++) {
		if (s[i - 1] != s[i])
			chmin(ans, max(i, (int)s.size() - i));
	}
	cout << ans << "\n";
	return 0;
}