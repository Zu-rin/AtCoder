#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define X 0
#define Y 1

using namespace std;

int g[2];
queue<int> xque, yque, dque;

int BFS(int x, int y, int dep, vector<string> &m) {
	if (x == g[X] && y == g[Y])
		return dep;
	if (m[y][x - 1] == '.') {
		m[y][x - 1] = '#';
		xque.push(x - 1);
		yque.push(y);
		dque.push(dep + 1);
	}
	if (m[y][x + 1] == '.') {
		m[y][x + 1] = '#';
		xque.push(x + 1);
		yque.push(y);
		dque.push(dep + 1);
	}
	if (m[y - 1][x] == '.') {
		m[y - 1][x] = '#';
		xque.push(x);
		yque.push(y - 1);
		dque.push(dep + 1);
	}
	if (m[y + 1][x] == '.') {
		m[y + 1][x] = '#';
		xque.push(x);
		yque.push(y + 1);
		dque.push(dep + 1);
	}
	x = xque.front();
	y = yque.front();
	dep = dque.front();
	xque.pop();
	yque.pop();
	dque.pop();
	return BFS(x, y, dep, m);
}

int main(void) {
	int height, width, s[2], i = 0;
	scanf_s("%d%d%d%d%d%d", &height, &width, &s[Y], &s[X], &g[Y], &g[X]);
	g[X]--;	g[Y]--;
	vector<string> m(height);
	for (; i < height; i++)
		cin >> m[i];
	cout << BFS(s[X] - 1, s[Y] - 1, 0, m) << "\n";
	return 0;
}