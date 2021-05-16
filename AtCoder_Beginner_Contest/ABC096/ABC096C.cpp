#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	int h, w, i = 0, j = 0;
	cin >> h >> w;
	vector<string> s(h);
	for (; i < h; i++)
		cin >> s[i];
	for (; j < h; j++) {
		for (i = 0; i < w; i++) {
			if (s[j][i] == '#') {
				if (!((j > 0 && s[j - 1][i] == '#') || (j < h - 1 && s[j + 1][i] == '#') || (i < w - 1 && s[j][i + 1] == '#')))
					break;
				while (i < w && s[j][i] == '#')
					i++;
			}
		}
		if (i < w)
			break;
	}
	if (j < h)
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}