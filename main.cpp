#include <iostream>
#include <fstream>
#include <cstring>

const int str_max_len = 1024;//максимальное кол-во символов в предложении
const int str_max_q = 256;//максимальное кол-во предложений

using namespace std;

int main (int argc , char** argv)
{
	if(argc == 2 || argc == 4 || argc > 5)//если есть флаг, но нет названия файла
	{
		cout << "You can enter only two flags and names of files" << endl;
		return 1;
	}
	int tofile = 0;
	int fromfile = 0;
	char* tofilename;
	char* fromfilename;
	for (int i = 1; i < argc ; i++)//обработка флагов
	{
		if (tofile ==1)//если до этого был введен флаг --tofile, то считываем имя файла
		{
			tofile = 2;
			tofilename = argv[i];
		}
		else if (fromfile ==1)//аналогично
		{
			fromfile = 2;
			fromfilename = argv[i];
		}

		else if (strcmp("--tofile" , argv[i]) == 0) tofile = 1;
		else if (strcmp("--fromfile" , argv[i]) == 0) fromfile = 1;
		else cout << "Wrong flag " << argv[i] << endl << "Try other flag" << endl;
	}

	char arr[str_max_q][str_max_len];//массив с предложениями
	int lens[str_max_q];//массив с длинами предложений
	char c;//символ, который считываем		

	int len_counter = 0;//счетчик символов в предложении
	int q_counter = 0;//счетчик предложений
	int end_of_sents;//номер последнего предложения, начиная с единицы


	if(fromfile == 2)//если был флаг --fromfile, то считываем с файла
	{
		ifstream file_input;
		file_input.open(fromfilename);

		if(!file_input)//если такого файла нет
		{
			cerr << "There`s no file named " << fromfilename << " in directory with project" << endl;
			return EXIT_FAILURE;
		}
		else//иначе спокойно читаем с файла
		{
			cout << "File " << fromfilename << " was readen" << endl;
			while(true)
			{
				if(q_counter > str_max_q || len_counter > str_max_len)
				{
					cout << "buffer overflow" << endl;
					return 1;
				}
				if(file_input.eof())//если конец файла
				{
					end_of_sents = q_counter;
					break;//конец файла
				}
				c = file_input.get();//считываем символ с файла
				if(c == '.')//если конец предложения
				{
					arr[q_counter][len_counter] = '.';//конец предложения
					q_counter += 1;//счетчик предложений +1
					len_counter = 0;//счетчик символов обнуляем
					if(file_input.peek() == ' ' || file_input.peek() == '\n') file_input.ignore();//игнорируем пробел и переход на следующую строку после точки
					//cin.ignore() - игнорирует символ
					//cin.peek() - чекает некст символ, но не читает
				}
				else if(c == '\n') file_input.ignore();//если переход на следующую строку, то игнорим этот переход
				else 
				{
					arr[q_counter][len_counter] = c;
					len_counter += 1;
					lens[q_counter] += 1;
				}
			}
		file_input.close();
		}
	}

	else//считывание с консоли
	{
		while(true)
		{
			if(q_counter > str_max_q || len_counter > str_max_len)
			{
				cout << "buffer overflow" << endl;
				return 1;
			}
			c = cin.get();//считываем символ с консоли
			if (c == '\n') //конец ввода
			{
				end_of_sents = q_counter;//номер последнего предложения
				break;
			}
			else if(c == '.')//если конец предложения
			{
				arr[q_counter][len_counter] = '.';//конец предложения
				q_counter += 1;//счетчик предложений +1
				len_counter = 0;//счетчик символов обнуляем
				if(cin.peek() == ' ' || cin.peek() == '\n') cin.ignore();//если конец предложения, то после точки пробел, а только потом следующее предложение
				//cin.ignore() - игнорирует символ
			}
			else 
			{
				arr[q_counter][len_counter] = c;
				len_counter += 1;
				lens[q_counter] += 1;
			}
		}
	}


	bool flag_bubble = true;//флаг для пузырька, будет false, когда весь массив будет отсортирован
	while(flag_bubble)
	{
		flag_bubble = false;
		for(int i = 1; i < end_of_sents; i++)
		{
			if(lens[i] < lens[i - 1])
			{
				flag_bubble = true;
				char time_arr[str_max_len];
				memcpy(time_arr, arr[i], str_max_len); 
				memcpy(arr[i], arr[i - 1], str_max_len);
				memcpy(arr[i-1], time_arr, str_max_len); 
				int time_lena = lens[i];
				lens[i] = lens[i-1];
				lens[i-1] = time_lena;
			}
		}
	}

	ofstream file_output;
	if(tofile == 2) file_output.open(tofilename, ios::out);
	else cout << endl;
	for(int i = 0; i < end_of_sents; i ++)//идем по предложениям
	{
		for(int j = 0; j < 1024; j	++)//идем по символам в предложении
		{
			if(tofile == 2) file_output << arr[i][j];
			else cout << arr[i][j];
			if(arr[i][j] == '.')
			{
				if(tofile == 2) file_output << endl;
				else cout << endl;
				break; //если предложение закончилось
			}
		}
	}
	if(tofile == 2){
		cout << "Answer was written in " << tofilename << endl;
		file_output.close();
	}



//прикол с самой длинной строкой
	char nine_arr[str_max_len];
	int nine_counter = 0;//индекс для nine_arr
	
	int end_nine;//индекс точки в самом длинном предложении
	for(int i = 0; i < str_max_len; i++)
		if(arr[end_of_sents - 1][i] == '.')
		{
			end_nine = i;
			break;
		}

	for(int i = end_nine - 1; i >= 0; i--)//идем от первого символа перед точкой до начала преложения
	{
		if(arr[end_of_sents - 1][i] == ' ' || i == 0)//если нашли пробел
		{
			if(i == 0)//отдельно добавляем самый первый символ из нашей строки
			{
				nine_arr[nine_counter] = arr[end_of_sents -1][0];
				nine_counter += 1;
			}
			for(int j = i + 1; j <= end_nine; j++)//то идем в обратную сторону до пробела или точки и записываем слово в nine_arr
			{
				if (j == end_nine)
				{
					nine_arr[nine_counter] = ' ';
					nine_counter += 1;
					break;
				}
				if(arr[end_of_sents - 1][j] == ' ')//если дошли до пробела
				{
					nine_arr[nine_counter] = ' ';
					nine_counter += 1;
					break;
				}
				nine_arr[nine_counter] = arr[end_of_sents - 1][j];
				nine_counter += 1;
			}
		}
	}
	ofstream nine;//вывод самого длинного предложения реверснутого в файл
	nine.open("NINE.txt", ios::out);
	for(int i = 0; i < end_nine; i++) nine << nine_arr[i];
	nine.close();
	return 0;
}