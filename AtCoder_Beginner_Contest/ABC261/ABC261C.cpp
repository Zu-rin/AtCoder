#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
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
	string s;
	map<string, int> mp;
	cin >> num;
	rep(i, num) {
		cin >> s;
		if (mp[s]) {
			cout << s;
			printf("(%d)\n", mp[s]);
		}
		else
			cout << s << "\n";
		mp[s]++;
	}
	return 0;
}