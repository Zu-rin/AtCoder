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
	cin >> num;
	string e;
	vector<string> s(num);
	vector<int> t(num);
	rep(i, num)
		cin >> s[i] >> t[i];
	cin >> e;
	rep(i, num) {
		if (s[i] == e) {
			i++;
			break;
		}
	}
	for (; i < num; i++) {
		ans += t[i];
	}
	cout << ans << "\n";
	return 0;
}