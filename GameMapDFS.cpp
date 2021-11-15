/*
 202035340 서은수
 [Algorithm Term Project - DFS/BFS related topic]
 Topic - Game Map Shortest Way (게임 맵 최단거리 문제)

 [Problem]
 - ROR 게임은 두 팀으로 나누어서 진행하며, 상대 팀 진영을 먼저 파괴하면 이기는 게임입니다.
 - 따라서, 각 팀은 상대 팀 진영에 최대한 빨리 도착하는 것이 유리합니다.

 - 캐릭터는 동/서/남/북 방향으로 한 칸씩 이동 가능.
 - 게임 맵의 상태 maps가 매개변수로 주어질 때, 캐릭터가 상대 팀 진영에 도착하기 위해
   "지나가야 하는 칸의 개수의 최솟값"(= 최단거리)을 return 하도록 solution 함수를 완성하는 문제.
 - 단, 상대 팀 진영에 도착할 수 없을 때는 -1을 return.

 <제한사항>
 maps는 0과 1로만 이루어진 n x m 크기의 2차원 배열. (1 <= n,m <= 100)
 0은 벽이 있는 자리, 1은 벽이 없는 자리. (그 자리에 1이 있어야 갈 수 있다)
 n과 m은 서로 같을 수도, 다를 수도 있지만, n과 m이 모두 1인 경우는 입력으로 주어지지 않는다.
 처음에 캐릭터는 게임 맵의 좌측 상단인 (0, 0)에 위치, 상대방 진영은 게임 맵의 우측 하단인 (n-1, m-1)에 위치한다.
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