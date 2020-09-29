#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, ans = 0;
	string s;
	cin >> num >> s;
	for (i = 0; i < num - 1; i++) {
		if (s[i] != s[i + 1]) {
			ans++;
			i++;
		}
	}
	cout << ans << "\n";
	return 0;
}