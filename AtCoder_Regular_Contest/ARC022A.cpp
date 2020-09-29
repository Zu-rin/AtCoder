#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int i, v = 0;
	string s, ICT = "ICT", ict = "ict";
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == ICT[v] || s[i] == ict[v])
			v++;
		if (v == 3)
			break;
	}
	if (v == 3)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}