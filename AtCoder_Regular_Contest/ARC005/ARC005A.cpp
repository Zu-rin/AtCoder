#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int num, i = 0, ans = 0;
	string s, t[3] = { "TAKAHASHIKUN", "Takahashikun", "takahashikun" };
	string e[3] = { "TAKAHASHIKUN.", "Takahashikun.", "takahashikun." };
	cin >> num;
	for (i = 0; i < num; i++){
		cin >> s;
		if (s == t[0] || s == t[1] || s == t[2])
			ans++;
	}
	if (s == e[0] || s == e[1] || s == e[2])
		ans++;
	printf("%d\n", ans);
	return 0;
}