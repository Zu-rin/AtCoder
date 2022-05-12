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

void swap(int& a, int& b) {
	int x = a;
	a = b;
	b = x;
}

int main(void) {
	int num, i, q, x;
	cin >> num >> q;
	map<int, int> mp;
	vector<int> ans(num + 1);
	for (i = 0; i < num; i++) {
		mp[i + 1] = i;
		ans[i] = i + 1;
	}
	rep(i, q) {
		cin >> x;
		if (mp[x] == num - 1) {
			swap(ans[num - 1], ans[num - 2]);
			mp[x] = num - 2;
			mp[ans[num - 1]] = num - 1;
		}
		else {
			swap(ans[mp[x]], ans[mp[x] + 1]);
			mp[ans[mp[x]]] = mp[x];
			mp[x]++;
		}
	}
	rep(i, num - 1)
		cout << ans[i] << " ";
	cout << ans[i] << "\n";
	return 0;
}