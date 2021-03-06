#include <iostream>
#include <string>
using namespace std;

class node {
friend class chain;

private:
	string gift;
	string price;
	node *next;
};

class chain {
public:
	void init (string gift, string price);
	void InsertBack (string gift, string price);
	void InsertAfter (string gift, string price, string ptib);
	void Delete (string price);
	void Reverse ();
	void print();
	void free();

private:
	node *first;
	node *p;
	string ptib;
};

int empty;

int main()
{
	chain list;
	string in;
	string pin;
	string ptibin;
	string gin;

	cin>>in;
	if (in == "End") cout<<"Empty"<<endl;
	else {
		while (in != "InsertBack") cin>>in;
		cin>>gin;
		cin>>pin;
		list.init(gin, pin);
		empty = 0;
		cin>>in;

		while (in != "End") {
			if (in == "InsertBack")	{
				cin>>gin;
				cin>>pin;
				if (empty == 0) list.InsertBack(gin, pin);
				else {
					list.init(gin, pin);
					empty = 0;
				}
			} else if (in == "InsertAfter") {
				cin>>gin;
				cin>>pin;
				cin>>ptibin;
				list.InsertAfter(gin, pin, ptibin);
			} else if (in == "Reverse") {
				list.Reverse();
			} else if (in == "Delete") {
				cin>>pin;
				list.Delete(pin);
			}
			cin>>in;
		}
		list.print();
		list.free();
	}
	return 0;
}

void chain::init(string gift, string price)
{
	node *tmp;
	tmp = new node;
	tmp->gift = gift;
	tmp->price = price;
	first = tmp;	
}

void chain::InsertBack (string gift, string price)
{
	node *tmp;
	p = first;
	while (p->next != 0) {
		p = p->next;	
	}
	tmp = new node;
	p->next = tmp;
	p = p->next;
	p->gift = gift;
	p->price = price;
	p->next = 0;
}

void chain::InsertAfter (string gift, string price, string ptib)
{
	node *tmp;
	int test = 0;
	p = first;
	while (p->next != 0 && test == 0) {
		if (p->price == ptib) {
			tmp = new node;
			tmp->price = price;
			tmp->gift = gift;
			tmp->next = p->next;
			p->next = tmp;
			test = 1;
		} else {
			p = p->next;
		}
	}
	if (test == 0 && p->price == ptib) {
		tmp = new node;
		p->next = tmp;
		p = p->next;
		p->gift = gift;
		p->price = price;	
		p->next = 0;
	} else ;
}
void chain::Delete (string price)
{
	p = first;
	int test = 0;
	node *tmp;
	if (p->next == 0 && p->price != price) return;
	else if(p->next == 0 && p->price == price) {
		delete first;
		empty = 1;
		return;
	}
	tmp = p->next;
	for ( ;tmp->next != 0 && test == 0; tmp = p->next) {
		if (tmp->price == price) {
			p->next = tmp->next;
			delete tmp;
			test = 1;
		} else {
			p = p->next;
		}
	}
	tmp = p->next;
	if (test == 0) {
		if (first->price == price) {
			tmp = first;
			first = first->next;
			delete tmp;
		} else if (tmp->price == price) {
			delete tmp;
			p->next = 0;
		}
	} else ;
}

void chain::Reverse ()
{
	node *tmp;
	tmp = first;
	if (tmp->next == 0) return;
	if (first->next->next == 0) {
		p = first->next;
		tmp->next = 0;
		first = p;
		first->next = tmp;
		return; 
	}
	p = first->next;
	tmp->next = 0;
	first = p;
	p = p->next;
	first->next = tmp; 
	while (p->next != 0) {
		tmp = first;
		first = p;
		p = p->next;
		first->next = tmp;
	}
	tmp = first;
	first = p;
	p = p->next;
	first->next = tmp;
}

void chain::print()
{
	p = first;
	if (empty == 1) {
		cout<<"Empty"<<endl;
		return;
	}
	cout<<"List"<<endl;
	while (p->next != 0) {
		cout<<'('<<p->gift<<','<<p->price<<')'<<'-'<<'>';
		p = p->next;
	}
	cout<<'('<<p->gift<<','<<p->price<<')'<<endl;
}
void chain::free()
{
	p = first;
	node *tmp;
	while (p->next != 0) {
		tmp = p;
		p = p->next;
		delete tmp;
	}
}
