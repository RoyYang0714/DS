#include<iostream>
#include <iomanip>
#include<string>
#define N 100

using namespace std;

void qsort(const int left, const int right);
void swap(double a, double b);

struct mole
{
	double mass;
	string name;
	string sh;
};

mole a[N];
int count;

int main()
{
	int num;
	int size;
	int flag;

	cin>>num;
	cout<<num<<endl;

	while (num) {
		count=0;
		cin>>size;
		cout<<size<<endl;
		flag=0;
		for (int i=0; i<size; i++) {
			cin>>a[i].name;
			cin>>a[i].sh;
			cin>>a[i].mass;
			if (a[i].mass == 0) flag = 1;
		}
		if (flag) {
			
		}

		qsort(0, size-1);
		
		for (int i=0; i<size; i++) {
			cout<<a[i].name<<" ";
			for (int j=1; j<40-a[i].name.size(); j++) cout<<" ";
			cout<<a[i].sh<<" ";
			for (int j=1; j<25-a[i].sh.size(); j++) cout<<" ";
			cout<<fixed<<right<<setw(10)<<setprecision(2)<<a[i].mass<<endl;
		}
		cout<<count<<" swaps during qsort"<<endl;
		num--;
	}

	return 0;
}

void qsort(const int left, const int right)
{
	if (left < right) {
		double &pivot = a[left].mass;
		int i = left;
		int j = right+1;
		do {
			do j--; while (a[j].mass > pivot);
			do i++; while (i < j && a[i].mass <= pivot);
			if (i < j) swap (a[i].mass, a[j].mass);
		} while (i < j);
		if (pivot != a[j].mass) swap (pivot, a[j].mass);
		qsort(left, j-1);
		qsort(j+1, right);
	}
	return;
}

void swap(double l, double r)
{
	mole tmp;
	int t;
	for (int i=0; i<N; i++) {
		if (a[i].mass == l) {
			tmp = a[i];
			t=i;
		} else if (a[i].mass == r) {
			a[t] = a[i];
			a[i] = tmp;		
		}
	}
	count++;

	return;
}