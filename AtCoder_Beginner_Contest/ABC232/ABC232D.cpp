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

typedef struct Point_Coordinates {
	int i, j;
} point;

int BFS(vector<string>& s) {
	int ans = 0;
	queue<point> que;
	que.push({ 1, 1 });
	while (que.size()) {
		point n = que.front();
		que.pop();
		chmax(ans, n.i + n.j - 1);
		if (s[n.i + 1][n.j] == '.')
			que.push({ n.i + 1, n.j });
		if (s[n.i][n.j + 1] == '.')
			que.push({ n.i, n.j + 1 });
	}
	return ans;
}

int main(void) {
	int num, i, h, w;
	cin >> h >> w;
	vector<string> s(h + 2, string(w + 2, '#'));
	for (i = 1; i <= h; i++) {
		cin >> s[i];
		s[i] = "#" + s[i] + "#";
	}
	cout << BFS(s) << "\n";
	return 0;
}