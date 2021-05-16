#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i;
	string s;
	cin >> s;
	if (s[0] >= 'a')
		s[0] -= 'a' - 'A';
	for (i = 1; i < s.size(); i++) {
		if (s[i] < 'a')
			s[i] += 'a' - 'A';
	}
	cout << s << "\n";
	return 0;
}