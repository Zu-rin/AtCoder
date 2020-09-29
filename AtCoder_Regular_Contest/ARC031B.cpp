#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

queue<pair<int, int>> que;

int BFS(int y, int x, vector<string> &s) {
	s[y][x] = 'x';
	if (y > 0 && s[y - 1][x] == 'o') {
		que.push(make_pair(y - 1, x));
		s[y - 1][x] = 'x';
	}
	if (y < 9 && s[y + 1][x] == 'o') {
		que.push(make_pair(y + 1, x));
		s[y + 1][x] = 'x';
	}
	if (x > 0 && s[y][x - 1] == 'o') {
		que.push(make_pair(y, x - 1));
		s[y][x - 1] = 'x';
	}
	if (x < 9 && s[y][x + 1] == 'o') {
		que.push(make_pair(y, x + 1));
		s[y][x + 1] = 'x';
	}
	if (que.empty())
		return 0;
	y = que.front().first;
	x = que.front().second;
	que.pop();
	return BFS(y, x, s) + 1;
}

int main(void) {
	int num, i, j, sum = 0, ok = false;
	vector<string> mp(10), s(10);
	for (i = 0; i < 10; i++) {
		cin >> mp[i];
		for (j = 0; j < 10; j++) {
			if (mp[i][j] == 'o')
				sum++;
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10 && !(ok); j++) {
			if (mp[i][j] == 'x') {
				copy(mp.begin(), mp.end(), s.begin());
				num = BFS(i, j, s);
				if (sum == num)
					ok = true;
			}
		}
	}
	if (ok)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}