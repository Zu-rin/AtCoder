#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#define ENUM 26

using namespace std;

int main(void) {
	int num, i = 0, cons[ENUM] = {0};
	long long ans = 1;
	string str;
	cin >> num >> str;
	for (; i < num; i++)
		cons[str[i] - 'a']++;
	for (i = 0; i < ENUM; i++) {
		if (cons[i] == 0)
			continue;
		ans *= (cons[i] + 1);
		ans %= (int)pow(10, 9) + 7;
	}
	if (ans == 0)
		printf("%d\n", (int)pow(10, 9) + 6);
	else
		cout << ans - 1 << "\n";
	return 0;
}