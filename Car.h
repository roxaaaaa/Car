#pragma once
#include <iostream> 
#include <string>
#include <istream>
using namespace std;
class Car {
protected:
	float eng;
	int pr;
	string name;
	int doors;
public:
	Car();
	Car(const Car& c);
	Car(float eng, int pr, string name, int doors);
	virtual void print() const;
	virtual  float price_per_en() const;
	float get_en() const;
	string get_name() const;
	virtual int get_pr() const;
	int get_door() const;
	void add_pr(int n);
	bool operator>(Car& c);
	void compare_pr(Car& c);
	virtual void create();
	friend istream& operator>>(istream& s, Car& c);
};

class Elec : public Car {
private:
	float power;
	int disc;
public:
	Elec();
	Elec(const Elec& c);
	Elec(float eng, int pr, string name, int doors, float power, int disc);

	void change_dis(int n);
	void print() const override;
	float price_per_en() const override;
	int get_pr() const override;
	void create() override;
	friend istream& operator>>(istream& s, Elec& c);


};
