#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j, k, len = 0, ans = INF;
	vector<string> d(16);
	string s, b = "ABXY";
	cin >> num >> s;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			d[i * 4 + j] = b.substr(i, 1) + b.substr(j, 1);
		}
	}
	for (i = 0; i < 16; i++) {
		for (j = i + 1; j < 16; j++) {
			len = num;
			for (k = 0; k < num - 1; k++) {
				if (s.substr(k, 2) == d[i] || s.substr(k, 2) == d[j]) {
					len--;
					k++;
				}
			}
			ans = min(ans, len);
		}
	}
	cout << ans << "\n";
	return 0;
}