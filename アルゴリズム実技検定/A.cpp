#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, a, b, i;
	cin >> num >> a >> b;
	cout << min(num * a, b) << "\n";
	return 0;
}