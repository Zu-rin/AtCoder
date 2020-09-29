#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int num, st, ed, i = 0, sum = 0;
	string s;
	vector<int> rain(2401, 0);
	cin >> num;
	for (; i < num; i++) {
		st = 0;
		ed = 0;
		cin >> s;
		for (int j = 0; j < 4; j++) {
			st *= 10;
			ed *= 10;
			st += s[j] - '0';
			ed += s[j + 5] - '0';
		}
		st -= st % 5;
		if (ed % 5 > 0) {
			ed += 5 - (ed % 5);
			if (ed % 100 == 60)
				ed += 40;
		}
		rain[st]++;
		rain[ed]--;
	}
	for (i = 0; i <= 2400; i++) {
		if (sum == 0 && rain[i] > 0)
			st = i;
		sum += rain[i];
		if (sum == 0 && rain[i] < 0) {
			ed = i;
			for (int j = 3; j >= 0; j--) {
				s[j] = st % 10 + '0';
				s[j + 5] = ed % 10 + '0';
				st /= 10;
				ed /= 10;
			}
			cout << s << "\n";
		}
	}
	return 0;
}