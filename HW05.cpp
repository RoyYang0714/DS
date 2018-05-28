#include<iostream>
#include<iomanip>
#include<string>
#define N 2000

using namespace std;

void qsort(const int left, const int right);
void caculate(int p);
void swap(double a, double b);

struct test
{
	string name;
	double mass;
};

struct mole
{
	double mass;
	string name;
	string sh;
};

mole a[N];

test e[107];

int count;

int main()
{
	int num;
	int size;
	e[0].name = 'H';  e[0].mass = 1.01;
	e[1].name = "He"; e[1].mass = 4.00;
	e[2].name = "Li"; e[2].mass = 6.94;
	e[3].name = "Be"; e[3].mass = 9.01;
	e[4].name = 'B';  e[4].mass = 10.81;
	e[5].name = 'C';  e[5].mass = 12.01;
	e[6].name = 'N';  e[6].mass = 14.01;
	e[7].name = 'O';  e[7].mass = 16.00;
	e[8].name = 'F';  e[8].mass = 19.00;
	e[9].name = "Ne"; e[9].mass = 20.18;

	e[10].name = "Na"; e[10].mass = 22.99;
	e[11].name = "Mg"; e[11].mass = 24.31;
	e[12].name = "Al"; e[12].mass = 26.98;
	e[13].name = "Si"; e[13].mass = 28.09;
	e[14].name = 'P';  e[14].mass = 30.97;
	e[15].name = 'S';  e[15].mass = 32.07;
	e[16].name = "Cl"; e[16].mass = 35.45;
	e[17].name = "Ar"; e[17].mass = 39.95;
	e[18].name = 'K';  e[18].mass = 39.10;
	e[19].name = "Ca"; e[19].mass = 40.08;

	e[20].name = "Se"; e[20].mass = 44.96;
	e[21].name = "Ti"; e[21].mass = 47.87;
	e[22].name = 'V';  e[22].mass = 50.94;
	e[23].name = "Cr"; e[23].mass = 52.00;
	e[24].name = "Mn"; e[24].mass = 54.94;
	e[25].name = "Fe"; e[25].mass = 55.85;
	e[26].name = "Co"; e[26].mass = 55.93;
	e[27].name = "Ni"; e[27].mass = 58.69;
	e[28].name = "Cu"; e[28].mass = 63.55;
	e[29].name = "Zn"; e[29].mass = 65.41;

	e[30].name = "Ga"; e[30].mass = 69.72;
	e[31].name = "Ge"; e[31].mass = 72.64;
	e[32].name = "As"; e[32].mass = 74.92;
	e[33].name = "Se"; e[33].mass = 78.96;
	e[34].name = "Br"; e[34].mass = 79.90;
	e[35].name = "Kr"; e[35].mass = 83.80;
	e[36].name = "Rb"; e[36].mass = 85.47;
	e[37].name = "Sr"; e[37].mass = 87.62;
	e[38].name = 'Y';  e[38].mass = 88.91;
	e[39].name = "Zr"; e[39].mass = 91.22;

	e[40].name = "Nb"; e[40].mass = 92.91;
	e[41].name = "Mo"; e[41].mass = 95.94;
	e[42].name = "Tc"; e[42].mass = 98.91;
	e[43].name = "Ru"; e[43].mass = 101.07;
	e[44].name = "Rh"; e[44].mass = 102.90;
	e[45].name = "Pd"; e[45].mass = 106.42;
	e[46].name = "Ag"; e[46].mass = 107.86;
	e[47].name = "Cd"; e[47].mass = 112.41;
	e[48].name = "In"; e[48].mass = 114.81;
	e[49].name = "Sn"; e[49].mass = 118.71;

	e[50].name = "Sb"; e[50].mass = 121.76;
	e[51].name = "Te"; e[51].mass = 127.60;
	e[52].name = 'I';  e[52].mass = 126.90;
	e[53].name = "Xe"; e[53].mass = 131.29;
	e[54].name = "Cs"; e[54].mass = 132.90;
	e[55].name = "Ba"; e[55].mass = 137.32;
	e[56].name = "La"; e[56].mass = 138.90;
	e[57].name = "Ce"; e[57].mass = 140.11;
	e[58].name = "Pr"; e[58].mass = 140.90;
	e[59].name = "Nd"; e[59].mass = 144.24;

	e[60].name = "Pm"; e[60].mass = 146.91;
	e[61].name = "Sm"; e[61].mass = 150.36;
	e[62].name = "Eu"; e[62].mass = 151.96;
	e[63].name = "Gd"; e[63].mass = 157.25;
	e[64].name = "Tb"; e[64].mass = 158.92;
	e[65].name = "Dy"; e[65].mass = 162.50;
	e[66].name = "Ho"; e[66].mass = 164.93;
	e[67].name = "Er"; e[67].mass = 167.25;
	e[68].name = "Tm"; e[68].mass = 168.93;
	e[69].name = "Yb"; e[69].mass = 173.04;

	e[70].name = "Lu"; e[70].mass = 174.96;
	e[71].name = "Hf"; e[71].mass = 178.49;
	e[72].name = "Ta"; e[72].mass = 180.94;
	e[73].name = 'W';  e[73].mass = 183.84;
	e[74].name = "Re"; e[74].mass = 186.20;
	e[75].name = "Os"; e[75].mass = 190.23;
	e[76].name = "Ir"; e[76].mass = 192.21;
	e[77].name = "Pt"; e[77].mass = 195.08;
	e[78].name = "Au"; e[78].mass = 196.96;
	e[79].name = "Hg"; e[79].mass = 200.59;

	e[80].name = "Tl"; e[80].mass = 204.38;
	e[81].name = "Pb"; e[81].mass = 207.21;
	e[82].name = "Bi"; e[82].mass = 208.98;
	e[83].name = "Po"; e[83].mass = 208.98;
	e[84].name = "At"; e[84].mass = 209.98;
	e[85].name = "Rn"; e[85].mass = 222.01;
	e[86].name = "Fr"; e[86].mass = 223.01;
	e[87].name = "Ra"; e[87].mass = 226.02;
	e[88].name = "Ac"; e[88].mass = 227.02;
	e[89].name = "Th"; e[89].mass = 223.03;

	e[90].name = "Pa"; e[90].mass = 231.03;
	e[91].name = 'U';  e[91].mass = 238.02;
	e[92].name = "Np"; e[92].mass = 237.04;
	e[93].name = "Pu"; e[93].mass = 244.06;
	e[94].name = "Am"; e[94].mass = 143.06;
	e[95].name = "Cm"; e[95].mass = 247.07;
	e[96].name = "Bk"; e[96].mass = 247.07;
	e[97].name = "Cf"; e[97].mass = 251.07;
	e[98].name = "Es"; e[98].mass = 252.08;
	e[99].name = "Fm"; e[99].mass = 257.09;

	e[100].name = "Md"; e[100].mass = 258.09;
	e[101].name = "No"; e[101].mass = 259.10;
	e[102].name = "Lr"; e[102].mass = 260.10;
	e[103].name = "Rf"; e[103].mass = 261.10;
	e[104].name = "Db"; e[104].mass = 262.11;
	e[105].name = "Sg"; e[105].mass = 266.12;
	e[106].name = "Bh"; e[106].mass = 264.12;

	cin>>num;
	cout<<num<<endl;

	while (num) {
		count=0;
		cin>>size;
		cout<<size<<endl;
		
		for (int i=0; i<size; i++) {
			cin>>a[i].name;
			cin>>a[i].sh;
			cin>>a[i].mass;
			if (a[i].mass == 0) caculate(i);
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

void caculate(int p)
{
	int flag=0;
	string cp;
	string t;
	int m;
	int select;

	for (int i=0; i<a[p].sh.size(); i++) {
		if (a[p].sh[i] == '(') flag = 1; 
		else if (a[p].sh[i] == ')' )
		{

		} else {
			select=0;
			for (int j=0; j<107; j++) {
				if (a[p].sh.size() > i+1 && a[p].sh[i]+a[p].sh[i+1] == e[j].name[0]+e[j].name[1]) {
					if (a[p].sh.size() > i+2 && a[p].sh[i+2] <= '9') {
						if (a[p].sh.size() > i+3 && a[p].sh[i+3] <= '9') {
							t = t.append(a[p].sh,i+2,2);
							m = stoi(t);
							a[p].mass+=e[j].mass*m;
							i+=3;
						} else {
							t = t.append(a[p].sh,i+2,1);
							m = stoi(t);
							a[p].mass+=e[j].mass*m;
							i+=2;
						}
					} else {
						a[p].mass+=e[j].mass;
						i+=1;
					}
					j=107;
					select=1;
				}
			}
			for (int j=0; j<107 && select==0; j++) {
				if (a[p].sh[i] == e[j].name[0]) {
					if (a[p].sh.size() > i+1 && a[p].sh[i+1] <= '9') {
						if (a[p].sh[i+2] <= '9') {
							t = t.append(a[p].sh,i+1,2);
							m = stoi(t);
							a[p].mass+=e[j].mass*m;
							i+=2;
						} else {
							t = t.append(a[p].sh,i+1,1);
							m = stoi(t);
							a[p].mass+=e[j].mass*m;
							i+=1;
						}
					} else a[p].mass+=e[j].mass;
					j=107;
				}
			}				
		}
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
