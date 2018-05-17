#include <iostream>
#include<string>
using namespace std;

void walk(int v);
void path(int s, int e);

int cost[100][100]={0};
int record[100]={-1};
int count;
int test;
int l;
int num_v;
int dist[100];
int id[100];

int main()
{
	string command;

	cin>>num_v;

	for (int i=0; i<num_v; i++) {
		for (int j=0; j<num_v; j++) {
			cin>>cost[i][j];
		}
	}

	cin>>command;

	if (command == "Show-path") {
		for (int i=0; i<num_v; i++){
			walk(i);
			for (int j=0; j<num_v; j++) {
				if (dist[j] != 0) {
					cout<<"Path("<<i<<','<<j<<"):"<<i;
					for (int ri=0; ri<100; ri++) {
						record[ri] = -1;
						id[ri] = 0;
					}
					count = 0;
					l = 0;
					test = 0; 
					id[i]=1;
					path(i, j);
					for (int k=0; record[k] != -1; k++) cout<<"->"<<record[k];
					cout<<endl;
					cout<<"Cost:"<<dist[j]<<endl;
				}		
			}
		}
	} else if (command == "Hide-path") { 
		for (int i=0; i<num_v; i++) {
			walk(i);
			for (int j=0; j<num_v; j++) {
				if (dist[j] != 0) {
					cout<<"Path("<<i<<','<<j<<"):"<<endl;
					cout<<"Cost:"<<dist[j]<<endl;
				}
			}
		}
	}
	return 0;
}

void path(int s, int e)
{
	for (int i=0; i<num_v && test == 0; i++) {
		if (cost[s][i] != 0) {
			if (id[i] == 1);
			else if (l > dist[e]) return;
			else { 
				l += cost[s][i];
				record[count]=i;
				count++;
				id[i]=1;
				if (i == e) {
					if (l == dist[e]) { 
						test = 1;
						return;
					}
				}
				path(i, e);
				if (test == 0) {
					l -= cost[s][i];
					record[count] = -1;
					count--;
					id[i]=0;
				}
			}
		}
	}

	return;
}

void walk(int v)
{
	for (int i=0; i<num_v; i++) {
		dist[i] = cost[v][i];
		id[i] = 0;
		if (cost[v][i] != 0) id[i] = 1;
	}
	id[v] = 1;

	for (int k=1; k<num_v-1; k++) {
		for (int i=0; i<num_v; i++) {
			for (int j=0; j<num_v && id[i] != 0; j++) {
				if (cost[i][j] != 0) {
					if (id[j] == 1 && dist[j] > dist[i] + cost[i][j]) dist[j] = dist[i] + cost[i][j];
					else if (id[j] == 0) dist[j] = dist[i] + cost[i][j];
					id[j]=1;
				}
			}
		}
	}
	return;
}