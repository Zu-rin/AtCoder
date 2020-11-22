#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i;
	string s, t = "";
	cin >> num >> s;
	for (char c : s) {
		t += c;
		while (t.size() >= 3 && t.substr(t.size() - 3) == "fox") {
			t.erase(t.size() - 3);
		}
	}
	cout << t.size() << "\n";
	return 0;
}