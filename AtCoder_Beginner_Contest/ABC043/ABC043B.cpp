#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int i, j;
	string s;
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == 'B') {
			for (j = i - 1; j >= 0; j--) {
				if (s[j] != 'x') {
					s[j] = 'x';
					break;
				}
			}
			s[i] = 'x';
		}
	}
	for (i = 0; i < s.size(); i++) {
		if (s[i] != 'x')
			cout << s[i];
	}
	cout << "\n";
	return 0;
}