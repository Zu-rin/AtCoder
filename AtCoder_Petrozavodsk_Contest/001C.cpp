#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int Judge(int n) {
	string s;
	printf("%d\n", n);
	cin >> s;
	if (s[0] == 'V')
		return 0;
	if (s[0] == 'M')
		return 1;
	else
		return 2;
}

int Judge(int n, string &s) {
	if (s[n] == '0')
		return 0;
	else if (s[n] == '1')
		return 1;
	else
		return 2;
}

int main(void) {
	int num, l = 0, r, p;
	cin >> num;
	vector<int> d(num, 0);
	d[0] = Judge(0);
	if (d[0] == 0)
		return 0;
	r = num - 1;
	d[r] = Judge(r);
	if (d[r] == 0)
		return 0;
	while (l != r) {
		p = (l + r) >> 1;
		d[p] = Judge(p);
		if (d[p] == 0)
			break;
		if ((p - l) & 1) {
			if (d[p] != d[l])
				l = p;
			else
				r = p;
		}
		else {
			if (d[p] != d[l])
				r = p;
			else
				l = p;
		}
	}
	return 0;
}