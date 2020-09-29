#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, a = 0, b = 0;
	string s;
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			a++;
		else
			b++;
	}
	cout << min(a, b) * 2 << "\n";
	return 0;
}