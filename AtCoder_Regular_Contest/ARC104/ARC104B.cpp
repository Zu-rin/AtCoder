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
	int num, i, j, ans = 0;
	char a = 'A', t = 'T', c = 'C', g = 'G';
	string s;
	cin >> num >> s;
	map<char, vector<int>> d;
	d[a].resize(num + 1);
	d[t].resize(num + 1);
	d[c].resize(num + 1);
	d[g].resize(num + 1);
	rep(i, s.size())
		d[s[i]][i + 1]++;
	for (auto it = d.begin(); it != d.end(); it++) {
		vector<int>& x = (*it).second;
		rep(i, num)
			x[i + 1] += x[i];
	}
	for (i = 1; i <= num; i++) {
		rep(j, i) {
			if (d[a][i] - d[a][j] == d[t][i] - d[t][j] && d[c][i] - d[c][j] == d[g][i] - d[g][j])
				ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}