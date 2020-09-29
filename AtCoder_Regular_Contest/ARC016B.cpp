#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j, ans = 0;
	cin >> num;
	vector<string> s(num);
	vector<int> a(9, 0);
	for (i = 0; i < num; i++)
		cin >> s[i];
	for (i = 0; i < num; i++) {
		for (j = 0; j < 9; j++) {
			if (s[i][j] == 'x')
				a[j]++;
			else if (s[i][j] == 'o') {
				if (i == 0 || s[i - 1][j] != 'o')
					a[j]++;
			}
		}
	}
	for (i = 0; i < 9; i++)
		ans += a[i];
	cout << ans << "\n";
	return 0;
}