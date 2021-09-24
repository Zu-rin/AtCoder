#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
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
	int num, i, j;
	cin >> num;
	vector<int> a(num), b(num);
	set<int> ans;
	rep(i, num)
		cin >> a[i];
	rep(i, num)
		cin >> b[i];
	sort(a.begin(), a.end());
	rep(i, num) {
		vector<int> d(num);
		int x = a[0] ^ b[i];
		rep(j, num)
			d[j] = x ^ b[j];
		sort(d.begin(), d.end());
		if (a == d)
			ans.insert(x);
	}
	cout << ans.size() << "\n";
	for(int a : ans)
		cout << a << "\n";
	return 0;
}