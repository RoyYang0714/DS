#include <iostream>
#include <stack>
using namespace std;

#define N 100
stack<char> ans;

void mazerunner(char maze[N][N], int maze_w, int maze_h, int maze_id[N][N]);

int main()
{
	char maze[N][N];
	int maze_id[N][N];
	int maze_num;
	int maze_w;
	int maze_h;
	
	cin>>maze_num;
	
	while (maze_num > 0) {
		cin>>maze_w;
		cin>>maze_h;
		mazerunner(maze, maze_w, maze_h, maze_id);
		maze_num--;
		if (ans.empty()) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			while (!ans.empty()) {
				cout<<ans.top();
				ans.pop();
			}
		}
		cout<<endl;
	}
	return 0;
}

void mazerunner(char maze[N][N], int maze_w, int maze_h, int maze_id[N][N])
{
	int i = 0;
	int j = 0;

	for (int i = 0; i < maze_h; i++) {
		for (int j = 0; j < maze_w; j++) {
			cin>>maze[i][j];
			maze_id[i][j] = 0;
			cout<<maze[i][j]<<' ';
		}
		cout<<endl;
	}
	
	ans.push(maze[0][0]);
	maze_id[0][0] = 1;

	while (!ans.empty()) {
		if (maze_id[i+1][j] != 1 && i+1 < maze_h) {
			i++;
			ans.push(maze[i][j]);
			maze_id[i][j] = 1;
		} 
		else if (maze_id[i][j+1] != 1 && j+1 < maze_w) {
			j++;
			ans.push(maze[i][j]);
			maze_id[i][j] = 1;
		} 
		else if (maze_id[i][j-1] != 1 && j > 0) {
			j--;
			ans.push(maze[i][j]);
			maze_id[i][j] = 1;
		} 
		else if (maze_id[i-1][j] != 1 && i > 0) {
			i--;
			ans.push(maze[i][j]);
			maze_id[i][j] = 1;
		}
		if (i == maze_h - 1 && j == maze_w -1) return; 
	}
	
	return;
}
