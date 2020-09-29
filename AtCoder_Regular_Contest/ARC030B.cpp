#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int DFS(int n, int p, vector<int>& d, vector<list<int>>& mp) {
	for (auto itr = mp[n].begin(); itr != mp[n].end(); itr++) {
		if (*itr != p) {
			d[n] |= DFS(*itr, n, d, mp);
		}
	}
	return d[n];
}

int main(void) {
	int num, x, i, a, b, ans = 0;
	cin >> num >> x;
	vector<int> d(num + 1, 0);
	vector<list<int>> mp(num + 1);
	for (i = 1; i <= num; i++) {
		cin >> d[i];
	}
	for (i = 0; i < num - 1; i++) {
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	DFS(x, 0, d, mp);
	for (i = 1; i <= num; i++) {
		if (d[i])
			ans++;
	}
	cout << max(0, 2 * (ans - 1)) << "\n";
	return 0;
}