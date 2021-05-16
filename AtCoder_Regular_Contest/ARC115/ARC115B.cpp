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
	cin >> num;
	vector<vector<int>> d(num, vector<int>(num));
	vector<int> a(num, INF), b(num);
	rep(i, num) {
		rep(j, num) {
			cin >> d[i][j];
		}
	}
	rep(i, num) {
		rep(j, num)
			chmin(a[i], d[i][j]);
		b[i] = d[0][i] - a[0];
	}
	rep(i, num) {
		rep(j, num) {
			if (d[i][j] != a[i] + b[j]) {
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	rep(i, num - 1)
		cout << a[i] << " ";
	cout << a[i] << "\n";
	rep(i, num - 1)
		cout << b[i] << " ";
	cout << b[i] << "\n";
	return 0;
}