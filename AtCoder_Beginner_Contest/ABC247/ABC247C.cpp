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

void print(int n) {
	if (n == 1) {
		printf("1");
		return;
	}
	print(n - 1);
	printf(" %d ", n);
	print(n - 1);
	return;
}

int main(void) {
	int num, i;
	cin >> num;
	print(num);
	printf("\n");
	return 0;
}