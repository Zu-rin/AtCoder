#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, a;
	ll sum = 0, ans = 0, s;
	cin >> num;
	vector<ll> d(num + 1, 0);
	for (i = 1; i <= num; i++) {
		scanf_s("%d", &a);
		sum += a;
		d[i] = sum;
	}
	sort(d.begin(), d.end());
	for (i = 0; i < num; i++) {
		s = 1;
		while (i < num && d[i] == d[i + 1]) {
			s++;
			i++;
		}
		s *= s - 1;
		ans += s >> 1;
	}
	cout << ans << "\n";
	return 0;
}