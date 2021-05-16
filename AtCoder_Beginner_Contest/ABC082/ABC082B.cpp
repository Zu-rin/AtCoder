#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string s, t, x = "";
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	for (int i = t.size() - 1; i >= 0; i--) {
		x += t[i];
	}
	if (s < x)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}