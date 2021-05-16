#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main(void) {
	int i, j, num, buf;
	long long ans = 1;
	vector<int> pri = { 2 }, d = { 0 };
	cin >> num;
	for (i = 3; i <= num; i+=2) {;
		j = 0;
		while (j < pri.size() && i % pri[j] != 0)
			j++;
		if (j == pri.size()) {
			pri.push_back(i);
			d.push_back(0);
		}
	}
	for (i = 0; i < pri.size(); i++) {
		buf = 1;
		while (num / buf >= 1) {
			buf *= pri[i];
			d[i] += num / buf;
		}
	}
	for (i = 0; i < d.size(); i++) {
		ans *= d[i] + 1;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}