#include<iostream>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	// 1) Создание потока:
	std::ofstream fout;
	// 2) Открытие потока:
	//fout.open("File.txt");        // Поток открытый таким образом всегда будет перезаписывать файл.
	fout.open("File.txt", std::ios_base::app);  // Append - добавить в конец
	// 3) Запись в поток:
	fout << "Hello Files" << endl;;
	// 4) ПОТОКИ ОБЯЗАТЕЛЬНО НУЖНО ЗАКРЫВАТЬ:
	fout.close();

	system("notepad File.txt");

#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	
	// 1) Создаем и открываем поток:
	std::ifstream fin("File.txt");

	// 2) Проверяем, открылся ли поток:
	if (fin.is_open())
	{
		//TODO: Read from file:
		while (!fin.eof())   // EndOfFile
		{
			std::string buffer;
			//fin >> buffer;
			std::getline(fin, buffer);
			cout << buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}

	// ?) Зыкрываем поток:
	fin.close();




#endif // READ_FROM_FILE


}