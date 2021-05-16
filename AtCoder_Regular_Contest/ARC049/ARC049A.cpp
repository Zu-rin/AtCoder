#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j = 0;
	string s;
	cin >> s;
	vector<int> d(4);
	for (i = 0; i < 4; i++)
		cin >> d[i];
	for (i = 0; i < 4; i++) {
		for (; j < d[i]; j++) {
			cout << s[j];
		}
		cout << "\"";
	}
	for (; j < s.size(); j++)
		cout << s[j];
	cout << "\n";
	return 0;
}