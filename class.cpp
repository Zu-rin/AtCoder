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
	string s;
	cin >> s;
	if (s == "RRR")
		printf("3\n");
	else if (s == "SSS")
		printf("0\n");
	else if(0 <= (int)s.find("RR"))
		printf("2\n");
	else
		printf("1\n");
	int p = s.find("RR");
	return 0;
}