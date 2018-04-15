#include <iostream>
#include <stack>
using namespace std;

#define N 100

stack<char> ans;
int flag;

struct maze_tp
{
	char cont;
	int id, pi, pj, r, d, l, u;
};

int maze_judge(int p, int n);
void mazerunner(maze_tp maze[N][N], int maze_w, int maze_h);

int main()
{
	maze_tp maze[N][N];
	int maze_num;
	int maze_w;
	int maze_h;
	char sol[10000];
	int sol_size;
	stack<char> itp;
	int itp_f;
	
	cin>>maze_num;
	
	while (maze_num > 0) {
		cin>>maze_w;
		cin>>maze_h;
		mazerunner(maze, maze_w, maze_h);
		maze_num--;
		if (ans.empty()) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			sol_size = ans.size();
			for (int i = 0; !ans.empty(); i++) {
				sol[i] = ans.top();
				ans.pop();
			}
			for (int i = sol_size-1; i >= 0; i--) {
				if (i == 0) {
					if (sol[i] == ')') cout<<' '<<sol[i];
					else cout<<sol[i];
				}
				else {
					if (sol[i] >= '1' && sol[i] <= '9') cout<<sol[i];
					else {
						if (sol[i] == '(') {
							cout<<sol[i];
							cout<<' ';
						}
						else if (sol[i] == ')') {
							cout<<' ';
							cout<<sol[i];
						}
						else {
							cout<<' ';
							cout<<sol[i];
							cout<<' ';
						}
					}
				}
			}
			cout<<endl;
			itp_f = 0;
			for (int i = sol_size-1; i >= 0; i--) {
				if (sol[sol_size-1] == '(' && i == sol_size-1) itp.push(sol[i]);
				if(sol[i] != '(' && sol[i] != ')' && sol[i] != '+' && sol[i] != '-' && sol[i] != '*' && sol[i] != '/')
					cout<<sol[i];
				else {
					if (itp.empty()) {
						itp.push(sol[i]);
						cout<<' ';
					} else {
						if (sol[i] == '(')	{
							itp.push(sol[i]);
						}
						else if (sol[i] == ')') {
							while (itp.top() != '(') {
								cout<<' '<<itp.top();
								itp.pop();
							}
							itp.pop();
						}
						else if (sol[i] == '*' || sol[i] == '/') {
							while (!itp.empty() && itp.top() != '+' && itp.top() != '-' && itp.top() != '(')
							{ 
								cout<<' '<<itp.top();
								itp.pop();
							}
							itp.push(sol[i]);
							cout<<' ';
						}
						else if (sol[i] == '+' || sol[i] == '-') {
							while (!itp.empty() && itp.top() != '(' ) {
								cout<<' '<<itp.top();
								itp.pop();
							}
							itp.push(sol[i]);
							cout<<' ';
						}
					}
				}
			}
			while (!itp.empty()){
				cout<<' '<<itp.top();
				itp.pop();
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
	int i_tmp;
	int j_tmp;
	int test = 0;
	int track = 0;
	flag = 0;

	for (int i = 0; i < maze_h; i++) {
		for (int j = 0; j < maze_w; j++) {
			cin>>maze[i][j].cont;
			maze[i][j].id = 0;
			maze[i][j].pi = 0;
			maze[i][j].pj = 0;
			maze[i][j].d = 0;
			maze[i][j].u = 0;
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
		if (maze[0][0].cont == '(') flag++;
	}
	while (1) {		
		if (maze[i+1][j].id != 1 && i+1 < maze_h && maze[i][j].d != 1) {	 

			maze[i][j].d = 1;

			test = maze_judge (maze[i][j].cont, maze[i+1][j].cont);

			if (test == 1) {
				i++;
				ans.push(maze[i][j].cont);
				maze[i][j].id = 1;
				maze[i][j].d = 0;
				maze[i][j].u = 0;
				maze[i][j].l = 0;
				maze[i][j].r = 0;
				maze[i][j].pi = i-1;
				maze[i][j].pj = j;
			}
			test = 0; 
		} 
		else if (maze[i][j+1].id != 1 && j+1 < maze_w && maze[i][j].r != 1) {

			maze[i][j].r = 1;

			test = maze_judge (maze[i][j].cont, maze[i][j+1].cont);

			if (test == 1) {
				j++;
				ans.push(maze[i][j].cont);
				maze[i][j].d = 0;
				maze[i][j].u = 0;
				maze[i][j].l = 0;
				maze[i][j].r = 0;
				maze[i][j].pi = i;
				maze[i][j].pj = j-1;
				maze[i][j].id = 1;
			}
			test = 0;
		} 
		else if (maze[i][j-1].id != 1 && j > 0 && maze[i][j].l != 1) {
			maze[i][j].l = 1;
			
			test = maze_judge (maze[i][j].cont, maze[i][j-1].cont);

			if (test == 1) {
				j--;
				ans.push(maze[i][j].cont);
				maze[i][j].d = 0;
				maze[i][j].u = 0;
				maze[i][j].l = 0;
				maze[i][j].r = 0;
				maze[i][j].pi = i;
				maze[i][j].pj = j+1;
				maze[i][j].id = 1;
			}
			test = 0;
		} 
		else if (maze[i-1][j].id != 1 && i > 0 && maze[i][j].u != 1) {
			maze[i][j].u = 1;

			test = maze_judge (maze[i][j].cont, maze[i-1][j].cont);

			if (test == 1) {
				i--;
				ans.push(maze[i][j].cont);
				maze[i][j].d = 0;
				maze[i][j].u = 0;
				maze[i][j].l = 0;
				maze[i][j].r = 0;
				maze[i][j].pi = i+1;
				maze[i][j].pj = j;	
				maze[i][j].id = 1;			
			} 
			test = 0;
		}
		else {
			if (ans.top() == ')') flag++;
			else if (ans.top() == '(') flag--;
			ans.pop();
			maze[i][j].id = 0;
			i_tmp = i;
			j_tmp = j;
			i = maze[i_tmp][j_tmp].pi;
			j = maze[i_tmp][j_tmp].pj;
		}
		if (i == 0 && j == 0 && maze[0][0].r == 1 && maze[0][0].d == 1) {
			if (ans.top() == ')') flag++;
			else if (ans.top() == '(') flag--;
			ans.pop();
			maze[i][j].id = 0;
			i_tmp = i;
			j_tmp = j;
			i = maze[i_tmp][j_tmp].pi;
			j = maze[i_tmp][j_tmp].pj;
			return;
		}
		if (i == maze_h-1  && j == maze_w - 1) {
			if (flag == 0) return;
			else {
				if (ans.top() == ')') flag++;
				else if (ans.top() == '(') flag--;
				ans.pop();
				maze[i][j].id = 0;
				i_tmp = i;
				j_tmp = j;
				i = maze[i_tmp][j_tmp].pi;
				j = maze[i_tmp][j_tmp].pj;
			}
		}
	}
}

int maze_judge (int p, int n)
{
	int test = 0;
	if (p == '(') {
		if (n != ')' && n != '+' && n != '-' && n != '*' && n != '/') {
			test = 1;
			if (n == '(') flag++;
		}
	}
	else if (p == ')') {
		if (n == '+' || n == '-' || n == '*' || n == '/' || n == ')') {
			test = 1;
			if (n == ')') flag--;
		}
	}
	else if (p == '+' || p == '-' || p == '*' || p == '/') {
		if (n != '+' && n != '-' && n != '*' && n != '/' && n != ')') {
			if (n == '(') flag++;
			test = 1;
		}
	}
	else{
		if (n == '(') test = 0;
		else if (n == ')' && flag == 0) test = 0;
		else {
			if (n == ')') flag--;
			test = 1;
		}
	}
	return test;
}