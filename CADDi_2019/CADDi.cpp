#include <iostream>
#include <vector>
using namespace std;

int Bestpair(const vector<int> &R, const vector<int> &P, const vector<int> &A, const vector<int> &B, const vector<int> &S, const vector<int> &X) {
	int bestPair, i = 0;
	long long bestPoint = 0, pt;
	for (; i < 100000; i++) {
		if (X[A[i]] > 0 || X[B[i]] > 0)
			continue;
		pt = P[A[i]] + P[B[i]] + S[i] - (R[A[i]] * R[B[i]]);
		if (pt > bestPoint) {
			bestPair = i;
			bestPoint = pt;
		}
	}
	return bestPair;
}

int Searchmin(const vector<int> &R, const vector<int> &P, const vector<int> &S, const vector<int> &X) {
	int minball, min = 200, i = 0;
	for (; i < 1000; i++) {
		if (X[i] > 0)
			continue;
		if (min > R[i]) {
			minball = i;
			min = R[i];
		}
	}
	return minball;
}

int main(void) {
	//入力処理
	int L, N, M, i, left, right, maxX, maxY, maxZ = 1000, bestPair, mRY = 0, mRZ = 0, failY, failZ, minball;
	cin >> L >> N >> M;
	vector<int> R(N), P(N), A(M), B(M), Dist(M), S(M);
	vector<int> X(N, -1), Y(N, -1), Z(N, -1);
	for (i = 0; i < N; i++)
		cin >> R[i] >> P[i];
	for (i = 0; i < M; i++) {
		cin >> A[i] >> B[i] >> Dist[i] >> S[i];
		A[i]--; B[i]--;
	}

	while (maxZ) {
		maxY = 1000;
		while (maxY) {
			maxX = 1000;
			while (maxX) {
				failY = 0;
				failZ = 0;
				//2つの球+組み合わせポイントで最大のものを探す。
				bestPair = Bestpair(R, P, A, B, S, X);

				left = A[bestPair];
				right = B[bestPair];

				if (maxZ >= R[left] << 1) {
					if (maxY >= R[left] << 1) {
						if (maxX >= R[left] << 1) {
							X[left] = maxX - R[left];
							Y[left] = maxY - R[left];
							Z[left] = maxZ - R[left];
							maxX = X[left] - R[left];
							if (mRY < R[left])
								mRY = R[left];
						}
						else {
							minball = Searchmin(R, P, S, X);
							if (maxX >= R[minball] << 1 && maxY >= R[minball] << 1 && maxZ >= R[minball] << 1) {
								X[minball] = maxX - R[minball];
								Y[minball] = maxY - R[minball];
								Z[minball] = maxY - R[minball];
								maxX = X[minball] - R[minball];
								if (mRY < R[minball])
									mRY = R[minball];
							}
							break;
						}
					}
					else {
						failY = 1;
						break;
					}
				}
				else {
					failZ = 1;
					break;
				}

				if (maxZ >= R[right] << 1) {
					if (maxY >= R[right] << 1) {
						if (maxX >= R[right] << 1) {
							X[right] = maxX - R[right];
							Y[right] = maxY - R[right];
							Z[right] = maxZ - R[right];
							maxX = X[right] - R[right];
							if (mRY < R[right])
								mRY = R[right];
						}
						else {
							minball = Searchmin(R, P, S, X);
							if (maxX >= R[minball] << 1 && maxY >= R[minball] << 1 && maxZ >= R[minball] << 1) {
								X[minball] = maxX - R[minball];
								Y[minball] = maxY - R[minball];
								Z[minball] = maxY - R[minball];
								maxX = X[minball] - R[minball];
								if (mRY < R[minball])
									mRY = R[minball];
							}
							break;
						}
					}
					else {
						failY = 1;
						break;
					}
				}
				else {
					failZ = 1;
					break;
				}
			}
			if (mRZ < mRY)
				mRZ = mRY;
			if (failY == 1 || failZ == 1)
				break;
			maxY -= mRY << 1;
			mRY = 0;
		}
		if (failZ == 1)
			break;
		maxZ -= mRZ << 1;
		mRZ = 0;
	}


	//全球を出力する
	for (int i = 0; i < N; i++)
		printf("%d %d %d\n", X[i], Y[i], Z[i]);
	//cout << X[i] << " " << Y[i] << " " << Z[i] << "\n";
	return 0;
}