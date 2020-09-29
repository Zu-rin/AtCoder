#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int ok = true, i;
	vector<int> d(26, 0);
	string s;
	cin >> s;
	for (i = 0; i < s.size(); i++)
		d[s[i] - 'a']++;
	for (i = 0; i < 26; i++) {
		if (d[i] & 1) {
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