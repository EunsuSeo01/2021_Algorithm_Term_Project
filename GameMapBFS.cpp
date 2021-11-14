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
 0�� ���� �ִ� �ڸ�, 1�� ���� ���� �ڸ�.
 n�� m�� ���� ���� ����, �ٸ� ���� ������, n�� m�� ��� 1�� ���� �Է����� �־����� �ʴ´�.
 ó���� ĳ���ʹ� ���� ���� ���� ����� (0, 0)�� ��ġ, ���� ������ ���� ���� ���� �ϴ��� (n-1, m-1)�� ��ġ�Ѵ�.
*/
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define MAX 101
int n = 0, m = 0;

int BFS(int** maps);

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

	return 0;
}