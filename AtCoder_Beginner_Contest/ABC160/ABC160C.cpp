#include <iostream>
#include <vector>
#include <string>
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
	int sum, num, i, mi = 0;
	cin >> sum >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	rep(i, num - 1)
		chmax(mi, d[i + 1] - d[i]);
	chmax(mi, d[0] + sum - d[num - 1]);
	cout << sum - mi << "\n";
	return 0;
}