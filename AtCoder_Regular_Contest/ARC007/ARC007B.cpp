#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j, m, a, b = 0;
	cin >> num >> m;
	vector<int> d(num + 1);
	for (i = 0; i <= num; i++) {
		d[i] = i;
	}
	for (i = 0; i < m; i++) {
		cin >> a;
		d[b] = d[a];
		d[a] = 0;
		b = a;
	}
	for (i = 1; i <= num; i++) {
		for (j = 0; j <= num; j++) {
			if (d[j] == i) {
				cout << j << "\n";
				break;
			}
		}
	}
	return 0;
}