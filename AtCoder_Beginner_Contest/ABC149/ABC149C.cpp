#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j;
	cin >> num;
	vector<int> d(min(2 * num, 100004), 1);
	for (i = 2; i < d.size(); i++) {
		if (d[i]) {
			for (j = i << 1; j < d.size(); j += i) {
				d[j] = 0;
			}
		}
	}
	for (i = num; d[i] == 0; i++) {}
	cout << i << "\n";
	return 0;
}