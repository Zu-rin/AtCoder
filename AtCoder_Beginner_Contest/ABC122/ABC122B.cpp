#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;
	int num, max = 0;
	for (int i = 0; i < str.size(); i++) {
		num = 0;
		while (str[i] == 'A' || str[i] == 'T' || str[i] == 'C' || str[i] == 'G') {
			num++;
			i++;
		}
		if (num > max)
			max = num;
	}
	cout << max << "\n";
	return 0;
}