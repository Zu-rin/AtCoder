#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, k, q, a;
	cin >> num >> k >> q;
	vector<int> d(num + 1, 0);
	for (i = 0; i < q; i++) {
		scanf_s("%d", &a);
		d[a]++;
	}
	for (i = 1; i <= num; i++) {
		if (q - d[i] >= k)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}