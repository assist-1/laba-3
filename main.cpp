#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


int main(int argc, char** argv)
{
	if(argc == 2 || argc == 4 || argc > 5)
	{
		cout << "You have to enter any flag and name of file after: --tofile name.txt --fromfile name.txt" << endl;
		return EXIT_FAILURE;
	}
	int tofile = 0;
	int fromfile = 0;
	char* tofile_name;
	char* fromfile_name;

	for(int i = 1; i < argc; i++)
	{
		if(tofile == 1) 
		{
			tofile_name = argv[i];
			tofile = 2;
		}
		else if(fromfile == 1) 
		{
			fromfile_name = argv[i];
			fromfile = 2;
		}
		else if(strcmp(argv[i], "--tofile") == 0) tofile = 1;
		else if(strcmp(argv[i], "--fromfile") == 0) fromfile = 1;
		else
		{
			cout << "Unexpected flag " << argv[i] << endl;
			return EXIT_FAILURE;
		}
	}


	int n;

	ifstream file_input;
	if(fromfile == 2)//чтение с файла
	{
		file_input.open(fromfile_name);

		if(!file_input)
		{
			cerr << "There`s no file named " << fromfile_name << " in directory with project" << endl;
			return EXIT_FAILURE;
		}
		else
		{
			cout << "File " << tofile_name << " was readen" << endl;
			file_input >> n;
		}
	}
	else cin >> n;

	double arr[n][2];//двумерный массив с отрезками

	if(fromfile == 2)	
	{
		for(int i = 0; i < n; i ++)
		{
			file_input >> arr[i][0];	
			file_input >> arr[i][1];
		}
		file_input.close();
	}
	else//чтение с консоли
	{
		for(int i = 0; i < n; i ++)
		{
			cin >> arr[i][0];	
			cin >> arr[i][1];
			if(arr[i][0] > arr[i][1])
			{
				cerr << "Start of line is over the end" << endl;
				return EXIT_FAILURE;
			}
		}
	}


	bool flag = true;
	if(n == 0) flag = false;
	while(flag)//ПУЗЫРЕЕЕЕЕЕЕЕК
	{
		flag = false;
		for(int i = 1; i < n; i++)
		{
			if(arr[i][0] < arr[i - 1][0])
			{
				double c0 = arr[i][0];
				double c1 = arr[i][1];
				arr[i][0] = arr[i-1][0];
				arr[i][1] = arr[i-1][1];
				arr[i-1][0] = c0;
				arr[i-1][1] = c1;
				flag = true;
			}
		}
	}

	// for(int i =0; i < n; i++) cout << arr[i][0] << " " << arr[i][1] << endl;//вывод осорт.

	double start = arr[0][0];
	double end = arr[0][1];
	int count = 1;
	bool flag_nothing = true;

	ofstream file;
	if(tofile == 2)
	{
		file.open(tofile_name, ios::out);
	}
	else cout << endl;

	if(n==0)
	{	
		if(tofile == 2) 
		{
			file << "NOTHING FOUND" << endl;
			cout << "Output was written in " << tofile_name << endl;
		}
		else cout << "NOTHING FOUND" << endl;
		return EXIT_SUCCESS;
	}

	for(int i = 1; i < n; i++)
	{
		if(arr[i][0] > end)//разрыв, начало нынешнего больше конца предыдущего объединения
		{
			if(count != 1)//если предыдущее объединение состоит не из одного отрезка
			{
				if(tofile == 2) file << start << " " << end << endl;
				else cout << start << " " << end << endl;
				count = 1;
			}
			start = arr[i][0];
			end = arr[i][1];
		} 
		else if(arr[i][1] > end)//начало меньше end, конец больше end
		{
			end = arr[i][1];
			count += 1;
			flag_nothing = false;
		}
		else 
		{
			count += 1;//начало меньше или равно конца объединения, конец меньше конца объединения
			flag_nothing = false;
		}
	}
	if(tofile == 2)
	{
		if(count != 1) file << start << " " << end << endl;
		if(flag_nothing) 
		{
			file << "NOTHING FOUND" << endl;
			return EXIT_SUCCESS;
		}
		cout << "Output was written in " << tofile_name << endl;
		file.close();
	}
	else
	{
		if(count != 1) cout << start << " " << end << endl;
		if(flag_nothing) 
		{
			cout << "NOTHING FOUND" << endl;
			return EXIT_SUCCESS;
		}
	}

	return EXIT_SUCCESS;
}