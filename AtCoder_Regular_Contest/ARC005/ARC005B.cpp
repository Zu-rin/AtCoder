#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

typedef struct vec{
	int dx, dy;
} vec;

int main(void) {
	int num, i, x, y, dx, dy;
	string k;
	vector<string> s(9), pt = { "R", "L", "U", "D", "RU", "RD", "LU", "LD" };
	vector<vec> v = { {1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1} };
	cin >> x >> y >> k;
	x--; y--;
	for (i = 0; i < 9; i++) {
		cin >> s[i];
	}
	i = 0;
	while (pt[i] != k)
		i++;
	dx = v[i].dx;
	dy = v[i].dy;
	for (i = 0; i < 4; i++) {
		cout << s[y][x];
		if (x + dx == s[0].size() || x + dx < 0)
			dx *= -1;
		if (y + dy == s.size() || y + dy < 0)
			dy *= -1;
		x += dx;
		y += dy;
	}
	cout << "\n";
	return 0;
}