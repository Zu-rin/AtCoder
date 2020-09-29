#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int i, a[3] = { 0 };
	string s;
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		a[s[i] - 'a']++;
	}
	sort(a, a + 3);
	if (abs(a[0] - a[2]) < 2)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}