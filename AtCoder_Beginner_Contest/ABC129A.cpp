#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> d(3);
	cin >> d[0] >> d[1] >> d[2];
	sort(d.begin(), d.end());
	cout << d[0] + d[1] << "\n";
	return 0;
}