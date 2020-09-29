#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int i, j = 0, X, Y, a = 0;
	string s;
	cin >> s >> X >> Y;
	vector<int> x, y;
	for (i = 0; i <= s.size(); i++) {
		if (i == s.size() || s[i] == 'T') {
			if (j & 1)
				y.push_back(a);
			else
				x.push_back(a);
			a = 0;
			j++;
		}
		else
			a++;
	}
	X = -abs(X - x[0]);
	Y = -abs(Y);
	vector<vector<int>> dpx(x.size() + 1, vector<int>(s.size() + 1, false)), dpy(y.size() + 1, vector<int>(s.size() + 1, false));
	dpx[1][0] = true;
	dpy[0][0] = true;
	for (i = 1; i < x.size(); i++) {
		for (j = 0; j <= s.size(); j++) {
			if (dpx[i][j]) {
				dpx[i + 1][j] = true;
				if (j + x[i] <= s.size())
					dpx[i + 1][j + x[i]] = true;
			}
		}
		X += x[i];
	}
	for (i = 0; i < y.size(); i++) {
		for (j = 0; j <= s.size(); j++) {
			if (dpy[i][j]) {
				dpy[i + 1][j] = true;
				if (j + y[i] <= s.size())
					dpy[i + 1][j + y[i]] = true;
			}
		}
		Y += y[i];
	}
	if (X < 0 || Y < 0)
		printf("No\n");
	else if (!(X & 1) && !(Y & 1) && dpx[x.size()][X >> 1] && dpy[y.size()][Y >> 1])
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}