#include<iostream>
#include<stdio.h>
using namespace std;
int m = 2;
int n = 2;
int path = 0;
int mat[20][20];
int tot_paths = 0;
bool visited[20][20] = {0, };
int printpaths(int x, int y)
{
	if (x == m - 1 && y == n - 1)
	{
		path = path + 1;
		return path;

	}
	if (x >= 0 && x < m && y >= 0 && y < n && visited[x][y] == false)
	{
		visited[x][y] = true;
		printpaths(x + 1, y);
		printpaths(x, y + 1);
		printpaths(x + 1, y + 1);
		visited[x][y] = false;
	}
	return path;

}


void main()
{
	int mat[20][20];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
		cout << "\n";
	}
	 tot_paths = printpaths(0, 0);
	 cout << tot_paths;
}