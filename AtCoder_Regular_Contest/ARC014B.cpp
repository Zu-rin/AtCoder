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
	int num, i;
	map<string, int> mp;
	string s, a;
	cin >> num >> a;
	mp[a] = 1;
	for (i = 1; i < num; i++) {
		cin >> s;
		if (s[0] != a[a.size() - 1] || mp[s])
			break;
		mp[s] = 1;
		a = s;
	}
	if (i == num)
		printf("DRAW\n");
	else if (i & 1)
		printf("WIN\n");
	else
		printf("LOSE\n");
	return 0;
}