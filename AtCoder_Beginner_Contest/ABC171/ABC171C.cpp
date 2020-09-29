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
	ll num, i;
	string ans = "";
	cin >> num;
	while (num > 0) {
		num--;
		int a = num % 26;
		num /= 26;
		char c = 'a' + a;
		ans += c;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
	return 0;
}