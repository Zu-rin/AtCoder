#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int h, w, num, i, j = 0, a;
	cin >> h >> w >> num;
	vector<int> d(h * w);
	for (i = 1; i <= num; i++) {
		cin >> a;
		while (a > 0) {
			d[j++] = i;
			a--;
		}
	}
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++)
			printf("%d ", d[i * w + j]);
		printf("\n");
		i++;
		if (i >= h)
			break;
		for (j = w - 1; j >= 0; j--)
			printf("%d ", d[i * w + j]);
		printf("\n");
	}
	return 0;
}