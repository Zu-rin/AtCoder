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

int Solve(vector<int> & d, int s) {
	int i, j, ans = 0;
	rep(i, s) {
		if (d[i] == d[s])
			continue;
		for (j = i + 1; j < s; j++) {
			if (d[i] == d[j] || d[j] == d[s])
				continue;
			if(d[i] + d[j] > d[s])
				ans++;
		}
	}
	return ans;
}

int main(void) {
	int num, i;
	ll ans = 0;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	sort(d.begin(), d.end());
	for (i = 2; i < d.size(); i++) {
		ans += Solve(d, i);
	}
	cout << ans << "\n";
	return 0;
}