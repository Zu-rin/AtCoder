#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, ma = 0;
	string s;
	map<string, int> mp;
	cin >> num;
	rep(i, num) {
		cin >> s;
		mp[s]++;
		chmax(ma, mp[s]);
	}
	for (auto itr = mp.begin(); itr != mp.end(); itr++) {
		if(itr -> second == ma)
			cout << itr->first << "\n";
	}
	return 0;
}