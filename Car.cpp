#include "Car.h"

Car::Car()
{
	eng = 0.0;
	pr = 0;
	name = " ";
	doors = 0;
}

Car::Car(const Car& c)
{
	eng = c.eng;
	pr = c.pr;
	name = c.name;
	doors = c.doors;
}

Car::Car(float eng, int pr, string name, int doors) :
	eng(eng), pr(pr), name(name), doors(doors) {}

void Car::print() const
{
	cout << "------CAR-----" << endl;
	cout << "engine " << eng << endl;
	cout << "price " << pr << endl;
	cout << "model " << name << endl;
	cout << "doors " << doors << endl;
	cout << endl;
}

float Car::price_per_en() const
{
	return pr / eng;
}

float Car::get_en() const
{
	return eng;
}

string Car::get_name() const
{
	return name;
}

int Car::get_pr() const
{
	return pr;
}

int Car::get_door() const
{
	return doors;
}

void Car::add_pr(int n)
{
	pr += n;
}

bool Car::operator>(Car& c)
{
	return pr > c.pr;
}

void Car::compare_pr(Car& c)
{
	if (pr > c.pr) cout << c.name << " has better engne than" << name;
	else if (pr < c.pr) cout << name << " has better engne than" << c.name;
	else if (pr > c.pr) cout << c.name << " and " << name << " the same eng";
}

void Car::create()
{
	cout << "------creating CAR-----" << endl;
	cout << "engine ";
	cin >> eng;
	cout << "price ";
	cin >> pr;
	cout << "model ";
	cin >> name;
	cout << "doors ";
	cin >> doors;
	cout << endl;
}

Elec::Elec() : Car()
{
	power = 0.0;
	disc = 0;
}

Elec::Elec(const Elec& c) : Car(c)
{
	power = c.power;
	disc = c.disc;
}

Elec::Elec(float eng, int pr, string name, int doors, float power, int disc) :
	Car(eng, pr, name, doors), power(power), disc(disc) {};

void Elec::change_dis(int n)
{
	disc = n;
}

void Elec::print() const
{
	cout << "------Electric CAR-----" << endl;
	cout << "engine " << this->eng << endl;
	cout << "price w discount " << get_pr() << endl;
	cout << "model " << this->name << endl;
	cout << "doors " << this->doors << endl;

	cout << "power " << power << endl;
	cout << "discount " << disc << endl;
	cout << endl;
}

float Elec::price_per_en() const
{
	return (this->pr - (1 - disc)) / (this->eng * (1 + power / 100));
}

int Elec::get_pr() const
{
	return this->pr * (100 - disc) / 100;
}

void Elec::create()
{
	cout << "------creating electric CAR-----" << endl;
	cout << "engine ";
	cin >> this->eng;
	cout << "price ";
	cin >> this->pr;
	cout << "model ";
	cin >> this->name;
	cout << "doors ";
	cin >> this->doors;
	cout << "power ";
	cin >> power;
	cout << "discount ";
	cin >> disc;

	cout << endl;
}

istream& operator>>(istream& s, Car& c)
{
	s >> c.eng >> c.pr >> c.name >> c.doors;
	return s;
}

istream& operator>>(istream& s, Elec& c)
{
	s >> c.eng >> c.pr >> c.name >> c.doors >> c.power >> c.disc;
	return s;
}
