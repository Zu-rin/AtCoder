#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int h, w, a, b, num, i, j;
	cin >> h >> w >> a >> b;
	vector<string> s(h, "");
	for (i = 0; i < b; i++) {
		for (j = 0; j < a; j++)
			s[i] += "0";
		for (; j < w; j++)
			s[i] += "1";
		cout << s[i] << "\n";
	}
	for (; i < h; i++) {
		for (j = 0; j < a; j++)
			s[i] += "1";
		for (; j < w; j++)
			s[i] += "0";
		cout << s[i] << "\n";
	}
	return 0;
}