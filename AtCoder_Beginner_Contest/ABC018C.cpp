#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	int height, width, K, i = 0, j, size = 0, ans = 0;
	string map;
	cin >> height >> width >> K;
	vector<vector<int>> num(height, vector<int>(width, 0));
	for (; i < height; i++) {
		cin >> map;
		for (j = 0; j < width; j++) {
			if (map[j] == 'x')
				num[i][j] = -1;
		}
	}
	if (K << 1 > height || K << 1 > width) {
		cout << "0\n";
		return 0;
	}
	K--;
	while (size < K) {
		for (i = 1; i < height - 1; i++) {
			for (j = 1; j < width - 1; j++) {
				if (num[i][j] == -1)
					continue;
				if (num[i - 1][j] >= size && num[i + 1][j] >= size && num[i][j - 1] >= size && num[i][j + 1] >= size)
					num[i][j]++;
			}
		}
		size++;
	}
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (num[i][j] == K)
				ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}