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
	int num, i, j, h, w;
	cin >> h >> w;
	vector<string> s(h);
	vector<vector<char>> d(h, vector<char>(w, 0));
	rep(i, h)
		cin >> s[i];
	i = j = 0;
	while (true) {
		if (d[i][j]) {
			printf("-1\n");
			break;
		}
		d[i][j] = 1;
		if (s[i][j] == 'U' and i > 0)
			i--;
		else if (s[i][j] == 'D' and i < h - 1)
			i++;
		else if (s[i][j] == 'L' and j > 0)
			j--;
		else if (s[i][j] == 'R' and j < w - 1)
			j++;
		else {
			printf("%d %d\n", i + 1, j + 1);
			break;
		}
	}
	return 0;
}