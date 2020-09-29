#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int num, i = 0;
	vector<int> cnt(4, 0);
	string str;
	cin >> num >> str;
	for (; i < num; i++) {
		if (str[i] == '1')
			cnt[0]++;
		else if (str[i] == '2')
			cnt[1]++;
		else if (str[i] == '3')
			cnt[2]++;
		else if (str[i] == '4')
			cnt[3]++;
	}
	sort(cnt.begin(), cnt.end());
	cout << cnt[3] << " " << cnt[0] << "\n";
	return 0;
}