#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int a, b;
	cin >> a >> b;
	cout << max(a + b, max(a - b, a * b)) << "\n";
	return 0;
}