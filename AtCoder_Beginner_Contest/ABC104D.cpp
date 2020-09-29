#include <iostream>
#include <vector>
#include <string>
#define MOD 1000000007

using namespace std;
typedef long long ll;

int main(void) {
	int i;
	string s;
	cin >> s;
	vector<vector<ll>> d(s.size() + 1, vector<ll>(4, 0));
	d[0][0] = 1;
	for (i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case 'A':
			d[i + 1][1] = d[i][0];
			break;
		case 'B':
			d[i + 1][2] = d[i][1];
			break;
		case 'C':
			d[i + 1][3] = d[i][2];
			break;
		case '?':
			d[i + 1][0] = d[i][0] << 1;
			d[i + 1][1] = d[i][0] + (d[i][1] << 1);
			d[i + 1][2] = d[i][1] + (d[i][2] << 1);
			d[i + 1][3] = d[i][2] + (d[i][3] << 1);
			break;
		}
		d[i + 1][0] += d[i][0];
		d[i + 1][1] += d[i][1];
		d[i + 1][2] += d[i][2];
		d[i + 1][3] += d[i][3];
		d[i + 1][0] %= MOD;
		d[i + 1][1] %= MOD;
		d[i + 1][2] %= MOD;
		d[i + 1][3] %= MOD;
	}
	cout << d[s.size()][3] << "\n";
	return 0;
}