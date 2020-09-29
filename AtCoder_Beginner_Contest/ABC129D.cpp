#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MIN (-1) * (1 << 30)

using namespace std;

int main(void) {
	int H, W, i = 0, j, l, sum, ans = 0;
	cin >> H >> W;
	vector<vector<int>> x(H, vector<int>(W, 0));
	vector<string> s(H);
	for (; i < H; i++)
		cin >> s[i];
	for (i = 0; i < H; i++) {
		l = 0;
		for (j = 0; j < W; j++) {
			while (j < W && s[i][j] == '.')
				j++;
			sum = j - l;
			for (; l < j; l++)
				x[i][l] = sum;
			if (j < W)
				x[i][j] = MIN;
			l = j + 1;
		}
	}
	for (j = 0; j < W; j++) {
		l = 0;
		for (i = 0; i < H; i++) {
			while (i < H && s[i][j] == '.')
				i++;
			sum = i - l;
			for (; l < i; l++)
				x[l][j] += sum;
			l = i + 1;
		}
	}
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			ans = max(ans, x[i][j]);
		}
	}
	cout << ans - 1 << "\n";
	return 0;
}