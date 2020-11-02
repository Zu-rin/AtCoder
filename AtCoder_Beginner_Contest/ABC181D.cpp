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
	int num, i, j;
	string s;
	cin >> s;
	vector<int> d(10, 0);
	for(char c : s) {
		d[c - '0']++;
	}
	for (i = 8; i < 1000; i += 8) {
		vector<int> a(10);
		int x = i, ok = 1, l = 0;
		while (x) {
			a[x % 10]++;
			l++;
			x /= 10;
		}
		rep(j, 10) {
			if (d[j] - a[j] < 0 || (l < 3 && l < s.size())) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}