#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int num, i = 0;
	double m, ans = 0;
	string s;
	cin >> num;
	for (; i < num; i++) {
		cin >> m >> s;
		if (s[0] == 'J')
			ans += m;
		else
			ans += m * 380000.0;
	}
	cout << ans << "\n";
	return 0;
}