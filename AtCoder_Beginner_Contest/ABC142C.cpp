#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, a;
	cin >> num;
	vector<int> d(num + 1);
	for (i = 1; i <= num; i++) {
		cin >> a;
		d[a] = i;
	}
	for (i = 1; i <= num; i++)
		cout << d[i] << " ";
	cout << "\n";
	return 0;
}