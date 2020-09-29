#include <iostream>
#include <vector>
#include <string>
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
	int num, i, ok = false;
	string s;
	cin >> s;
	if (s[0] == '7' || s[1] == '7' || s[2] == '7')
		ok = true;
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}