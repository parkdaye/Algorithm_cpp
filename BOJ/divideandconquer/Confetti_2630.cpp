#include <iostream>
using namespace std;

const int MAX = 128;
int paper[MAX + 1][MAX + 1];
int white = 0;
int blue = 0;

void daq(int N, int x, int y) {
	bool isSame = true;

	if (N == 1) {
		if (paper[x][y] == 0) white++;
		else blue++;
		return;
	}

	int first = paper[x][y];
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (first != paper[i][j])
				isSame = false;
		}
	}


	if (isSame) {
		if (first == 0) white++;
		else blue++;
	} else {
		daq(N / 2, x, y);
		daq(N / 2, x + N / 2, y);
		daq(N / 2, x, y + N / 2);
		daq(N / 2, x + N / 2, y + N / 2);
	}
}

int main() {
	
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> paper[i][j];
		}
	}

	daq(N, 1, 1);
	
	cout << white << '\n' << blue;
	return 0;
}