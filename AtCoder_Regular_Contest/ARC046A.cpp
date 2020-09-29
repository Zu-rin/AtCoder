#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int Judge(int n) {
	int a = n % 10;
	while (n > 0) {
		if (n % 10 != a)
			return false;
		n /= 10;
	}
	return true;
}

int main(void) {
	int num, i, k = 0;
	cin >> num;
	for (i = 1; i <= INF; i++) {
		if (Judge(i)) {
			k++;
			if (k == num)
				break;
		}
	}
	cout << i << "\n";
	return 0;
}