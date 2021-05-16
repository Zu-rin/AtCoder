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

int main(void) {
	int num, m, i, a, ans;
	cin >> num >> m;
	ans = num;
	vector<int> d(1500000, -1);
	rep(i, num) {
		scanf_s("%d", &a);
		if (a < ans){
			if(d[a] + m < i)
				ans = a;
			d[a] = i;
		}
	}
	rep(i, ans) {
		if (d[i] + m < num) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}