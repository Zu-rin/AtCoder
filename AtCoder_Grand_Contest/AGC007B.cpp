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
	int num, i, j;
	cin >> num;
	vector<int> d(num), a(num), b(num);
	rep(i, num)
		cin >> d[i];
	rep(j, num){
		i = d[j] - 1;
		a[i] = 20001 * (i + 1);
		b[i] = 20001 * (num - i) + j;
	}
	rep(i, num - 1)
		cout << a[i] << " ";
	cout << a[i] << "\n";
	rep(i, num - 1)
		cout << b[i] << " ";
	cout << b[i] << "\n";
	return 0;
}