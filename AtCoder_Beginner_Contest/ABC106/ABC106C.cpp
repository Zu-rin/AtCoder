#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int sum = 0, i = 0;
	long long k;
	string s;
	cin >> s >> k;
	while (s[i] == '1') {
		sum++;
		i++;
	}
	if (k <= sum)
		printf("1\n");
	else
		cout << s[sum] << "\n";
	return 0;
}