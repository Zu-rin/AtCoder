#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, ok = true;
	string s, a;
	map<string, int> d;
	cin >> num >> a;
	d[a] = 1;
	for (i = 1; i < num; i++) {
		cin >> s;
		if (a[a.size() - 1] != s[0] || d[s] == 1) {
			ok = false;
			break;
		}
		d[s] = 1;
		a = s;
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}