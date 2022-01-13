#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

unsigned short pan[3][3], zi, zj;

unsigned char *map;

void showPan() {
	int i ,j;
	cout << "===============" << endl;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout << pan[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "===============" << endl; // << endl;
}

bool isInMap() {
	unsigned short i, j, num;
	long long index = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			index = index * 10 + pan[i][j];
		}
	}
	if (map[index] == 1) {
		cout << index << " is in map" << endl;
		return true;
	}
	map[index] = 1;
	return false;
}

bool is_ordered = false;

bool isOrdered() {
	if (is_ordered)
		return true;
	unsigned short cn = 1, i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (cn != pan[i][j])
				return false;
			cn++;
		}
	}
	is_ordered = true;
	cout << "-----is ordered--------" << endl;
	showPan();
	cout << "-----is ordered--------" << endl;
	return true;
}

inline bool actL() {
	cout << "left" << endl;
	unsigned short tmp = pan[zi][zj-1];
	pan[zi][zj-1] = pan[zi][zj];
	pan[zi][zj] = tmp;
	zj--;
	return true;
}

inline bool actR() {
	cout << "right" << endl;
	unsigned short tmp = pan[zi][zj+1];
	pan[zi][zj+1] = pan[zi][zj];
	pan[zi][zj] = tmp;
	zj++;
	return true;
}

inline bool actU() {
	cout << "up" << endl;
	unsigned short tmp = pan[zi-1][zj];
	pan[zi-1][zj] = pan[zi][zj];
	pan[zi][zj] = tmp;
	zi--;
	return true;
}

inline bool actD() {
	cout << "down" << endl;
	unsigned short tmp = pan[zi+1][zj];
	pan[zi+1][zj] = pan[zi][zj];
	pan[zi][zj] = tmp;
	zi++;
	return true;
}

void findZIndex() {
	unsigned short i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (9 == pan[i][j]) {
				zi = i;
				zj = j;
				return ;
			}
		}
	}
}

void initPan() {
	unsigned short i, j, num;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cin >> num;
			pan[i][j] = num;
		}
	}
	findZIndex();
}


/*
7 6 3
8 2 5
4 1 0
*/
void run() {
	if (isOrdered() || isInMap())
		return ;
	showPan();
	if (zi > 0) {
		actU();
		run();
		actD();

	}
	if (zi < 2) {
		actD();
		run();
		actU();
	}
	if (zj > 0) {
		actL();
		run();
		actR();
	}
	if (zj < 2) {
		actR();
		run();
		actL();
	}
}

int main(int args, char **argv) {
	map = (unsigned char *) calloc(987654322, sizeof(unsigned char));
	initPan();
	// showPan();
	run();
	return 0;
}
