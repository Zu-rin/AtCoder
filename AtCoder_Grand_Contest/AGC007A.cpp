#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Search(int x, int y, vector<string> &d) {
	if (y == d.size() - 1 && x == d[0].size() - 1)
		return true;
	if (x < d[0].size() - 1 && d[y][x + 1] == '#') {
		if (y < d.size() - 1 && d[y + 1][x] == '#')
			return false;
		if (y > 0 && d[y - 1][x + 1] == '#')
			return false;
		return Search(x + 1, y, d);
	}
	if (y < d.size() - 1 && d[y + 1][x] == '#'){
		if (x > 0 && d[y + 1][x - 1] == '#')
			return false;
		return Search(x, y + 1, d);
	}
	else
		return false;
}

int main(void) {
	int h, w, i;
	cin >> h >> w;
	vector<string> d(h);
	for (i = 0; i < h; i++)
		cin >> d[i];
	if (Search(0, 0, d))
		printf("Possible\n");
	else
		printf("Impossible");
	return 0;
}