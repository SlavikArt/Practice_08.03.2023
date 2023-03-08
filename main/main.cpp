#include <iostream>
using namespace std;

class Student
{
protected:
	string name;
	int age;
public:
	Student();
	Student(string n, int a);
};

Student::Student() 
{
	name = "Vasya";
	age = 16;
}

Student::Student(string n, int a) : name(n), age(a) 
{
}

class StepStudent : public Student
{
	int technologies;
public:
	StepStudent();
	StepStudent(int tech);
	StepStudent(string n, int a, int tech);

	void Print();
};

StepStudent::StepStudent()
{
	technologies = 0;
}

StepStudent::StepStudent(int tech)
{
	technologies = tech;
}

StepStudent::StepStudent(string n, int a, int tech) :Student(n, a)
{
	technologies = tech;
}

void StepStudent::Print()
{
	cout << "Name: " << name 
		<< "\nAge: " << age 
		<< "\nTechnologies: " << technologies << "\n";
}


class Transport
{
protected:
	int wheels;
	double speed;
	double weight;
	double costPerKm;
public:
	Transport();
	Transport(int w, double s, double we, double c);

	void CalcTripDuration(double km);
};

Transport::Transport()
{
	wheels = 0;
	speed = 0;
	weight = 0;
	costPerKm = 0;
}

Transport::Transport(int w, double s, double we, double c) 
	: wheels(w), speed(s), weight(we), costPerKm(c)
{
}

void Transport::CalcTripDuration(double km)
{
	cout << "Trip cost: " << km * costPerKm << " $\nTrip time: " << km / speed * 60 << " min\n";
}

class Car : public Transport
{
public:
	Car();
	Car(int w, double s, double we, double c);
};

Car::Car()
{
	wheels = 4;
	speed = 60;
	weight = 10049;
	costPerKm = 10;
}

Car::Car(int w, double s, double we, double c) 
	: Transport(w, s, we, c)
{
}


class Carriage : public Transport
{
public:
	Carriage();
	Carriage(int w, double s, double we, double c);
};

Carriage::Carriage()
{
	wheels = 4;
	speed = 20;
	weight = 500;
	costPerKm = 7;
}

Carriage::Carriage(int w, double s, double we, double c)
	: Transport(w, s, we, c)
{
}


class Bicycle : public Transport
{
public:
	Bicycle();
	Bicycle(int w, double s, double we, double c);
};

Bicycle::Bicycle()
{
	wheels = 2;
	speed = 30;
	weight = 14;
	costPerKm = 2.5;
}

Bicycle::Bicycle(int w, double s, double we, double c)
	: Transport(w, s, we, c)
{
}


int main()
{
	StepStudent st(5);
	st.Print();

	cout << "\n";

	StepStudent st2("Petya", 18, 3);
	st2.Print();

	int km = 0;
	cout << "\nEnter a distance(km): ";
	cin >> km;

	cout << "\nTrip duration and cost for " << km <<" km:\n\n";

	Car objCar(4, 40.5, 1050.2, 11.5);
	cout << "Car:\n";
	objCar.CalcTripDuration(km);

	cout << "\n";

	Car objCarriage(4, 20.3, 580, 5);
	cout << "Carriage:\n";
	objCarriage.CalcTripDuration(km);

	cout << "\n";

	Car objBicycle(2, 27.3, 12.5, 2.7);
	cout << "Bicycle:\n";
	objBicycle.CalcTripDuration(km);
}
