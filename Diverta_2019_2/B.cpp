#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, j, sum = 0;
	cin >> num;
	vector<int> x(num), y(num);
	map<pair<int, int>, int> mp;
	for (; i < num; i++)
		scanf_s("%d%d", &x[i], &y[i]);
	for (i = 0; i < num - 1; i++) {
		for (j = i + 1; j < num; j++) {
			if (x[i] < x[j])
				sum = max(sum, ++mp[make_pair(x[j] - x[i], y[j] - y[i])]);
			else if(x[i] > x[j])
				sum = max(sum, ++mp[make_pair(x[i] - x[j], y[i] - y[j])]);
			else
				sum = max(sum, ++mp[make_pair(0, abs(y[i] - y[j]))]);
		}
	}
	cout << num - sum << "\n";
	return 0;
}