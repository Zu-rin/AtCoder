#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int i, num, snum, l = 1, r;
	string s;
	cin >> num >> snum >> s;
	s = "x" + s + "x";
	r = num;
	vector<string> spl(snum), drct(snum);
	for (i = 0; i < snum; i++)
		cin >> spl[i] >> drct[i];
	for (i = snum - 1; i >= 0; i--) {
		if (drct[i] == "L") {
			if (s[l] == spl[i][0])
				l++;
			if (s[r + 1] == spl[i][0])
				r++;
		}
		else {
			if (s[r] == spl[i][0])
				r--;
			if (s[l - 1] == spl[i][0])
				l--;
		}
	}
	cout << r - l + 1 << "\n";
	return 0;
}