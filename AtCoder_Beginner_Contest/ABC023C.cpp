#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int Leng, Side, Order, Num, i = 0, l, s;
	long int ans = 0;
	cin >> Leng >> Side >> Order >> Num;
	vector<int> leng(Leng, 0), side(Side, 0), lnum(Num + 1, 0), snum(Num + 1, 0), ameX(Num), ameY(Num);
	for (; i < Num; i++) {
		scanf_s("%d%d", &ameY[i], &ameX[i]);
		leng[--ameY[i]]++;
		side[--ameX[i]]++;
	}
	for (i = 0; i < Leng; i++)
		lnum[leng[i]]++;
	for (i = 0; i < Side; i++)
		snum[side[i]]++;
	for (i = 0; i < Order + 1; i++)
		ans += lnum[i] * snum[Order - i];
	for (i = 0; i < Num; i++) {
		l = leng[ameY[i]] + side[ameX[i]];
		if (l == Order)
			ans--;
		else if (l == Order + 1)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}