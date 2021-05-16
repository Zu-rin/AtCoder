#include <iostream>
#include <vector>
#include <string>
#include <list>
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
		mp[s]++;
	}
	printf("AC x %d\n", mp["AC"]);
	printf("WA x %d\n", mp["WA"]);
	printf("TLE x %d\n", mp["TLE"]);
	printf("RE x %d\n", mp["RE"]);
	return 0;
}