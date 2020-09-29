#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int main(void) {
	int i, a = 0;
	ll ans = 0;
	string x, s = "";
	cin >> x;
	for (i = 0; i < x.size() - 1; i++) {
		if (x[i] == 'B' && x[i + 1] == 'C') {
			s += "D";
			i++;
		}
		else
			s += x[i];
	}
	if (x.size() > 1 && x[x.size() - 2] != 'B' || x[x.size() - 1] != 'C')
		s += x[x.size() - 1];
	for (i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case 'A':
			a++;
			break;
		case 'D':
			ans += a;
			break;
		default:
			a = 0;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}