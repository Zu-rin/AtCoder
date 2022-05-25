#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
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

int culc(vector<string> &s, int n) {
	int i, j;
	map<int, int> mp;
	rep(i, 10) {
		int k = 0;
		rep(j, s.size()) {
			if (s[j][i] == '0' + n)
				k++;
		}
		mp[k] = i;
	}
	int k = (*mp.rbegin()).first, x = (*mp.rbegin()).second;
	return (k - 1) * 10 + x;
}

int main(void) {
	int num, i, ans = INF;
	cin >> num;
	vector<string> s(num);
	rep(i, num)
		cin >> s[i];
	rep(i, 10)
		chmin(ans, culc(s, i));
	cout << ans << "\n";
	return 0;
}