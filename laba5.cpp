#include <iostream>
#include <fstream>
#include <cstring>

const int str_max_len = 1024;
const int str_max_q = 256;

using namespace std;

int main(int argc, char** argv)
{
	if (argc == 2 || argc == 4 || argc > 5)
	{
		cout << "Only two flags and names of files" << endl;
		return 1;
	}
	int tof = 0;
	int fromf = 0;
	char* tofilename;
	char* fromfilename;
	for (int i = 1; i < argc; i++)
	{
		if (tof == 1)
		{
			tof = 2;
			tofilename = argv[i];
		}
		else if (fromf == 1)
		{
			fromf = 2;
			fromfilename = argv[i];
		}

		else if (strcmp("--tofile", argv[i]) == 0) tof = 1;
		else if (strcmp("--fromfile", argv[i]) == 0) fromf = 1;
		else cout << "Wrong flag " << argv[i] << endl << "Try other flag" << endl;
	}

	char list[str_max_q][str_max_len];
	int lens[str_max_q];
	char c;

	int len_counter = 0;
	int q_counter = 0;
	int end_of_sents;


	if (fromf == 2)
	{
		ifstream file_input;
		file_input.open(fromfilename);

		if (!file_input)
		{
			cerr << "There`s no file named " << fromfilename << " in directory with project" << endl;
			return EXIT_FAILURE;
		}
		else
		{
			cout << "File " << fromfilename << " was readen" << endl;
			while (true)
			{
				if (q_counter > str_max_q || len_counter > str_max_len)
				{
					cout << "buffer overflow" << endl;
					return 1;
				}
				if (file_input.eof())
				{
					end_of_sents = q_counter;
					break;
				}
				c = file_input.get();
				if (c == '.')
				{
					list[q_counter][len_counter] = '.';
					q_counter += 1;
					len_counter = 0;
					if (file_input.peek() == ' ' || file_input.peek() == '\n') file_input.ignore();

				}
				else if (c == '\n') file_input.ignore();
				else
				{
					list[q_counter][len_counter] = c;
					len_counter += 1;
					lens[q_counter] += 1;
				}
			}
			file_input.close();
		}
	}
	else
	{
		while (true)
		{
			if (q_counter > str_max_q || len_counter > str_max_len)
			{
				cout << "buffer overflow" << endl;
				return 1;
			}
			c = cin.get();
			if (c == '\n')
			{
				end_of_sents = q_counter;
				break;
			}
			else if (c == '.')
			{
				list[q_counter][len_counter] = '.';
				q_counter += 1;
				len_counter = 0;
				if (cin.peek() == ' ' || cin.peek() == '\n') cin.ignore();

			}
			else
			{
				list[q_counter][len_counter] = c;
				len_counter += 1;
				lens[q_counter] += 1;
			}
		}
	}


	bool flag_bubble = true;
	while (flag_bubble)
	{
		flag_bubble = false;
		for (int i = 1; i < end_of_sents; i++)
		{
			if (lens[i] < lens[i - 1])
			{
				flag_bubble = true;
				char time_arr[str_max_len];
				memcpy(time_arr, list[i], str_max_len);
				memcpy(list[i], list[i - 1], str_max_len);
				memcpy(list[i - 1], time_arr, str_max_len);
				int time_lena = lens[i];
				lens[i] = lens[i - 1];
				lens[i - 1] = time_lena;
			}
		}
	}

	ofstream file_output;
	if (tof == 2) file_output.open(tofilename, ios::out);
	else cout << endl;
	for (int i = 0; i < end_of_sents; i++)
	{
		if (tof == 2) file_output << list[i] << endl;
		else cout << list[i] << endl;
	}
	if (tof == 2) {
		cout << "Answer was written in " << tofilename << endl;
		file_output.close();
	}




	char newtxt_arr[str_max_len];
	int nine_counter = 0;

	int end_nine;
	for (int i = 0; i < str_max_len; i++)
		if (list[end_of_sents - 1][i] == '.')
		{
			end_nine = i;
			break;
		}

	for (int i = end_nine - 1; i >= 0; i--)
	{
		if (list[end_of_sents - 1][i] == ' ' || i == 0)
		{
			if (i == 0)
			{
				newtxt_arr[nine_counter] = list[end_of_sents - 1][0];
				nine_counter += 1;
			}
			for (int j = i + 1; j <= end_nine; j++)
			{
				if (j == end_nine)
				{
					newtxt_arr[nine_counter] = ' ';
					nine_counter += 1;
					break;
				}
				if (list[end_of_sents - 1][j] == ' ')
				{
					newtxt_arr[nine_counter] = ' ';
					nine_counter += 1;
					break;
				}
				newtxt_arr[nine_counter] = list[end_of_sents - 1][j];
				nine_counter += 1;
			}
		}
	}
	ofstream newtxt;
	newtxt.open("NINE.txt", ios::out);
	newtxt << newtxt_arr;
	newtxt.close();
	return 0;
}