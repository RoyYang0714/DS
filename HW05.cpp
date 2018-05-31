#include<iostream>
#include<iomanip>
#include<string>
#define N 1800

using namespace std;

void qsort(const int left, const int right);
double caculate(int p);
void swap(int l, int r);

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

test e[118];

int count;
int size;
unsigned int index;

int main()
{
	int num;
	
	e[0].name = "H";  e[0].mass = 1.00;
	e[1].name = "He"; e[1].mass = 4.00;
	e[2].name = "Li"; e[2].mass = 7.00;
	e[3].name = "Be"; e[3].mass = 9.00;
	e[4].name = "B";  e[4].mass = 11.00;
	e[5].name = "C";  e[5].mass = 12.00;
	e[6].name = "N";  e[6].mass = 14.00;
	e[7].name = "O";  e[7].mass = 16.00;
	e[8].name = "F";  e[8].mass = 19.00;
	e[9].name = "Ne"; e[9].mass = 20.00;

	e[10].name = "Na"; e[10].mass = 23.00;
	e[11].name = "Mg"; e[11].mass = 24.00;
	e[12].name = "Al"; e[12].mass = 27.00;
	e[13].name = "Si"; e[13].mass = 28.00;
	e[14].name = "P";  e[14].mass = 31.00;
	e[15].name = "S";  e[15].mass = 32.00;
	e[16].name = "Cl"; e[16].mass = 35.00;
	e[17].name = "Ar"; e[17].mass = 40.00;
	e[18].name = "K";  e[18].mass = 39.00;
	e[19].name = "Ca"; e[19].mass = 40.00;

	e[20].name = "Sc"; e[20].mass = 45.00;
	e[21].name = "Ti"; e[21].mass = 48.00;
	e[22].name = "V";  e[22].mass = 51.00;
	e[23].name = "Cr"; e[23].mass = 52.00;
	e[24].name = "Mn"; e[24].mass = 55.00;
	e[25].name = "Fe"; e[25].mass = 56.00;
	e[26].name = "Co"; e[26].mass = 59.00;
	e[27].name = "Ni"; e[27].mass = 59.00;
	e[28].name = "Cu"; e[28].mass = 64.00;
	e[29].name = "Zn"; e[29].mass = 65.00;

	e[30].name = "Ga"; e[30].mass = 70.00;
	e[31].name = "Ge"; e[31].mass = 73.00;
	e[32].name = "As"; e[32].mass = 75.00;
	e[33].name = "Se"; e[33].mass = 79.00;
	e[34].name = "Br"; e[34].mass = 80.00;
	e[35].name = "Kr"; e[35].mass = 84.00;
	e[36].name = "Rb"; e[36].mass = 85.00;
	e[37].name = "Sr"; e[37].mass = 88.00;
	e[38].name = "Y";  e[38].mass = 89.00;
	e[39].name = "Zr"; e[39].mass = 91.00;

	e[40].name = "Nb"; e[40].mass = 93.00;
	e[41].name = "Mo"; e[41].mass = 96.00;
	e[42].name = "Tc"; e[42].mass = 97.00;
	e[43].name = "Ru"; e[43].mass = 101.00;
	e[44].name = "Rh"; e[44].mass = 103.00;
	e[45].name = "Pd"; e[45].mass = 106.00;
	e[46].name = "Ag"; e[46].mass = 108.00;
	e[47].name = "Cd"; e[47].mass = 112.00;
	e[48].name = "In"; e[48].mass = 115.00;
	e[49].name = "Sn"; e[49].mass = 119.00;

	e[50].name = "Sb"; e[50].mass = 122.00;
	e[51].name = "Te"; e[51].mass = 128.00;
	e[52].name = "I";  e[52].mass = 127.00;
	e[53].name = "Xe"; e[53].mass = 131.00;
	e[54].name = "Cs"; e[54].mass = 133.00;
	e[55].name = "Ba"; e[55].mass = 137.00;
	e[56].name = "La"; e[56].mass = 139.00;
	e[57].name = "Ce"; e[57].mass = 140.00;
	e[58].name = "Pr"; e[58].mass = 141.00;
	e[59].name = "Nd"; e[59].mass = 144.00;

	e[60].name = "Pm"; e[60].mass = 145.00;
	e[61].name = "Sm"; e[61].mass = 150.00;
	e[62].name = "Eu"; e[62].mass = 152.00;
	e[63].name = "Gd"; e[63].mass = 157.00;
	e[64].name = "Tb"; e[64].mass = 159.00;
	e[65].name = "Dy"; e[65].mass = 163.00;
	e[66].name = "Ho"; e[66].mass = 165.00;
	e[67].name = "Er"; e[67].mass = 167.00;
	e[68].name = "Tm"; e[68].mass = 169.00;
	e[69].name = "Yb"; e[69].mass = 173.00;

	e[70].name = "Lu"; e[70].mass = 175.00;
	e[71].name = "Hf"; e[71].mass = 178.00;
	e[72].name = "Ta"; e[72].mass = 181.00;
	e[73].name = "W";  e[73].mass = 184.00;
	e[74].name = "Re"; e[74].mass = 186.00;
	e[75].name = "Os"; e[75].mass = 190.00;
	e[76].name = "Ir"; e[76].mass = 192.00;
	e[77].name = "Pt"; e[77].mass = 195.00;
	e[78].name = "Au"; e[78].mass = 197.00;
	e[79].name = "Hg"; e[79].mass = 201.00;

	e[80].name = "Tl"; e[80].mass = 204.00;
	e[81].name = "Pb"; e[81].mass = 207.00;
	e[82].name = "Bi"; e[82].mass = 209.00;
	e[83].name = "Po"; e[83].mass = 209.00;
	e[84].name = "At"; e[84].mass = 210.00;
	e[85].name = "Rn"; e[85].mass = 222.00;
	e[86].name = "Fr"; e[86].mass = 223.00;
	e[87].name = "Ra"; e[87].mass = 226.00;
	e[88].name = "Ac"; e[88].mass = 227.00;
	e[89].name = "Th"; e[89].mass = 232.00;

	e[90].name = "Pa"; e[90].mass = 231.00;
	e[91].name = "U";  e[91].mass = 238.00;
	e[92].name = "Np"; e[92].mass = 237.00;
	e[93].name = "Pu"; e[93].mass = 244.00;
	e[94].name = "Am"; e[94].mass = 243.00;
	e[95].name = "Cm"; e[95].mass = 247.00;
	e[96].name = "Bk"; e[96].mass = 247.00;
	e[97].name = "Cf"; e[97].mass = 251.00;
	e[98].name = "Es"; e[98].mass = 252.00;
	e[99].name = "Fm"; e[99].mass = 257.00;

	e[100].name = "Md"; e[100].mass = 258.00;
	e[101].name = "No"; e[101].mass = 259.00;
	e[102].name = "Lr"; e[102].mass = 262.00;
	e[103].name = "Rf"; e[103].mass = 267.00;
	e[104].name = "Db"; e[104].mass = 270.00;
	e[105].name = "Sg"; e[105].mass = 269.00;
	e[106].name = "Bh"; e[106].mass = 270.00;
	e[107].name = "Hs"; e[107].mass = 270.00;
	e[108].name = "Mt"; e[108].mass = 278.00;
	e[109].name = "Ds"; e[109].mass = 281.00;
	e[110].name = "Rg"; e[110].mass = 281.00;
	e[111].name = "Cn"; e[111].mass = 285.00;
	e[112].name = "Nh"; e[112].mass = 286.00;
	e[113].name = "Fl"; e[113].mass = 289.00;
	e[114].name = "Mc"; e[114].mass = 289.00;
	e[115].name = "Lv"; e[115].mass = 293.00;
	e[116].name = "Ts"; e[116].mass = 293.00;
	e[117].name = "Og"; e[117].mass = 294.00;

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
			if (a[i].mass == 0) {
				index = 0;
				a[i].mass = caculate(i);
			}
		}

		qsort(0, size-1);
		
		for (int i=0; i<size; i++) {
			cout<<a[i].name;
			for (unsigned int j=0; j<40-a[i].name.size(); j++) cout<<" ";
			cout<<a[i].sh;
			for (unsigned int j=0; j<25-a[i].sh.size(); j++) cout<<" ";
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
			if (i < j && a[i].mass != a[j].mass) swap (i, j);
		} while (i < j);
		if (left != j && pivot != a[j].mass) swap (left, j);
		qsort(left, j-1);
		qsort(j+1, right);
	}
	return;
}

double caculate(int p)
{
	double ans=0;
	string t;
	int select;
	int m;
	int z;

	while (index < a[p].sh.size()) {
		if (a[p].sh[index] == '(') {
			index++;
			ans += caculate(p);
		} else if (a[p].sh[index] == ')') {
			if (a[p].sh.size() > index+1 && a[p].sh[index+1] <= '9' && a[p].sh[index+1] != ')' && a[p].sh[index+1] != '(') {
				for (z=index+1; z < a[p].sh.size() && a[p].sh[z] <= '9' && a[p].sh[z] != ')' && a[p].sh[z] != '('; z++);
				t = '0';
				t = t.append(a[p].sh,index+1,z-index);
				m = stoi(t);
				ans *= m;
				index+=z-index;
				return ans;
			} else {
				index++;
				return ans;
			}					
		} else if (a[p].sh[index] == '[') {
			index++;
			//ans += caculate(p);
		} else if (a[p].sh[index] == ']') {
			if (a[p].sh.size() > index+1 && a[p].sh[index+1] <= '9' && a[p].sh[index+1] != ')' && a[p].sh[index+1] != '(') {
				for (z=index+1; z < a[p].sh.size() && a[p].sh[z] <= '9' && a[p].sh[z] != ')' && a[p].sh[z] != '('; z++);
				t = '0';
				t = t.append(a[p].sh,index+1,z-index);
				m = stoi(t);
				ans *= m;
				index+=z-index;
				return ans;
			} else {
				index++;
				return ans;
			}
		} else {
			t = '0';
			select=0;
			for (int j=0; j<118; j++) {
				if (a[p].sh.size() > index+1 && a[p].sh[index] == e[j].name[0] && a[p].sh[index+1] == e[j].name[1]) {
					if (a[p].sh.size() > index+2 && a[p].sh[index+2] <= '9' && a[p].sh[index+2] != ')' && a[p].sh[index+2] != '(') {
						for (z=index+2; z < a[p].sh.size() && a[p].sh[z] <= '9' && a[p].sh[z] != ')' && a[p].sh[z] != '('; z++);
						t = t.append(a[p].sh,index+2,z-index);
						m = stoi(t);
						ans += e[j].mass*m;
						index+=z-index;
					} else {
						ans += e[j].mass;
						index+=2;
					}
					j=107;
					select=1;
				}
			}
			for (int j=0; j<118 && select==0; j++) {
				if (a[p].sh[index] == e[j].name[0] && e[j].name[1] == 0) {
					if (a[p].sh.size() > index+1 && a[p].sh[index+1] <= '9' && a[p].sh[index+1] != ')' && a[p].sh[index+1] != '(') {
						for (z=index+1; z < a[p].sh.size() && a[p].sh[z] <= '9' && a[p].sh[z] != ')' && a[p].sh[z] != '('; z++);
						t = t.append(a[p].sh,index+1,z-index);
						m = stoi(t);
						ans += e[j].mass*m;
						index+=z-index; 
					} else {
						ans += e[j].mass;
						index++;
					}
					j=107;
				}
			}				
		}
	}

	return ans;
}

void swap(int l, int r)
{
	mole tmp;
	tmp = a[l];
	a[l] = a[r];
	a[r]=tmp;

	count++;

	return;
}