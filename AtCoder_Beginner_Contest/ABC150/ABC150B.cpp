#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, ans = 0;
	string s;
	cin >> num >> s;
	rep(i, num - 2) {
		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
			ans++;
	}
	cout << ans << "\n";
	return 0;
}