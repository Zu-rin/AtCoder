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

int Rowjudge(const vector<int> &d) {
	int i, lst = d[d.size() - 1] % 7;
	if(lst){
		rep(i, d.size() - 1) {
			if (d[i] + 1 != d[i + 1] or d[i] % 7 == 0 or d[i] % 7 != lst - d.size() + 1 + i)
				return  0;
		}
	}
	else {
		rep(i, d.size() - 1) {
			if (d[i] + 1 != d[i + 1] or d[i] % 7 != 8 - d.size() + i)
				return  0;
		}
	}
	return 1;
}

int Coljudge(const vector<vector<int>>& d) {
	int i, j;
	rep(j, d[0].size()) {
		rep(i, d.size() - 1) {
			if (d[i][j] + 7 != d[i + 1][j])
				return 0;
		}
	}
	return 1;
}

int main(void) {
	int n, m, i, j;
	cin >> n >> m;
	vector<vector<int>> d(n, vector<int>(m));
	rep(i, n) {
		rep(j, m) {
			cin >> d[i][j];
		}
	}
	if (Rowjudge(d[0]) && Coljudge(d))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}