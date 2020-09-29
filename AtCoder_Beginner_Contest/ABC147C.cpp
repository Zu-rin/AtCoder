#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int Pow(int n, int k) {
	int i, ans = 1;
	for (i = 0; i < k; i++) {
		ans *= n;
	}
	return ans;
}

int main(void) {
	int num, i, j, ans = 0, a, b, ok;
	cin >> num;
	vector<int> l(num);
	vector<list<pair<int, int>>> d(num);
	for (i = 0; i < num; i++) {
		cin >> l[i];
		for (j = 0; j < l[i]; j++) {
			cin >> a >> b;
			d[i].push_back(make_pair(a, b));
		}
	}
	for (i = 1; i < Pow(2, num); i++) {
		ok = true;
		for (j = 0; j < num && ok; j++) {
			if (i & (1 << j)) {
				for (auto itr = d[j].begin(); itr != d[j].end(); itr++) {
					a = (*itr).first - 1;
					if ((*itr).second) {
						if (!(i & (1 << a))) {
							ok = false;
							break;
						}
					}
					else {
						if (i & (1 << a)) {
							ok = false;
							break;
						}
					}
				}
			}
		}
		if (ok) {
			a = 0;
			for (j = 1; j <= i; j <<= 1) {
				if (i & j)
					a++;
			}
			ans = max(ans, a);
		}
	}
	cout << ans << "\n";
	return 0;
}