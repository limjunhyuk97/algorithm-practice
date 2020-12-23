#include <iostream>
#include <vector>
#include <string>
#define FOR(index, start, end) for(int (index) =(start); (index)<(end); ++(index))
using namespace std;

class XYGrid {
private:
	int x;
	int y;
	char alphabet;
public:
	void InitXYGrid(int x, int y, char alpha) {
		this->x = x;
		this->y = y;
		this->alphabet = alpha;
	}
	char GetAlphabet() const{
		return alphabet;
	}
	int GetXGrid() const {
		return x;
	}
	int GetYGrid() const {
		return y;
	}
};

const int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

bool InGrid(int x, int y) {
	if (x < 0 || x>4 || y < 0 || y > 4) return false;
	else return true;
}

bool hasWord(int x, int y, const string &word, vector < vector <XYGrid> > &grid) {
	if (!InGrid(x, y)) return false;
	if (grid[x][y].GetAlphabet() != word[0]) return false;
	if (word.size() == 1) return true;
	FOR(direction, 0, 8) {
		int nextX = x + dx[direction], nextY = y + dy[direction];
		if (hasWord(nextX, nextY, word.substr(1), grid)) return true;
	}
	return false;
}

int main(void) {
	int C, N;

	cin >> C;
	cin.ignore(1, '\n');

	FOR(i, 0, C) {
		vector < vector <XYGrid> > grid(5, vector <XYGrid>(5));
		vector < vector <XYGrid> > abcgrid(26);
		FOR(j, 0, 5) {
			FOR(k, 0, 5) {
				grid[j][k].InitXYGrid(j, k, cin.get());
				abcgrid[grid[j][k].GetAlphabet() - 'A'].push_back(grid[j][k]);
			}
			cin.ignore(1, '\n');
		}

		cin >> N;
		vector <string> list(N);
		FOR(j, 0, N) {
			cin >> list[j];
		}

		FOR(j, 0, N) {
			bool flag = false;
			FOR(k, 0, abcgrid[list[j][0] - 'A'].size()) {
				if (hasWord(abcgrid[list[j][0] - 'A'][k].GetXGrid(), abcgrid[list[j][0] - 'A'][k].GetYGrid(), list[j], grid)) {
					cout << list[j] << " YES" << endl;
					flag = true;
					continue;
				}
			}
			if (!flag) cout << list[j] << " NO" << endl;
		}

	}
	
	return 0;
}
