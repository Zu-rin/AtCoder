#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, a;
	string s;
	cin >> num;
	vector<pair<string, int>> d(num);
	map<int, int> pos;
	for (; i < num; i++) {
		cin >> d[i].first >> d[i].second;
		d[i].second = 100 - d[i].second;
		pos[d[i].second] = i;
	}
	sort(d.begin(), d.end());
	for (i = 0; i < num; i++)
		cout << pos[d[i].second] + 1 << "\n";
	return 0;
}