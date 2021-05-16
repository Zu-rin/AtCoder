#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i;
	cin >> num;
	vector<pair<int, int>> d(num);
	for (i = 0; i < num; i++) {
		cin >> d[i].first;
		d[i].second = i + 1;
	}
	sort(d.begin(), d.end());
	for (i = num - 1; i >= 0; i--)
		cout << d[i].second << "\n";
	return 0;
}