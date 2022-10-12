#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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
	int num, i, x;
	cin >> num;
	vector<int> a, b;
	rep(i, num) {
		cin >> x;
		if (x & 1)
			a.push_back(x);
		else
			b.push_back(x);
	}
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	if (a.size() > 1 and b.size() > 1)
		cout << max(a[0] + a[1], b[0] + b[1]) << "\n";
	else if (a.size() > 1)
		cout << a[0] + a[1] << "\n";
	else if (b.size() > 1)
		cout << b[0] + b[1] << "\n";
	else
		printf("-1\n");
	return 0;
}