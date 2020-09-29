#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, sum = 0;
	string s;
	cin >> num >> s;
	vector<int> d(s.size());
	for (; i < num; i++) {
		if (s[i] == 'W')
			sum++;
		d[i] = sum;
	}
	for (sum = 0, i = num - 1; i >= 0; i--) {
		if (s[i] == 'E')
			sum++;
		d[i] += sum;
	}
	for (sum = 1 << 29, i = 0; i < num; i++)
		sum = min(sum, d[i]);
	cout << sum - 1 << "\n";
	return 0;
}