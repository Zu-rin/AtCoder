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
	int num, m, i;
	ll a = 0, b = 0;
	cin >> num >> m;
	string s;
	rep(i, num) {
		cin >> s;
		int x = 0;
		for (char c : s) {
			if (c == '1')
				x++;
		}
		if (x & 1)
			a++;
		else
			b++;
	}
	cout << a * b << "\n";
	return 0;
}