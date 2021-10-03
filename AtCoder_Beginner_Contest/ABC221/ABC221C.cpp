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

int main(void) {
	int num, i;
	ll ans = 0;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	do {
		for (i = 1; i < s.size(); i++)
			chmax(ans, stoll(s.substr(0, i)) * stoll(s.substr(i)));
	} while (next_permutation(s.begin(), s.end()));
	cout << ans << "\n";
	return 0;
}