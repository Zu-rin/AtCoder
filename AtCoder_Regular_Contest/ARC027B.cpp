#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int Parent(int n, vector<int>& p) {
	if (p[n] == n)
		return n;
	return p[n] = Parent(p[n], p);
}

int main(void) {
	int num, i, j;
	string s, t;
	vector<int> p(26, 0), d(26, -1);
	for (i = 0; i < 26; i++) {
		p[i] = i;
	}
	cin >> num >> s >> t;
	for (i = 0; i < num; i++) {
		if (s[i] != t[i]) {
			if (s[i] >= '0' && s[i] <= '9') {

			}
				
		}
	}
	return 0;
}