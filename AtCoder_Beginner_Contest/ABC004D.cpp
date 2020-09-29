#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int R, G, B, rl, rr, gl, gr, bl, br, ans = 0;
	scanf_s("%d%d%d", &R, &G, &B);

	rl = (R >> 1) + (R & 1);
	rr = R >> 1;
	gl = (G >> 1) + (G & 1);
	gr = G >> 1;
	bl = (B >> 1) + (B & 1);
	br = B >> 1;
	ans += rl * (rl + 1) / 2;
	ans += rr * (rr + 1) / 2;
	ans += gl * (gl + 1) / 2;
	ans += gr * (gr + 1) / 2;
	ans += bl * (bl + 1) / 2;
	ans += br * (br + 1) / 2;
	cout << ans << "\n";
	return 0;
}