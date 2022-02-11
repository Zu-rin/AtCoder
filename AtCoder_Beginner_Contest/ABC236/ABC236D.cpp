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

int Search(const vector<vector<int>> d, int v, int a = 0) {
	if (v == 0)
		return a;
	int i = 0, j, k = v, ans = 0;
	while (!(v & (1 << i)))
		i++;
	k ^= (1 << i);
	j = i + 1;
	while (k >= (1 << j)) {
		if (k & (1 << j))
			chmax(ans, Search(d, k ^ (1 << j), a ^ d[i][j]));
		j++;
	}
	return ans;
}

int main(void) {
	int num, i;
	cin >> num;
	num <<= 1;
	vector<vector<int>> d(num, vector<int>(num, -1));
	rep(i, num - 1) {
		for (int j = i + 1; j < num; j++) {
			cin >> d[i][j];
		}
	}
	cout << Search(d, (1 << num) - 1) << "\n";
	return 0;
}