#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int num;

void Search(string s, int ma) {
	if (s.size() == num) {
		cout << s << "\n";
		return;
	}
	int i;
	for(i = 0; i <= ma; i++) {
		char c = 'a' + i;
		Search(s + c, max(ma, i + 1));
	}
	return;
}

int main(void) {
	int i;
	string s = "a";
	cin >> num;
	Search(s, 1);
	return 0;
}