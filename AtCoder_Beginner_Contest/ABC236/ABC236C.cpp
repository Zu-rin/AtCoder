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

int main(void) {
	int n, m, i;
	cin >> n >> m;
	string s;
	map<string, int> mp;
	vector<char> ans(n, 0);
	rep(i, n) {
		cin >> s;
		mp[s] = i;
	}
	rep(i, m) {
		cin >> s;
		ans[mp[s]] = 1;
	}
	rep(i, n) {
		if (ans[i])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}