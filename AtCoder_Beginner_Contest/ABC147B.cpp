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
	cin >> s;
	num = s.size();
	for (i = 0; i < num / 2; i++) {
		if (s[i] != s[num - i - 1])
			ans++;
	}
	cout << ans << "\n";
	return 0;
}