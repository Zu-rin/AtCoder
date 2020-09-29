#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j, m, a, ok;
	cin >> num;
	vector<int> d(num + 1);
	for (i = 1; i <= num; i++) {
		cin >> d[i];
	}
	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> a;
		ok = true;
		if (d[a] == 2019)
			continue;
		for (j = 1; j <= num; j++) {
			if (d[j] == d[a] + 1) {
				ok = false;
				break;
			}
		}
		if(ok)
			d[a]++;
	}
	for (i = 1; i <= num; i++) {
		cout << d[i] << "\n";
	}
	return 0;
}