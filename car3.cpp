#include "Car.h"
#include <list>
#include <fstream>
#include <vector>
#include <algorithm>

/*template <typename T>
T big(list<T>& l) {
	auto big = l.begin();
	for (auto i = l.begin(); i != l.end(); ++i) {
		if (big->get_en() < i->get_en()) big = i;
	}
	return *big;
}
void compare_en(list<Car>& c, list<Elec>& e) {
	Car c1 = big<Car>(c);
	Elec e1 = big<Elec>(e);
	if (c1.get_en() > e1.get_en()) cout << c1.get_name() << " has the biggest engine " << endl;
	else if (c1.get_en() < e1.get_en()) cout << e1.get_name() << " has the biggest engine " << endl;
}
int total = 0;
list<string> names;
template <typename T>
void add(list<T>& l) {
	T a;
	a.create();
	total += a.get_door();
	names.push_back(a.get_name());
	l.push_back(a);
}
template <typename T>
void printl(list<T>& l) {
	for (const auto& i : l) {
		i.print();
	}
}
void enter(list<Car>& c, list<Elec>& e) {
	cout << "number of cars overall ";
	int n;
	cin >> n;
	for (int i(0); i < n; i++) {
		cout << "1-car, 2-electric: ";
		char l;
		cin >> l;
		switch (l) {
		case '1':
			add<Car>(c);
			break;
		case '2':
			add<Elec>(e);
			break;
		}
	}
	printl<Car>(c);
	printl<Elec>(e);
}
list<Car> c;
	list<Elec> e;
	enter(c, e);
	cout << total << endl;
	for (const auto& i : names) {
		cout << i << " ";
	}
	compare_en(c, e);*/

	/*
	 Визначте, скільки є автомобілів з чотирма дверима.
	 Впорядкуйте автомобілі за спаданням ціни за об'єм двигуна.
	 Для кожного електромобіля додайте тисячу до ціни, надрукуйте отриману колекцію.
	*/

bool byPr(Car* c, Car* t) {
	return c->get_pr() < t->get_pr();
}

bool doors4(Car* c) {
	return c->get_door() == 4;
}
void add(Car* c) {
	c->add_pr(1000);
}
int main() {
	vector<Car*> c;
	ifstream file("file.txt");
	int  x;
	while (file >> x) {
		switch (x) {
		case 1: {
			Car* c1 = new Car();

			file >> *c1;
			c1->print();
			c.push_back(c1);
			break;
		}
		case 2: {
			Elec* c1 = new Elec();
			file >> *c1;
			c1->print();
			c.push_back(c1);
			break;
		}
		}
	}

	sort(c.begin(), c.end(), byPr);
	cout << " sorted list : " << endl<< endl;
	for (const auto& i : c) {
		i->print();
	}
	cout << endl << count_if(c.begin(), c.end(), doors4) << endl;
	cout << " added 1000 : " << endl << endl;
	for_each(c.begin(), c.end(), add);
	for (const auto& i : c) {
		
		i->print();
	}
}