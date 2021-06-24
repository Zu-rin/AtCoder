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
	int num, i, t, x;
	vector<int> a, b;
	cin >> num;
	rep(i, num) {
		cin >> t >> x;
		if (t == 1)
			a.push_back(x);
		else if (t == 2)
			b.push_back(x);
		else {
			if (x <= a.size())
				cout << a[a.size() - x] << "\n";
			else
				cout << b[x - a.size() - 1] << "\n";
		}
	}
	return 0;
}