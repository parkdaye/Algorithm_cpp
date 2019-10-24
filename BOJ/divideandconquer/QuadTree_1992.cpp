#include <iostream>
#include <string>
using namespace std;

const int MAX = 64;
int vd[MAX + 1][MAX + 1];

void daq(int N, int x, int y) {
	if (N == 1) {
		cout << vd[x][y];
		return;
	}


	bool isSame = true;
	int first = vd[x][y];

	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (first != vd[i][j]) {
				isSame = false;
				break;
			}
		}
	}

	if (isSame) {
		cout << first;
	} else {
		cout << "(";
		daq(N / 2, x, y);
		daq(N / 2, x, y + N / 2); 
		daq(N / 2, x + N / 2, y);
		daq(N / 2, x + N / 2, y + N / 2);
		cout << ")";
	}

}

int main() {

	int N;
	cin >> N;

	string input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		for (int j = 1; j <= N; j++) {
			vd[i][j] = input[j - 1] - '0';
		}
	}

	daq(N, 1, 1);
	return 0;
}