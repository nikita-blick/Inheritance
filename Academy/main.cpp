#include<iostream>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n----------------------------------------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
	static const int type_width = 12;
	static const int name_width = 12;
	static const int age_width = 5;
	static int count;                 // объявление статической перемеенной 
	std::string last_name;
	std::string first_name;
	int age;
public:
	static int get_count()
	{
		return count;
	}
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
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	//					Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		count++;
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		count--;
		cout << "HDestructor:\t" << this << endl;
	}

	//					Methods:
	virtual std::ostream& info(std::ostream& os)const	//Base class
	{
		os.width(type_width);
		os << std::left;
		os << std::string(strchr(typeid(*this).name(), ' ') + 1) + ":";
		//return os << last_name << " " << first_name << " " << age;  
		os.width(name_width);
		os << last_name;
		os.width(name_width);
		os << first_name;
		os.width(age_width);
		os << age;
		return os;
	}
	virtual std::istream& scan(std::istream& is)
	{
		return is >> last_name >> first_name >> age;
	}
};

int Human::count = 0;  // Инициализация статической переменной 

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.info(os);
}
std::istream& operator>>(std::istream& is, Human& obj)
{
	return obj.scan(is);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human
{
	static const int speciality_width = 22;
	static const int group_width = 8;
	static const int rat_width = 8;
	std::string speciality;
	std::string group;
	double rating;			// успеваемость
	double attendance;		// посещаемость
public:
	const std::string& get_speciality()const
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

	//					Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//					Methods:
	std::ostream& info(std::ostream& os)const override//Derived class
	{
		//return Human::info(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
		Human::info(os);
		os.width(speciality_width);
		os << speciality;
		os.width(group_width);
		os << group;
		os.width(rat_width);
		os << rating;
		os.width(rat_width);
		os << attendance;
		return os;
	}
	std::istream& scan(std::istream& is)override
	{
		Human::scan(is);
		char sz_buffer[speciality_width + 1] = {};
		is.read(sz_buffer, speciality_width);                 // cin.read() читает заданное кол-во символов из файла и сохроняте их в NTL; (NULL-Terminated Line)

		//	Удаляем лишние пробелы в конце прочитанной строки:
		for (int i = speciality_width; sz_buffer[i] == ' '; i--)sz_buffer[i] = 0;

		// Удаляем лишние пробелы в начале прочитанной строки:
		while (sz_buffer[0] == ' ')
			for (int i = 0; sz_buffer[i]; i++)sz_buffer[i] = sz_buffer[i + 1];

		speciality = sz_buffer; // сохраняем специальность в соответствующее поле

		is >> group >> rating >> attendance;
		return is;
		 
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher :public Human
{
	static const int speciality_width = 32;
	static const int experience_width = 5;
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}

	//				Constructors:
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	std::ostream& info(std::ostream& os)const override
	{
		//return Human::info(os) << " " << speciality << " " << experience;
		Human::info(os);
		os.width(speciality_width);
		os << speciality;
		os.width(experience_width);
		os << experience;
		return os;
	}
	std::istream& scan(std::istream& is)override
	{
		Human::scan(is);
		char sz_buffer[speciality_width + 1] = {};
		is.read(sz_buffer, speciality_width);                 // cin.read() читает заданное кол-во символов из файла и сохроняте их в NTL; (NULL-Terminated Line)

		//	Удаляем лишние пробелы в конце прочитанной строки:
		for (int i = speciality_width-1; sz_buffer[i] == ' '; i--)sz_buffer[i] = 0;

		// Удаляем лишние пробелы в начале прочитанной строки:
		while (sz_buffer[0] == ' ')
			for (int i = 0; sz_buffer[i]; i++)sz_buffer[i] = sz_buffer[i + 1];

		speciality = sz_buffer; // сохраняем специальность в соответствующее поле

		is >> experience;
		return is;

	}
};

#define GRADUATE_TAKE_PARAMETERS const std::string& subject
#define GRADUATE_GIVE_PARAMETERS subject

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	//				Constructors:
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS)
		:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	//				Methods:
	std::ostream& info(std::ostream& os)const override
	{
		return Student::info(os) << " " << get_subject();
	}
	std::istream& scan(std::istream& is) override
	{
		Student::scan(is);
		std::getline(is, subject);
		return is;
	}
};

void Print(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		group[i]->info(cout);
		cout << delimiter << endl;
	}
	cout << "Количсетво объектов: " << group[0]->get_count() << endl;
	cout << "Количсетво объектов: " << Human::get_count() << endl;
}
void Save(Human* group[], const int n, const std::string& filename)
{
	std::ofstream fout("group.txt");
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	std::string cmd = "notepad ";
	cmd += filename;
	system(cmd.c_str());      // метод c_str() возращает строку в виде массива символов (char*); 
}
Human* HumanFactory(const std::string& type)
{
	Human* human = nullptr;
    if (strstr(type.c_str(), "Human"))human = new Human("", "", 0);
	else if (strstr(type.c_str(), "Student"))human = new Student("", "", 0, "", "", 0, 0);
	else if (strstr(type.c_str(), "Graduate"))human = new Graduate("", "", 0, "", "", 0, 0, "");
	else if (strstr(type.c_str(), "Teacher"))human = new Teacher("", "", 0, "", 0);
	return human;
}
Human** Load(const std::string& filename, int& n)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		// 1) подсчитываем кол-во объектов в файле:
		n = 0;
		std::string buffer;
		while (!fin.eof())
		{
			std::getline(fin, buffer);
			if (buffer.size() < 32)continue;
			n++;
		}
		cout << "Кол-во объектов: " << n << endl;

		// 2) Выделяем память под объекты:
		group = new Human* [n];

		// 3) Возварщаемся в начало файла, для того чтобы прочитать из него сами объекты:
		cout << "Position " << fin.tellg() << endl; // метод tellg() возращает текущую Get-позицию курсора на чтение. -1 значит eof()
		fin.clear();
		fin.seekg(0);        // метод seekg(n), переводит  Get-курсор (на чтение) в указанную позицию 'n';
		cout << "Position " << fin.tellg() << endl;

		// 4) Загружаем объекты из файла:
		for (int i=0; i < n; i++)
		{
			std::string buffer;
			std::getline(fin, buffer, ':');
			if (buffer.size() < 5)continue;
			group[i] = HumanFactory(buffer);
			fin >> *group[i];
			//i++;
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	// ?) Закрываем файл:
	fin.close();

	return group;
}
void Clear(Human* group[], const int n)
{
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
		cout << delimiter << endl;
	}
}

//#define INHERITANCE
//#define POLYMORPHISM //(poly - много, morphis - форма)

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE
	Human human("Montana", "Antonio", 25);
	human.info();

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 98);
	student.info();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.info();

	Graduate graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 40, 50, "How to catch Heisenberg");
	graduate.info();
#endif // INHERITANCE

#ifdef POLYMORPHISM


	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 98),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 40, 50, "How to catch Heisenberg"),
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20)
	};

	Print(group, sizeof(group) / sizeof(group[0]));
	Save(group, sizeof(group) / sizeof(group[0]), "group.txt");

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
		cout << delimiter << endl;
	}
#endif // POLYMORPHISM

	int n = 0;
	Human** group = Load("group.txt", n);
	Print(group, n);
	Save(group, n, "group2.txt");
	Clear(group, n);
}