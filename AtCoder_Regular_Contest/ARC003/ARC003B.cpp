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
	cin >> num;
	vector<string> s(num);
	for (i = 0; i < num; i++) {
		cin >> s[i];
		reverse(s[i].begin(), s[i].end());
	}
	sort(s.begin(), s.end());
	for (i = 0; i < num; i++) {
		reverse(s[i].begin(), s[i].end());
		cout << s[i] << "\n";
	}
	return 0;
}