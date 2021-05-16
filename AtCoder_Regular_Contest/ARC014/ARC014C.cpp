#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, ans;
	map<char, int> mp;
	string s;
	cin >> num >> s;
	rep(i, num) {
		mp[s[i]]++;
		mp[s[i]] %= 2;
	}
	ans = mp['R'] + mp['G'] + mp['B'];
	cout << ans << "\n";
	return 0;
}