#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Human
{
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = last_name;
	}
	int set_age(int age)
	{
		this->age = age;
	}

	//         Constructors:
	Human(const std::string& last_name, const std::string& sirdt_name, int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//         Methosd:
	void info()const
	{
		cout << last_name << " " << first_name << " " << age << endl;
	}
};
class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;          // успеваемость 
	double attendance;      // посещ€емость
public:
	const std::string& get_cpeciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance; 
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
};


void main()
{
	setlocale(LC_ALL, "");

}