#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, ok = true;
	string s;
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == 'U' || s[i] == 'D')
			continue;
		if (i & 1) {
			if (s[i] == 'R') {
				ok = false;
				break;
			}
		}
		else {
			if (s[i] == 'L') {
				ok = false;
				break;
			}
		}
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}