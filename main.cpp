#include <iostream>
#include <cstring>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;

int main(int argc, char *argv[]) {
  int t, k = 0;
  char ch, fs;
  float n0, n1;
  bool first_flag, second_flag = true, third_flag = true;

  if (argc == 1) { // ввод с консоли | вывод в консоль

    cout << "Enter the number of segments:" << endl;
    fs = cin.peek();
    while (fs == ' ' || fs == '\n') { // пропуск ненужных символов
      cin.ignore();
      fs = cin.peek();
    }
    if ((fs >= '0' & fs <= '9') || fs == '-') { // проверка на ошибку ввода
      cin >> t;
    } else {
      cout << "Error: Incorrect input" << endl;
      return -1;
    }

    float **arr = new float *[t], *temp = new float[t];
    for (size_t i = 0; i < t; ++i) { // создание динамического двумерного массива и
      // заполнения каждого i-ого массива нулями
      arr[i] = new float[2];
      arr[i][0] = 0;
      arr[i][1] = 0;
    }

    for (size_t i = 0; i < t; ++i) {
      fs = cin.peek();
      while (fs == ' ' || fs == '\n') { // пропуск ненужных символов
        cin.ignore();
        fs = cin.peek();
      }
      if ((fs >= '0' & fs <= '9') || fs == '-') { // проверка на ошибку ввода
        cin >> n0;
      } else {
        cout << "Error: Incorrect input" << endl;
        return -1;
      }
      fs = cin.peek();
      while (fs == ' ') { // пропуск ненужных символов
        cin.ignore();
        fs = cin.peek();
      }
      if ((fs >= '0' & fs <= '9') || fs == '-') { // проверка на ошибку ввода
        cin >> n1;
      } else {
        cout << "Error: Incorrect input" << endl;
        return -1;
      }
      if (n0 <= n1) {
        first_flag = true;
        for (size_t j = 0; j < t; ++j) {
          if ((arr[j][0] != 0) || (arr[j][1] != 0)) {
            if ((n0 >= arr[j][0]) & (n1 <= arr[j][1])) { // 4-ый вариант
              first_flag = false;
            }
            if ((n0 <= arr[j][1]) & (n1 >= arr[j][1])) { // 3-ий вариант
              first_flag = false;
              arr[j][1] = n1;
            }
            if ((n1 >= arr[j][0]) & (n0 <= arr[j][0])) { // 2-ой вариант
              first_flag = false;
              arr[j][0] = n0;
            }
            if ((n0 <= arr[j][0]) & (n1 >= arr[j][1])) { // 5-ый вариант
              first_flag = false;
              arr[j][0] = n0, arr[j][1] = n1;
            }
          }
        }
        if (first_flag) { // добавление отрезка в k-ый массив (1-ый вариант)
          arr[k][0] = n0, arr[k][1] = n1;
          k += 1;
        }
      } else {
        cout << "Error: The segment is specified incorrectly" << endl;
        return -1;
      }
    }
    fs = cin.peek();
    while (fs == ' ') {
      cin.ignore();
      fs = cin.peek();
    }
    if (fs != '\n') {
      cout << "Error: Incorrect input" << endl;
      return -1;
    }

    while (second_flag) { // объединение уже объединенных отрезков до того, пока уже нечего будет объединять
      second_flag = false;
      for (size_t i = 0; i < t - 1; ++i) {
        if (arr[i][0] != 0 || arr[i][1] != 0) {
          for (size_t j = i + 1; j < t; ++j) {
            if ((arr[j][0] != 0) || (arr[j][1] != 0)) {
              if ((arr[i][0] >= arr[j][0]) & (arr[i][1] <= arr[j][1])) {// 4-ый вариант
                second_flag = true;
                arr[i][0] = 0, arr[i][1] = 0;
              }
              if ((arr[i][0] <= arr[j][1]) & (arr[i][1] >= arr[j][1])) { // 3-ий вариант
                arr[j][1] = arr[i][1];
                arr[i][0] = 0, arr[i][1] = 0;
                second_flag = true;
              }
              if ((arr[i][1] >= arr[j][0]) & (arr[i][0] <= arr[j][0])) { // 2-ой вариант
                arr[j][0] = arr[i][0];
                arr[i][0] = 0, arr[i][1] = 0;
                second_flag = true;
              }
              if ((arr[i][0] <= arr[j][0]) & (arr[i][1] >= arr[j][1])) { // 5-ый вариант
                arr[j][0] = arr[i][0], arr[j][1] = arr[i][1];
                arr[i][0] = 0, arr[i][1] = 0;
                second_flag = true;
              }
            }
          }
        }
      }
    }

    for (int i = 0; i < t - 1; i++) { // сортировка двумерного массива по первым элементам каждого i-ого массива
      for (int j = 0; j < t - i - 1; j++) {
        if (arr[j][0] > arr[j + 1][0]) {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }

    for (size_t i = 0; i < t; ++i) { // вывод элементов
      if (arr[i][0] != 0 || arr[i][1] != 0) {
        if (arr[i][0] == arr[i][1]) {
          cout << arr[i][0] << endl;
        } else {
          cout << arr[i][0] << " " << arr[i][1] << endl;
        }
      }
    }

    for (size_t i = 0; i < t; ++i) {
      delete[] arr[i];
    }
  } else if (((argc == 2) || (argc == 3))
      & (strcmp(argv[1], "--tofile") == 0)) { // ввод с консоли | вывод в файл output.txt или в указанный файл

    cout << "Enter the number of segments:" << endl;
    fs = cin.peek();
    while (fs == ' ' || fs == '\n') { // пропуск ненужных символов
      cin.ignore();
      fs = cin.peek();
    }
    if ((fs >= '0' & fs <= '9') || fs == '-') { // проверка на ошибку ввода
      cin >> t;
    } else {
      cout << "Error: Incorrect input" << endl;
      return -1;
    }

    float **arr = new float *[t], *temp = new float[t];
    for (size_t i = 0; i < t; ++i) { // создание динамического двумерного массива и
      // заполнения каждого i-ого массива нулями
      arr[i] = new float[2];
      arr[i][0] = 0;
      arr[i][1] = 0;
    }

    for (size_t i = 0; i < t; ++i) {
      fs = cin.peek();
      while (fs == ' ' || fs == '\n') { // пропуск ненужных символов
        cin.ignore();
        fs = cin.peek();
      }
      if ((fs >= '0' & fs <= '9') || fs == '-') { // проверка на ошибку ввода
        cin >> n0;
      } else {
        cout << "Error: Incorrect input" << endl;
        return -1;
      }
      fs = cin.peek();
      while (fs == ' ') { // пропуск ненужных символов
        cin.ignore();
        fs = cin.peek();
      }
      if ((fs >= '0' & fs <= '9') || fs == '-') { // проверка на ошибку ввода
        cin >> n1;
      } else {
        cout << "Error: Incorrect input" << endl;
        return -1;
      }
      if (n0 <= n1) {
        first_flag = true;
        for (size_t j = 0; j < t; ++j) {
          if ((arr[j][0] != 0) || (arr[j][1] != 0)) {
            if ((n0 >= arr[j][0]) & (n1 <= arr[j][1])) { // 4-ый вариант
              first_flag = false;
            }
            if ((n0 <= arr[j][1]) & (n1 >= arr[j][1])) { // 3-ий вариант
              first_flag = false;
              arr[j][1] = n1;
            }
            if ((n1 >= arr[j][0]) & (n0 <= arr[j][0])) { // 2-ой вариант
              first_flag = false;
              arr[j][0] = n0;
            }
            if ((n0 <= arr[j][0]) & (n1 >= arr[j][1])) { // 5-ый вариант
              first_flag = false;
              arr[j][0] = n0, arr[j][1] = n1;
            }
          }
        }
        if (first_flag) { // добавление отрезка в k-ый массив (1-ый вариант)
          arr[k][0] = n0, arr[k][1] = n1;
          k += 1;
        }
      } else {
        cout << "Error: The segment is specified incorrectly" << endl;
        return -1;
      }
    }
    fs = cin.peek();
    while (fs == ' ') {
      cin.ignore();
      fs = cin.peek();
    }
    if (fs != '\n') {
      cout << "Error: Incorrect input" << endl;
      return -1;
    }

    while (second_flag) { // объединение уже объединенных отрезков до того, пока уже нечего будет объединять
      second_flag = false;
      for (size_t i = 0; i < t - 1; ++i) {
        if (arr[i][0] != 0 || arr[i][1] != 0) {
          for (size_t j = i + 1; j < t; ++j) {
            if ((arr[j][0] != 0) || (arr[j][1] != 0)) {
              if ((arr[i][0] >= arr[j][0]) & (arr[i][1] <= arr[j][1])) {// 4-ый вариант
                second_flag = true;
                arr[i][0] = 0, arr[i][1] = 0;
              }
              if ((arr[i][0] <= arr[j][1]) & (arr[i][1] >= arr[j][1])) { // 3-ий вариант
                arr[j][1] = arr[i][1];
                arr[i][0] = 0, arr[i][1] = 0;
                second_flag = true;
              }
              if ((arr[i][1] >= arr[j][0]) & (arr[i][0] <= arr[j][0])) { // 2-ой вариант
                arr[j][0] = arr[i][0];
                arr[i][0] = 0, arr[i][1] = 0;
                second_flag = true;
              }
              if ((arr[i][0] <= arr[j][0]) & (arr[i][1] >= arr[j][1])) { // 5-ый вариант
                arr[j][0] = arr[i][0], arr[j][1] = arr[i][1];
                arr[i][0] = 0, arr[i][1] = 0;
                second_flag = true;
              }
            }
          }
        }
      }
    }

    for (int i = 0; i < t - 1; i++) { // сортировка двумерного массива по первым элементам каждого i-ого массива
      for (int j = 0; j < t - i - 1; j++) {
        if (arr[j][0] > arr[j + 1][0]) {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }

    ofstream fout;
    if (argc == 3) { // вывод в указанный файл
      fout.open(argv[2]);
      if (fout.is_open()) {
        for (size_t i = 0; i < t; ++i) {
          if (arr[i][0] != 0 || arr[i][1] != 0) {
            fout << arr[i][0] << " " << arr[i][1] << endl;
          }
        }
      } else {
        cout << "Error: Could not open the file (out)" << endl;
        return -1;
      }
    } else { // вывод в файл output.txt
      fout.open("output.txt");
      if (fout.is_open()) {
        for (size_t i = 0; i < t; ++i) {
          if (arr[i][0] != 0 || arr[i][1] != 0) {
            fout << arr[i][0] << " " << arr[i][1] << endl;
          }
        }
      } else {
        cout << "Error: Could not open the file (out)" << endl;
        return -1;
      }
    }
    fout.close();

    for (size_t i = 0; i < t; ++i) {
      delete[] arr[i];
    }
  } else if ((argc == 3) & (strcmp(argv[1], "--fromfile") == 0)) { // ввод с файла | вывод с консоли
    fstream fin;
    fin.open(argv[2]);
    if (!fin.is_open()) {
      cout << "Error: Could not open the file (in)" << endl;
      return -1;
    } else {
      while (fin.get(ch)) { // проверка на ошибки
        ch = fin.get();
        if ((ch >= '0' & ch <= '9') || ch == '.' || ch == ' ' || ch == '\n' || ch == EOF) {
          third_flag = true;
        } else {
          third_flag = false;
        }
      }
      fin.close();

      fin.open(argv[2]);
      if (!third_flag) {
        cout << "Error: Incorrect input" << endl;
      } else {
        fin >> t;
        float **arr = new float *[t], *temp = new float[t];
        for (size_t i = 0; i < t; ++i) { // создание динамического двумерного массива и
          // заполнения каждого i-ого массива нулями
          arr[i] = new float[2];
          arr[i][0] = 0;
          arr[i][1] = 0;
        }

        for (size_t i = 0; i < t; ++i) {
          fin >> n0 >> n1;
          if (n0 <= n1) {
            first_flag = true;
            for (size_t j = 0; j < t; ++j) {
              if ((arr[j][0] != 0) || (arr[j][1] != 0)) {
                if ((n0 >= arr[j][0]) & (n1 <= arr[j][1])) { // 4-ый вариант
                  first_flag = false;
                }
                if ((n0 <= arr[j][1]) & (n1 >= arr[j][1])) { // 3-ий вариант
                  first_flag = false;
                  arr[j][1] = n1;
                }
                if ((n1 >= arr[j][0]) & (n0 <= arr[j][0])) { // 2-ой вариант
                  first_flag = false;
                  arr[j][0] = n0;
                }
                if ((n0 <= arr[j][0]) & (n1 >= arr[j][1])) { // 5-ый вариант
                  first_flag = false;
                  arr[j][0] = n0, arr[j][1] = n1;
                }
              }
            }
            if (first_flag) { // добавление отрезка в k-ый массив (1-ый вариант)
              arr[k][0] = n0, arr[k][1] = n1;
              k += 1;
            }
          } else {
            cout << "Error: The segment is specified incorrectly" << endl;
            return -1;
          }
        }

        while (second_flag) { // объединение уже объединенных отрезков до того, пока уже нечего будет объединять
          second_flag = false;
          for (size_t i = 0; i < t - 1; ++i) {
            if (arr[i][0] != 0 || arr[i][1] != 0) {
              for (size_t j = i + 1; j < t; ++j) {
                if ((arr[j][0] != 0) || (arr[j][1] != 0)) {
                  if ((arr[i][0] >= arr[j][0]) & (arr[i][1] <= arr[j][1])) {// 4-ый вариант
                    second_flag = true;
                    arr[i][0] = 0, arr[i][1] = 0;
                  }
                  if ((arr[i][0] <= arr[j][1]) & (arr[i][1] >= arr[j][1])) { // 3-ий вариант
                    arr[j][1] = arr[i][1];
                    arr[i][0] = 0, arr[i][1] = 0;
                    second_flag = true;
                  }
                  if ((arr[i][1] >= arr[j][0]) & (arr[i][0] <= arr[j][0])) { // 2-ой вариант
                    arr[j][0] = arr[i][0];
                    arr[i][0] = 0, arr[i][1] = 0;
                    second_flag = true;
                  }
                  if ((arr[i][0] <= arr[j][0]) & (arr[i][1] >= arr[j][1])) { // 5-ый вариант
                    arr[j][0] = arr[i][0], arr[j][1] = arr[i][1];
                    arr[i][0] = 0, arr[i][1] = 0;
                    second_flag = true;
                  }
                }
              }
            }
          }
        }

        for (int i = 0; i < t - 1; i++) { // сортировка двумерного массива по первым элементам каждого i-ого массива
          for (int j = 0; j < t - i - 1; j++) {
            if (arr[j][0] > arr[j + 1][0]) {
              temp = arr[j];
              arr[j] = arr[j + 1];
              arr[j + 1] = temp;
            }
          }
        }

        for (size_t i = 0; i < t; ++i) { // вывод элементов
          if (arr[i][0] != 0 || arr[i][1] != 0) {
            if (arr[i][0] == arr[i][1]) {
              cout << arr[i][0] << endl;
            } else {
              cout << arr[i][0] << " " << arr[i][1] << endl;
            }
          }
        }


        for (size_t i = 0; i < t; ++i) {
          delete[] arr[i];
        }
      }
      fin.close();
    }
  } else if (((argc == 5) || (argc == 4)) & ((strcmp(argv[1], "--fromfile") == 0)
      & (strcmp(argv[2], "--tofile") == 0))) { // ввод с файла || вывод в файл output.txt или в указанный файл
    fstream fin;
    fin.open(argv[3]);
    if (!fin.is_open()) {
      cout << "Error: Could not open the file (in)" << endl;
      return -1;
    } else {
      while (fin.get(ch)) { // проверка на ошибки
        ch = fin.get();
        if ((ch >= '0' & ch <= '9') || ch == '.' || ch == ' ' || ch == '\n' || ch == EOF) {
          third_flag = true;
        } else {
          third_flag = false;
        }
      }
      fin.close();

      fin.open(argv[3]);
      if (!third_flag) {
        cout << "Error: Incorrect input" << endl;
      } else {
        fin >> t;
        float **arr = new float *[t], *temp = new float[t];
        for (size_t i = 0; i < t; ++i) { // создание динамического двумерного массива и
          // заполнения каждого i-ого массива нулями
          arr[i] = new float[2];
          arr[i][0] = 0;
          arr[i][1] = 0;
        }

        for (size_t i = 0; i < t; ++i) {
          fin >> n0 >> n1;
          if (n0 <= n1) {
            first_flag = true;
            for (size_t j = 0; j < t; ++j) {
              if ((arr[j][0] != 0) || (arr[j][1] != 0)) {
                if ((n0 >= arr[j][0]) & (n1 <= arr[j][1])) { // 4-ый вариант
                  first_flag = false;
                }
                if ((n0 <= arr[j][1]) & (n1 >= arr[j][1])) { // 3-ий вариант
                  first_flag = false;
                  arr[j][1] = n1;
                }
                if ((n1 >= arr[j][0]) & (n0 <= arr[j][0])) { // 2-ой вариант
                  first_flag = false;
                  arr[j][0] = n0;
                }
                if ((n0 <= arr[j][0]) & (n1 >= arr[j][1])) { // 5-ый вариант
                  first_flag = false;
                  arr[j][0] = n0, arr[j][1] = n1;
                }
              }
            }
            if (first_flag) { // добавление отрезка в k-ый массив (1-ый вариант)
              arr[k][0] = n0, arr[k][1] = n1;
              k += 1;
            }
          } else {
            cout << "Error: The segment is specified incorrectly" << endl;
            return -1;
          }
        }

        while (second_flag) { // объединение уже объединенных отрезков до того, пока уже нечего будет объединять
          second_flag = false;
          for (size_t i = 0; i < t - 1; ++i) {
            if (arr[i][0] != 0 || arr[i][1] != 0) {
              for (size_t j = i + 1; j < t; ++j) {
                if ((arr[j][0] != 0) || (arr[j][1] != 0)) {
                  if ((arr[i][0] >= arr[j][0]) & (arr[i][1] <= arr[j][1])) {// 4-ый вариант
                    second_flag = true;
                    arr[i][0] = 0, arr[i][1] = 0;
                  }
                  if ((arr[i][0] <= arr[j][1]) & (arr[i][1] >= arr[j][1])) { // 3-ий вариант
                    arr[j][1] = arr[i][1];
                    arr[i][0] = 0, arr[i][1] = 0;
                    second_flag = true;
                  }
                  if ((arr[i][1] >= arr[j][0]) & (arr[i][0] <= arr[j][0])) { // 2-ой вариант
                    arr[j][0] = arr[i][0];
                    arr[i][0] = 0, arr[i][1] = 0;
                    second_flag = true;
                  }
                  if ((arr[i][0] <= arr[j][0]) & (arr[i][1] >= arr[j][1])) { // 5-ый вариант
                    arr[j][0] = arr[i][0], arr[j][1] = arr[i][1];
                    arr[i][0] = 0, arr[i][1] = 0;
                    second_flag = true;
                  }
                }
              }
            }
          }
        }

        for (int i = 0; i < t - 1; i++) { // сортировка двумерного массива по первым элементам каждого i-ого массива
          for (int j = 0; j < t - i - 1; j++) {
            if (arr[j][0] > arr[j + 1][0]) {
              temp = arr[j];
              arr[j] = arr[j + 1];
              arr[j + 1] = temp;
            }
          }
        }

        ofstream fout;
        if (argc == 5) { // вывод в указанный файл
          fout.open(argv[4]);
          if (fout.is_open()) {
            for (size_t i = 0; i < t; ++i) {
              if (arr[i][0] != 0 || arr[i][1] != 0) {
                fout << arr[i][0] << " " << arr[i][1] << endl;
              }
            }
          } else {
            cout << "Error: Could not open the file (out)" << endl;
            return -1;
          }
        } else { // вывод в файл output.txt
          fout.open("output.txt");
          if (fout.is_open()) {
            for (size_t i = 0; i < t; ++i) {
              if (arr[i][0] != 0 || arr[i][1] != 0) {
                fout << arr[i][0] << " " << arr[i][1] << endl;
              }
            }
          } else {
            cout << "Error: Could not open the file (out)" << endl;
            return -1;
          }
        }
        fout.close();
        for (size_t i = 0; i < t; ++i) {
          delete[] arr[i];
        }
      }
      fin.close();

    }
  } else {
    cout << "Error: Incorrectly entered flags" << endl;
    return -1;
  }
  return 0;
}

