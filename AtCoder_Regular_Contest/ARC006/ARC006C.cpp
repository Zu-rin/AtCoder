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
	int num, i, j, ans = 0, b;
	cin >> num;
	vector<int> d(num), a(num, true);
	rep(i, num)
		cin >> d[i];
	rep(i, num) {
		if (a[i]) {
			ans++;
			b = d[i];
			for (j = i; j < num; j++) {
				if (a[j] && d[j] <= b) {
					a[j] = false;
					b = d[j];
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}