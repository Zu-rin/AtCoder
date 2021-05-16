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
	int num, i, a;
	cin >> num;
	vector<list<int>> d(num);
	rep(i, num - 1) {
		cin >> a;
		d[a - 1].push_back(i + 1);
	}
	rep(i, num) {
		cout << d[i].size() <<"\n";
	}
	return 0;
}