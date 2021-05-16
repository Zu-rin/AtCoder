#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int num, len, i = 0;
	long long ans = 0, sum = 0;
	cin >> num >> len;
	vector<int> a(num + 1, 0);
	for (; i < num; i++)
		scanf_s("%d", &a[i]);
	for (i = 0; i < len; i++)
		sum += a[i];
	for (i = 0; i < num - len + 1; i++) {
		ans += sum;
		sum -= a[i];
		sum += a[i + len];
	}
	cout << ans << "\n";
	return 0;
}