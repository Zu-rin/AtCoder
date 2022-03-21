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
	int num, i, dif = 0;
	char c;
	vector<char> a;
	rep(i, 3) {
		cin >> c;
		a.push_back(c);
	}
	rep(i, 3) {
		cin >> c;
		if (a[i] != c)
			dif++;
	}
	if (dif == 2)
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}