#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int i, j, h, w, ok = true;
	string s;
	vector<int> d(26, 0), k(3, 0);
	cin >> h >> w;
	for (i = 0; i < h; i++) {
		cin >> s;
		for (j = 0; j < w; j++)
			d[s[j] - 'a']++;
	}
	if ((h & 1) & (w & 1)) {
		k[0] = 1;
		k[1] = (h >> 1) + (w >> 1);
	}
	else if (h & 1)
		k[1] = w >> 1;
	else if (w & 1)
		k[1] = h >> 1;
	k[2] = (h >> 1) * (w >> 1);
	for (i = 0; i < 26; i++) {
		while (k[2] > 0 && d[i] >= 4) {
			k[2]--;
			d[i] -= 4;
		}
		while (k[1] > 0 && d[i] >= 2) {
			k[1]--;
			d[i] -= 4;
		}
		while (k[0] > 0 && d[i] >= 1) {
			k[0]--;
			d[i] -= 4;
		}
		if (d[i] > 0) {
			ok = false;
			break;
		}
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}