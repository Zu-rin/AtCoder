#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j, x;
	vector<int> ab(10), ba(10);
	for (i = 0; i < 10; i++) {
		cin >> ba[i];
		ab[ba[i]] = i;
	}
	cin >> num;
	vector<int> s(num);
	for (i = 0; i < num; i++) {
		cin >> s[i];
		x = 0;
		j = 1;
		while (s[i] > 0) {
			x += ab[s[i] % 10] * j;
			j *= 10;
			s[i] /= 10;
		}
		s[i] = x;
	}
	sort(s.begin(), s.end());
	for (i = 0; i < num; i++) {
		x = 0;
		j = 1;
		while (s[i] > 0) {
			x += ba[s[i] % 10] * j;
			j *= 10;
			s[i] /= 10;
		}
		s[i] = x;
		cout << s[i] << "\n";
	}
	return 0;
}