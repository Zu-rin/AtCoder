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
	int num, i, j, a;
	cin >> num;
	vector<int> ans = {0};
	printf("0\n");
	rep(i, num) {
		cin >> a;
		a = ans[a - 1] + 1;
		rep(j, 2) {
			ans.push_back(a);
			cout << a << "\n";
		}
	}
	return 0;
}