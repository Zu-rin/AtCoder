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
	int t, num, i, j;
	string s;
	cin >> t;
	rep(j, t) {
		cin >> num;
		rep(i, 3)
			cin >> s;
		cout << string(num, '0') << string(num, '1') << "0\n";
	}
	return 0;
}