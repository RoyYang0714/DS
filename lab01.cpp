#include <iostream>
#include <stack>
#include <unistd.h>
using namespace std;

#define N 100

stack<char> ans;

struct maze_tp
{
	char cont;
	int id, r, d, l, u;
};

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
	int flag = 0;

	for (int i = 0; i < maze_h; i++) {
		for (int j = 0; j < maze_w; j++) {
			cin>>maze[i][j].cont;
			maze[i][j].id = 0;
			maze[i][j].u = 0;
			maze[i][j].d = 0;
			maze[i][j].l = 0;
			maze[i][j].r = 0;
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
		if (maze[i+1][j].id != 1 && i+1 < maze_h && maze[i][j].d != 1) {
			maze[i][j].d = 1;
			if (maze[i][j].cont == '(') {
				if (maze[i+1][j].cont != ')' && maze[i+1][j].cont != '+' && maze[i+1][j].cont != '-' && maze[i+1][j].cont != '*' && maze[i+1][j].cont != '/') {
					test = 1;
					flag++;
				}
			} 
			else if (maze[i][j].cont == ')') {
				if (flag != 0 && maze[i+1][j].cont != '(') {
					test = 1;
					flag--;
				}
			}
			else if (maze[i][j].cont == '+' || maze[i][j].cont == '-' || maze[i][j].cont == '*' || maze[i][j].cont == '/') {
				if (maze[i+1][j].cont != '+' && maze[i+1][j].cont != '-' && maze[i+1][j].cont != '*' && maze[i+1][j].cont != '/' && maze[i+1][j].cont != ')') test = 1;
			}
			else{
				if (maze[i+1][j].cont == '(') test = 0;
				else if (maze[i+1][j].cont == ')' && flag == 0) test = 0;
				else test = 1;
			}

			if (test == 1) {
				i++;
				ans.push(maze[i][j].cont);
				maze[i][j].id = 1;
			}
			test = 0; 
		} 
		else if (maze[i][j+1].id != 1 && j+1 < maze_w && maze[i][j].r != 1) {
			maze[i][j].r = 1;
			if (maze[i][j].cont == '(') {
				if (maze[i][j+1].cont != ')' && maze[i][j+1].cont != '+' && maze[i][j+1].cont != '-' && maze[i][j+1].cont != '*' && maze[i][j+1].cont != '/') {
					test = 1;
					flag++;
				}
			} 
			else if (maze[i][j].cont == ')') {
				if (flag != 0 && maze[i][j+1].cont != '(') {
					test = 1;
					flag--;
				}
			}
			else if (maze[i][j].cont == '+' || maze[i][j].cont == '-' || maze[i][j].cont == '*' || maze[i][j].cont == '/') {
				if (maze[i][j+1].cont != '+' && maze[i][j+1].cont != '-' && maze[i][j+1].cont != '*' && maze[i][j+1].cont != '/' && maze[i][j+1].cont != ')') test = 1;
			}
			else{
				if (maze[i+1][j].cont == '(') test = 0;
				else if (maze[i+1][j].cont == ')' && flag == 0) test = 0;
				else test = 1;
			}

			if (test == 1) {
				j++;
				ans.push(maze[i][j].cont);
				maze[i][j].id = 1;
			}
			test = 0;
		} 
		else if (maze[i][j-1].id != 1 && j > 0 && maze[i][j].l != 1) {
			maze[i][j].l = 1;
			if (maze[i][j].cont == '(') {
				if (maze[i][j-1].cont != ')' && maze[i][j-1].cont != '+' && maze[i][j-1].cont != '-' && maze[i][j-1].cont != '*' && maze[i][j-1].cont != '/') {
					test = 1;
					flag++;
				}
			} 
			else if (maze[i][j].cont == ')') {
				if (flag != 0 && maze[i][j-1].cont != '(') {
					test = 1;
					flag--;
				}
			}
			else if (maze[i][j].cont == '+' || maze[i][j].cont == '-' || maze[i][j].cont == '*' || maze[i][j].cont == '/') {
				if (maze[i][j-1].cont != '+' && maze[i][j-1].cont != '-' && maze[i][j-1].cont != '*' && maze[i][j-1].cont != '/' && maze[i][j-1].cont != ')') test = 1;
			}
			else{
				if (maze[i+1][j].cont == '(') test = 0;
				else if (maze[i+1][j].cont == ')' && flag == 0) test = 0;
				else test = 1;
			}

			if (test = 1) {
				j--;
				ans.push(maze[i][j].cont);
				maze[i][j].id = 1;
			}
			test = 0;
		} 
		else if (maze[i-1][j].id != 1 && i > 0 && maze[i][j].u != 1) {
			maze[i][j].u = 1;
			if (maze[i][j].cont == '(') {
				if (maze[i-1][j].cont != ')' && maze[i-1][j].cont != '+' && maze[i-1][j].cont != '-' && maze[i-1][j].cont != '*' && maze[i-1][j].cont != '/') {
					test = 1;
					flag++;
				}
			} 
			else if (maze[i][j].cont == ')') {
				if (flag != 0 && maze[i-1][j].cont != '(') {
					test = 1;
					flag--;
				}
			}
			else if (maze[i][j].cont == '+' || maze[i][j].cont == '-' || maze[i][j].cont == '*' || maze[i][j].cont == '/') {
				if (maze[i-1][j].cont != '+' && maze[i-1][j].cont != '-' && maze[i-1][j].cont != '*' && maze[i-1][j].cont != '/' && maze[i-1][j].cont != ')') test = 1;
			}
			else{
				if (maze[i+1][j].cont == '(') test = 0;
				else if (maze[i+1][j].cont == ')' && flag == 0) test = 0;
				else test = 1;
			}

			if (test = 1) {
				i--;
				ans.push(maze[i][j].cont);
				maze[i][j].id = 1;
			} 
			test = 0;
		}
		if (i == maze_h-1  && j == maze_w - 1) {
			if (flag == 0) return;
			else {
				if (maze[i-1][j].d == 1) i--;
				else if ((maze[i][j-1].r == 1)) j--;
			}
		}
		else if (maze[i][j].d && maze[i][j].r && maze[i][j].l && maze[i][j].u) {
			ans.pop();
			if (i > 0 && (maze[i-1][j].d == 1)) i--;
			else if (i+1 < maze_h && (maze[i+1][j].u == 1)) i++;
			else if (j > 0 && (maze[i][j-1].r == 1)) j--;
			else if (j+1 < maze_w && (maze[i][j+1].l == 1)) j++;
		}
		if (i == 0 && j == 0 && maze[i][j].r == 1 && maze[i][j].d == 1) {
			ans.pop();
			return;
		}
		cout<<ans.top();
	}
	
	return;
}
