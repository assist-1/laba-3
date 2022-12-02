#include <iostream>
#include <cstring>
#include <fstream>

/**
@brief Функция для вывода подсказок для пользователя
*/
void Menu() {
    std::cout << "Enter as follows:" << std::endl;
    std::cout << "To output from a file, enter: ./prog --fromfile <name.txt>" << std::endl;
    std::cout << "To enter the file, enter: ./prog --tofile <name.txt>" << std::endl;
    std::cout
            << "For reading from one file and out to another file enter: ./nameprog --fromfile --tofile <name1.txt> <name2.txt>"
            << std::endl;

}

/**
@brief ToFile -  Функция, при которой мы считываем из входного потока символы, считываем их во временный файл по предложения на каждую строку
Затем по строкам считываем в 1ый массив предложения, во 2 массив считываем длины, сортируем 2 массив, одновременно сортируя первый и выводим файл
Функция принимает параметр в виде названия выходного файла
*/
void ToFile(char *fname) {
    std::ofstream LongestSentence("LongestSentence.txt");   //Файл для ввода в него самого длинного предложения
    std::ofstream temp_out("var.txt");   // Файл для предварительного чтения из потока cin
    std::ofstream result(fname);  // Файл для ввода в него отсортированных предложений
    char previous_token = 'a'; //иниц. переменной, отвеч. за хранение предыдущего считанного элемента
    int length = 0; //иниц переменной, отвеч. за хранение текущей длины предложения
    int max_length = 0; //иниц. переменной, отвеч. за хранение макс.длины
    int count_sentences = 0; // иниц. переменной, отвеч. за хранения кол-ва всех предложений
    char current_token = '0'; // иниц. переменной для хранения текущего элемента
    while (std::cin.get(current_token) && current_token != '\n') {
        //пока считываем токен и он не переход на новую строку //пока считываем токен и он не переход на новую строку
        if (current_token == '.') {     // если токен - точка
            count_sentences++;  //увел. кол-во предложений и длину и обновляем макс.длину, текущую обнулим
            length++;
            if (length > max_length) max_length = length;
            length = 0;
            previous_token = '.'; // в предыдущий запишем эту самую точку и в файле сделаем переход на новую строку и поставим точку в конце
            temp_out << ".\n";
        } else if (current_token == ' ' && previous_token == '.')
            continue; // если встретился пробел после точки, то продолжаем
        else {                // иначе считываем символ, в предыдущий присваиваем его и увеличиваем длину
            temp_out << current_token;
            previous_token = current_token;
            length++;
        }
    }
    temp_out.close(); //закроем временный файл
    max_length++; // т.к всё закончилось, то увеличим макс.длину на 1
    char array_sent[count_sentences][max_length];  //двум.массив, хранящий предложения(по сути это матрица m на n, где m - макс.длина, n - число предл.
    int array_len[count_sentences];
    std::ifstream in_temp_file("var.txt");
    // теперь наш предыдущий файл для ввода в него делаем таким, чтобы из него можно было считать символы
    for (int i = 0; i < count_sentences; i++) {
        //пройдясь 2-ным циклом по массиву, перепишем данные из файла в него, как раз в каждом элементе будет предложение
        for (int j = 0; j < max_length; j++) {
            in_temp_file.get(current_token);
            if (current_token == '\n') {
                array_sent[i][j] = '\0';
                array_len[i] = j;
                break;
            }
            array_sent[i][j] = current_token;
        }
    }
    in_temp_file.close(); //вновь закроем временный файл
    char buffer[max_length]; // буфер в качестве массива, который будет хранить временно предложения в сортировке
    for (int i = 0; i < count_sentences; i++) {
        for (int j = 0; j < count_sentences - i - 1; j++) {
            if (array_len[j] > array_len[j + 1]) {
                int var = array_len[j]; //временная переменная для пузырьковой сортировки
                array_len[j] = array_len[j + 1];
                array_len[j + 1] = var;
                strcpy(buffer, array_sent[j]);
                strcpy(array_sent[j], array_sent[j + 1]);
                strcpy(array_sent[j + 1], buffer);
            }
        } //проводим сортировку
    }
    for (int i = 0; i < count_sentences; i++)
        result << array_sent[i] << std::endl; // выводим предложения на каждую строку в наш результирующий файл
    LongestSentence << array_sent[count_sentences - 1] << std::endl; // в другой файл выводим самое длинное предложение
    result.close(); // закрываем файлы
    LongestSentence.close();
}

/**
@brief FromFile -  Функция, при которой мы считываем из входного файла символы, считываем их во временный файл по предложения на каждую строку
Затем по строкам считываем в 1ый массив предложения, во 2 массив считываем длины, сортируем 2 массив, одновременно сортируя первый и выводим в консоль
Функция принимает параметр в виде названия входного файла
*/
void FromFile(char *fname) {
    std::ofstream temp_out("var.txt");
    // Файл для временного хранения того что считали с введеного файла и разбиения на предложения
    std::ifstream infile(fname); //файл с которого мы считаем символы
    char previous_token = 'a'; //иниц. переменной, отвеч. за хранение предыдущего считанного элемента
    int length = 0; //иниц переменной, отвеч. за хранение текущей длины предложения
    int max_length = 0; //иниц. переменной, отвеч. за хранение макс.длины
    int count_sentences = 0; // иниц. переменной, отвеч. за хранения кол-ва всех предложений
    char current_token = '0'; // иниц. переменной для хранения текущего элемента
    if (infile.is_open()) { // если файл открылся
        while (infile.get(current_token) && current_token != '\n') {
            //пока считываем токен и он не переход на новую строку
            if (current_token == '.') {     // если токен - точка
                count_sentences++;  //увел. кол-во предложений и длину и обновляем макс.длину, текущую обнулим
                length++;
                if (length > max_length) max_length = length;
                length = 0;
                previous_token = '.'; // в предыдущий запишем эту самую точку и в файле сделаем переход на новую строку и поставим точку в конце
                temp_out << ".\n";
            } else if (current_token == ' ' && previous_token == '.')
                continue; // если встретился пробел после точки, то продолжаем
            else {                // иначе считываем символ, в предыдущий присваиваем его и увеличиваем длину
                temp_out << current_token;
                previous_token = current_token;
                length++;
            }
        }
    } else std::cerr << "The file is not found" << std::endl; //если не открылся, то выводим ошибку
    infile.close();
    temp_out.close(); //закроем временный файл
    max_length++; // т.к всё закончилось, то увеличим макс.длину на 1
    char array_sent[count_sentences][max_length];  //двум.массив, хранящий предложения(по сути это матрица m на n, где m - макс.длина, n - число предл.
    int array_len[count_sentences];
    std::ifstream in_temp_file("var.txt");
    // теперь наш предыдущий файл для ввода в него делаем таким, чтобы из него можно было считать символы
    for (int i = 0; i < count_sentences; i++) {
        //пройдясь 2-ным циклом по массиву, перепишем данные из файла в него, как раз в каждом элементе будет предложение
        for (int j = 0; j < max_length; j++) {
            in_temp_file.get(current_token);
            if (current_token == '\n') {
                array_sent[i][j] = '\0';
                array_len[i] = j;
                break;
            }
            array_sent[i][j] = current_token;
        }
    }
    in_temp_file.close(); //вновь закроем временный файл
    char buffer[max_length]; // буфер в качестве массива, который будет хранить временно предложения в сортировке
    for (int i = 0; i < count_sentences; i++) {
        for (int j = 0; j < count_sentences - i - 1; j++) {
            if (array_len[j] > array_len[j + 1]) {
                int var = array_len[j]; //временная переменная для пузырьковой сортировки
                array_len[j] = array_len[j + 1];
                array_len[j + 1] = var;
                strcpy(buffer, array_sent[j]);
                strcpy(array_sent[j], array_sent[j + 1]);
                strcpy(array_sent[j + 1], buffer);
            }
        } //проводим сортировку
    }
    for (int i = 0; i < count_sentences; ++i)
        std::cout << array_sent[i] << std::endl; // Вывод отсортированных предложений
}

/**
@brief FromAndToFile -  Функция, при которой мы считываем из входного файла символы, считываем их во временный файл по предложения на каждую строку
Затем по строкам считываем в 1ый массив предложения, во 2 массив считываем длины, сортируем 2 массив, одновременно сортируя первый и результат записываем в файл
Функция принимает параметры в виде названия входного и выходного файлов
*/
void FromAndToFile(char *in_file, char *to_file) {
    std::ofstream temp_out("var.txt");
    std::ifstream infile(in_file);
    std::ofstream result(to_file);
    char previous_token = 'a';
    int length = 0;
    int max_length = 0;
    int count_sentences = 0;
    char current_token = '0';
    while (infile.get(current_token) && current_token != '\n') { //пока считываем токен и он не переход на новую строку
        if (current_token == '.') {     // если токен - точка
            count_sentences++;  //увел. кол-во предложений и длину и обновляем макс.длину, текущую обнулим
            length++;
            if (length > max_length) max_length = length;
            length = 0;
            previous_token = '.'; // в предыдущий запишем эту самую точку и в файле сделаем переход на новую строку и поставим точку в конце
            temp_out << ".\n";
        } else if (current_token == ' ' && previous_token == '.')
            continue; // если встретился пробел после точки, то продолжаем
        else {                // иначе считываем символ, в предыдущий присваиваем его и увеличиваем длину
            temp_out << current_token;
            previous_token = current_token;
            length++;
        }
    }
    temp_out.close();
    infile.close();
    temp_out.close(); //закроем временный файл
    max_length++; // т.к всё закончилось, то увеличим макс.длину на 1
    char array_sent[count_sentences][max_length];  //двум.массив, хранящий предложения(по сути это матрица m на n, где m - макс.длина, n - число предл.
    int array_len[count_sentences];
    std::ifstream in_temp_file("var.txt");
    // теперь наш предыдущий файл для ввода в него делаем таким, чтобы из него можно было считать символы
    for (int i = 0; i < count_sentences; i++) {
        //пройдясь 2-ным циклом по массиву, перепишем данные из файла в него, как раз в каждом элементе будет предложение
        for (int j = 0; j < max_length; j++) {
            in_temp_file.get(current_token);
            if (current_token == '\n') {
                array_sent[i][j] = '\0';
                array_len[i] = j;
                break;
            }
            array_sent[i][j] = current_token;
        }
    }
    in_temp_file.close(); //вновь закроем временный файл
    char buffer[max_length]; // буфер в качестве массива, который будет хранить временно предложения в сортировке
    for (int i = 0; i < count_sentences; i++) {
        for (int j = 0; j < count_sentences - i - 1; j++) {
            if (array_len[j] > array_len[j + 1]) {
                int var = array_len[j]; //временная переменная для пузырьковой сортировки
                array_len[j] = array_len[j + 1];
                array_len[j + 1] = var;
                strcpy(buffer, array_sent[j]);
                strcpy(array_sent[j], array_sent[j + 1]);
                strcpy(array_sent[j + 1], buffer);
            }
        } //проводим сортировку
    }
    for (int i = 0; i < count_sentences; i++)
        result << array_sent[i] << std::endl; // Записываем предложения в файл
}

/**
@brief Get_NINEFILE - функция, которая работает в ToFile, она в самом длинном предложении переворачивает слова и выводит их в файл nine.txt
*/
void Get_NINEFILE() {
    std::ifstream infile("LongestSentence.txt"); //Откроем файл для чтения наибольшего предложения
    std::ofstream var("tempfile.txt"); //Временный файл для обработки предложения
    char current_token = '0';
    int length = 0;
    int max_length = 0;
    int count_words = 1;
    while (infile.get(current_token)) { // Пока считываем токен
        if (current_token == ' ') {
            count_words += 1;
            max_length = std::max(++length, max_length);
            length = 0;
            var << "\n";
        } else { // В другом случае просто считаем символы, увеличивая длину
            var << current_token;
            length++;
        }
    }
    infile.close();
    var.close(); // Закрываем файлы
    max_length++;
    char words[count_words][max_length]; //Массив слов
    std::ifstream temp("tempfile.txt");
    std::ofstream res_file("NINE.txt"); //Файл, куда запишем результат переворота предложения
    for (int i = 0; i < count_words; i++) {
        //Пройдясь циклом по массиву, если считанный символ - переход на новую строку, то
        for (int j = 0; j < max_length; j++) {
            temp.get(current_token);
            if (current_token == '\n') { // то текущим элементом будет пробел
                words[i][j] = '\0';
                break; //выходим из цикла
            }
            if (current_token != '.') { //если это не точка, то записываем символ в массив
                words[i][j] = current_token;
            }
        }
    }
    char token;
    for (int i = count_words - 1; i >= 0; i--) {
        //Проходимся обратным циклом по i, и пока токен это элемент массива, мы его считываем в файл
        int j = 0;
        while ((token = words[i][j++])) {
            res_file << token;
        }
        res_file << " ";  //при окончании слова ставим пробел в файл в качестве разделителя
    }
    temp.close();  //закрываем временный файл
}

/**
@brief создаем массив строк, где будем содержать то, что может вводить пользователь
*/
const char *flags[2] = {"--fromfile","--tofile"};
//создаем массив строк, где будем содержать то, что может вводить пользователь
/**
@brief ф-ии main задаем параметры, первый это количество аргументов,
второй это массив, состоящий из аргументов, введенных в консоль при запуске программы
*/
int main(int argc, char *argv[]) { //ф-ии main задаем параметры, первый это количество аргументов,
//второй это массив, состоящий из аргументов, введенных в консоль при запуске программы
    if (argc == 1) { //если было введено только название out файла, то выводим ошибку
        std::cerr << "ERROR: flag(s) is not found" << std::endl;
        Menu();
    } else if (argc == 2) { // если ввели что-то еще:
        if (!strcmp(argv[1], flags[1])) {
            //если ввели --tofile, то выводим ошибку о требовании ввести название выходного файла
            std::cerr << "ERROR: name file is not found" << std::endl; //и выводим меню для --tofile
            Menu();
        } else if (!strcmp(argv[1], flags[0])) {
            //если ввели --fromfile, то выводим ошибку о требовании ввести название входного файла
            std::cerr << "ERROR: name file is not found" << std::endl; //и выводим меню для --fromfile
            Menu();
        } else { //если было введено что-то другое, то выводим ошибку и выводим общее меню
            std::cerr << "ERROR: incorrect flag" << std::endl;
            Menu();
        }
    } else if (argc == 3) { // если было введено всего 3 флага, включая название программы
        char *fname = argv[2]; // в массиве будем хранить название 3 флага, подразумевается, что это название файла
        if (!strcmp(argv[1], flags[1])) { //если это флаг --tofile, то выполняем tofile и Get_NINEFILE(на 9 баллов)
            ToFile(fname);
            Get_NINEFILE();
        } else if (((!strcmp(argv[1], flags[0])) && (!strcmp(argv[2], flags[1]))) ||
                   //иначе если мы ввели --tofile и --fromfile, то
                   ((!strcmp(argv[1], flags[1])) && (!strcmp(argv[2], flags[0])))) {
            std::cerr << "ERROR: you need to enter namefiles"
                      << std::endl; //потребовать ввести файлы для флагов с пом. меню
            Menu();
        } else if (!strcmp(argv[1], flags[0])) {
            FromFile(fname); //если введен --tofile, то выполнить FromFile
        } else {
            std::cerr << "ERROR:incorrect flag" << std::endl; // если введено что-то другое, то пишем ошибку
            Menu();
        }
    } else if (argc == 5) { //если аргументов было введено 5(включая файл)
        char *in_file = argv[2]; //пусть названиями файлов будет (2+1)ый и (4+1)ый аргумент
        char *to_file = argv[4];
        if ((!strcmp(argv[1], flags[0])) &&
            (!strcmp(argv[3], flags[1]))) { //если 2 аргумент - это fromfile , а 4ый это tofile
            FromAndToFile(in_file, to_file); // то выполняем FromAndToFile
        } else {
            std::cerr << "ERROR: incorrect input" << std::endl;
            Menu(); // а иначе вывести ошибку с выводом меню
        }
    } else { // если же флагов было введено неверное кол-во, то вывести ошибку и меню
        std::cerr << "ERROR: unnormal count of flags" << std::endl;
        Menu();
    }
}
