#include <iostream>
#include <stack>
#include <unistd.h>
using namespace std;

#define N 100

stack<char> ans;
int flag;

struct maze_tp
{
	char cont;
	int id, pi, pj;
};

int maze_judge(int p, int n);
void mazerunner(maze_tp maze[N][N], int maze_w, int maze_h);

int main()
{
	maze_tp maze[N][N];
	int maze_num;
	int maze_w;
	int maze_h;
	
	cin>>maze_num;
	
	while (maze_num > 0) {
		cin>>maze_w;
		cin>>maze_h;
		mazerunner(maze, maze_w, maze_h);
		maze_num--;
		if (ans.empty()) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			while (!ans.empty()) {
				cout<<ans.top();
				ans.pop();
			}
			cout<<endl;
		}
	}
	return 0;
}

void mazerunner(maze_tp maze[N][N], int maze_w, int maze_h)
{
	int i = 0;
	int j = 0;
	int test = 0;
	int track = 0;
	flag = 0;

	for (int i = 0; i < maze_h; i++) {
		for (int j = 0; j < maze_w; j++) {
			cin>>maze[i][j].cont;
			maze[i][j].id = 0;
			maze[i][j].pi = N;
			maze[i][j].pj = N;
			cout<<maze[i][j].cont<<' ';
		}
			
		cout<<endl;
	}
	if (maze[0][0].cont == '+' || maze[0][0].cont == '-' || maze[0][0].cont == ')' || maze[0][0].cont == '*' || maze[0][0].cont == '/') return;
	else {
		ans.push(maze[0][0].cont);
		maze[0][0].id = 1;
	}
	while (1) {
		usleep(500);
		cout<<ans.top();
		//cout<<' '<<i<<' '<<j<<' ';
		
		if (maze[i+1][j].id != 1 && i+1 < maze_h && maze[i+1][j].pi != i && maze[i+1][j].pj != j) {
			maze[i+1][j].id = 1;
			
			test = maze_judge (maze[i][j].cont, maze[i+1][j].cont);

			if (test == 1) {
				i++;
				ans.push(maze[i][j].cont);
				maze[i][j].id = 1;
				maze[i][j].pi = i-1;
				maze[i][j].pj = j;
			}
			test = 0; 
		} 
		else if (maze[i][j+1].id != 1 && j+1 < maze_w && maze[i][j+1].pi != i && maze[i][j+1].pj != j) {
			maze[i][j+1].id = 1;

			test = maze_judge (maze[i][j].cont, maze[i][j+1].cont);

			if (test == 1) {
				j++;
				ans.push(maze[i][j].cont);
				maze[i][j].id = 1;
				maze[i][j].pi = i;
				maze[i][j].pj = j-1;
			}
			test = 0;
		} 
		else if (maze[i][j-1].id != 1 && j > 0 && maze[i][j-1].pi != i && maze[i][j-1].pj != j) {
			maze[i][j-1].id = 1;
			
			test = maze_judge (maze[i][j].cont, maze[i][j-1].cont);

			if (test = 1) {
				j--;
				ans.push(maze[i][j].cont);
				maze[i][j].id = 1;
				maze[i][j].pi = i;
				maze[i][j].pj = j+1;
			}
			test = 0;
		} 
		else if (maze[i-1][j].id != 1 && i > 0 && maze[i-1][j].pi != i && maze[i-1][j].pj != j) {
			maze[i-1][j].id = 1;

			test = maze_judge (maze[i][j].cont, maze[i-1][j].cont);

			if (test = 1) {
				i--;
				ans.push(maze[i][j].cont);
				maze[i][j].pi = i+1;
				maze[i][j].pj = j;				
			} 
			test = 0;
		}
		else if (i == 0 && j == 0) {
			ans.pop();
			i = maze[i][j].pi;
			j = maze[i][j].pj;
			return;
		}
		else {
		//	cout<<endl;
			ans.pop();
			maze[i][j].id = 0;
			i = maze[i][j].pi;
			j = maze[i][j].pj;
		}
		if (i == maze_h-1  && j == maze_w - 1) {
			if (flag == 0) return;
			else {
				ans.pop();
				maze[i][j].id = 0;
				i = maze[i][j].pi;
				j = maze[i][j].pj;
			}
		}
	}
	
	return;
}

int maze_judge (int p, int n)
{
	int test = 0;
	if (p == '(') {
		if (n != ')' && n != '+' && n != '-' && n != '*' && n != '/') {
			test = 1;
			flag++;
		}
	}
	else if (p == ')') {
		if (flag != 0 && n != '(') {
			test = 1;
			flag--;
		}
	}
	else if (p == '+' || p == '-' || p == '*' || p == '/') {
		if (n != '+' && n != '-' && n != '*' && n != '/' && n != ')') test = 1;
	}
	else{
		if (n == '(') test = 0;
		else if (n == ')' && flag == 0) test = 0;
		else test = 1;
	}
	return test;
}