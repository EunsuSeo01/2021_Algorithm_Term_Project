/*
 202035340 ������
 [Algorithm Term Project - DFS/BFS related topic]
 Topic - Game Map Shortest Way (���� �� �ִܰŸ� ����)

 [Problem]
 - ROR ������ �� ������ ����� �����ϸ�, ��� �� ������ ���� �ı��ϸ� �̱�� �����Դϴ�.
 - ����, �� ���� ��� �� ������ �ִ��� ���� �����ϴ� ���� �����մϴ�.

 - ĳ���ʹ� ��/��/��/�� �������� �� ĭ�� �̵� ����.
 - ���� ���� ���� maps�� �Ű������� �־��� ��, ĳ���Ͱ� ��� �� ������ �����ϱ� ����
   "�������� �ϴ� ĭ�� ������ �ּڰ�"(= �ִܰŸ�)�� return �ϵ��� solution �Լ��� �ϼ��ϴ� ����.
 - ��, ��� �� ������ ������ �� ���� ���� -1�� return.

 <���ѻ���>
 maps�� 0�� 1�θ� �̷���� n x m ũ���� 2���� �迭. (1 <= n,m <= 100)
 0�� ���� �ִ� �ڸ�, 1�� ���� ���� �ڸ�. (�� �ڸ��� 1�� �־�� �� �� �ִ�)
 n�� m�� ���� ���� ����, �ٸ� ���� ������, n�� m�� ��� 1�� ���� �Է����� �־����� �ʴ´�.
 ó���� ĳ���ʹ� ���� ���� ���� ����� (0, 0)�� ��ġ, ���� ������ ���� ���� ���� �ϴ��� (n-1, m-1)�� ��ġ�Ѵ�.
*/
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#define MAX 101
using namespace std;

int DFS(int** maps);

int n = 0, m = 0;

int main() {
	/*
		I will read a test case through reading a text file.
		Step 1. Read a input file.
	*/
	char inputFileName[30] = {};
	printf("Enter a input file name: ");
	scanf("%s", &inputFileName);

	FILE* inputFile = fopen(inputFileName, "r");
	if (inputFile == NULL) {
		printf("%s file not exist.\n", inputFileName);
		exit(0);
	}

	/*
		Construct a map.
	*/
	fscanf(inputFile, "%d %d", &n, &m);
	if (n >= MAX || m >= MAX)
		exit(0);

	int** maps = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		maps[i] = (int*)malloc(sizeof(int) * m);
	}

	/*
		Fill a map with resourses.
	*/
	printf("--------------------------------------\n[MAP]\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(inputFile, "%d", &maps[i][j]);
			printf("%d ", maps[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------------------\n\n");


	/*
		Output format.
	*/
	printf("Game Map Shortest Way : %d\n", DFS(maps));

	return 0;
}

int DFS(int** maps) {
	int row = 0, col = 0;	// initial location.

	int locationRow[4] = { 0, 0, 1, -1 }; // E W S N of Row.
	int locationCol[4] = { 1, -1, 0, 0 }; // E W S N of Col.


	/*
		Step 2 : Declare dist for storing the distance from start location(0,0) to that location.
	*/
	int** dist = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		dist[i] = (int*)malloc(sizeof(int) * m);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = 0;
		}
	}

	/*
		Step 3 : Use Stack structure for implement DFS.
	*/
	stack<pair<int, int> > s;
	s.push(make_pair(row, col));
	maps[row][col] = -1;	// Mark the visited location.

	/*
		Step 4 : Update the dist array through push and pop.
	*/
	while (!s.empty()) {
		row = s.top().first;
		col = s.top().second;

		s.pop();	// Pop the top.

		/*
			Check 4-way location(= EWSN) is valid.
		*/
		for (int i = 0; i < 4; i++) {
			int newRow = row + locationRow[i];
			int newCol = col + locationCol[i];

			/*
				Step 5 : Determine where to go through push.
				check that location is in the map.
			*/
			if (newCol >= 0 && newCol < m && newRow >= 0 && newRow < n) {
				/*
					check there is a road.(-> not blocked road = 0) & not visited (= Not -1)
				*/
				if (maps[newRow][newCol] == 1) {
					maps[newRow][newCol] = -1;			// Mark this location is visited.
					s.push(make_pair(newRow, newCol));	// Push the location.
					dist[newRow][newCol] = dist[row][col] + 1;	// Update dist array.
				}
			}
		}
	}

	/*
		Destination is not visited. -> return -1.
	*/
	if (maps[n - 1][m - 1] != -1)
		return -1;
	else {
		int shortest = dist[n - 1][m - 1] + 1;
		return shortest;
	}
}