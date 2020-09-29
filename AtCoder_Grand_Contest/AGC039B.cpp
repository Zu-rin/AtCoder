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

queue<int> que;

int BFS(int n, vector<string> & mp, vector<int> & d) {
	int i, j;
	rep(i, mp.size()) {
		if (mp[n][i] == '1') {
			if (d[i] == INF) {
				d[i] = d[n] + 1;
				que.push(i);
			}
			else if (abs(d[i] - d[n]) != 1)
				return -1;
		}
	}
	if (que.empty())
		return d[n];
	n = que.front();
	que.pop();
	return BFS(n, mp, d);
}

int BFS(int n, vector<string> & mp) {
	vector<int> d(mp.size(), INF);
	d[n] = 1;
	return BFS(n, mp, d);
}

int main(void) {
	int num, i, j, ans = -1;
	cin >> num;
	vector<string> mp(num);
	rep(i, num)
		cin >> mp[i];
	rep(i, num)
		chmax(ans, BFS(i, mp));
	cout << ans << "\n";
	return 0;
}