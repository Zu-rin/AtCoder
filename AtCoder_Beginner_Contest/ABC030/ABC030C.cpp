#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int Anum, Bnum, At, Bt, i, j, t = 0, ans = 0;
	scanf_s("%d%d%d%d", &Anum, &Bnum, &At, &Bt);
	vector<int> Adep(Anum), Bdep(Bnum);
	for (i = 0; i < Anum; i++)
		scanf_s("%d", &Adep[i]);
	for (i = 0; i < Bnum; i++)
		scanf_s("%d", &Bdep[i]);
	i = 0; j = 0;
	while (true) {
		while (i < Anum && t > Adep[i])
			i++;
		if (i == Anum)
			break;
		t = Adep[i] + At;
		while (j < Bnum && t > Bdep[j])
			j++;
		if (j == Bnum)
			break;
		t = Bdep[j] + Bt;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}