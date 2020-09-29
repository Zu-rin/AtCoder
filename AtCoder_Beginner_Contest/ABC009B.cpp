#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i;
	cin >> num;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		cin >> d[i];
	sort(d.begin(), d.end());
	i = num - 2;
	while (d[i] == d[i + 1])
		i--;
	cout << d[i] << "\n";
	return 0;
}