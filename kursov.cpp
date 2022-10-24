#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>


using namespace std;

struct Train {
    int number;
    string kuda;
    string otkuda;
    string day;
    int hour;
    int min;
};

const int N = 10;
Train trains[N];

void text() {
    cout << "\nРАСПИСАНИЕ ДВИЖЕНИЯ ПОЕЗДОВ\n"
        "************************************************\n"
        "Полная информация -> нажмите 1;\n"
        "По пунктам отправления -> нажмите 2;\n"
        "Поиск по дням и времени -> нажмите 3;\n"
        "По пунктам назначения -> нажмите 4;\n"
        "Выход из меню -> нажмите 5;\n";
}

//Функция для вывода таблицы со всеми данными
int sort_data() {
    cout << setiosflags(ios::left);
    cout << "Пункт отправления \t" << "Пункт назначения\t" << "Номер\t" << "     День отправления\t" << "Время отправления\t" << endl;

    for (int i = 0; i < N; ++i)
    {
        cout << setw(24) << trains[i].otkuda;
        cout << setw(25) << trains[i].kuda;
        cout << setw(16) << trains[i].number;
        cout << setw(21) << trains[i].day;
        printf("%02d:%02d", trains[i].hour, trains[i].min);
        cout << endl;
    }
    return 0;
}

//Функция для вывода запрашиваемых данных таблицы, отсортированных по пункту отправления
int sort_otpravl() {
    string otprav;
    int k = 0;

    o:
    cout << "Введите пункт отправления:" << endl;
    cin >> otprav;

    //Функции проверки введенного значения на правильность
    for (unsigned int i = 0; i < otprav.size(); i++)
        if (!(otprav[i] >= 'a' && otprav[i] <= 'z') && !(otprav[i] >= 'A' && otprav[i] <= 'Z'))
        {
            cout << "Вы случайно ввели число. Пожалуйста, введите день буквами" << endl;
            goto o;
        }

    //Функция сортировки
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (strcmp(trains[i].kuda.c_str(), trains[j].kuda.c_str()) > 0)//сравниваем длину двоичного кода данных таблицы
            {
                swap(trains[i], trains[j]);//меняем 2 элемента таблицы местами
            }
        }
    }

    cout << setiosflags(ios::left);
    cout << "Пункт отправления \t" << "Пункт назначения\t" << "Номер\t" << "     День отправления\t" << "Время отправления\t" << endl;

    //Функция сортировки
    for (int i = 0; i < N; i++)
    {
        if (_stricmp(otprav.c_str(), trains[i].otkuda.c_str()) == 0)//сравниваем длину двоичного кода данных таблицы
        {
            cout << setw(24) << trains[i].otkuda;
            cout << setw(25) << trains[i].kuda;
            cout << setw(16) << trains[i].number;
            cout << setw(21) << trains[i].day;
            printf("%02d:%02d", trains[i].hour, trains[i].min);
            cout << endl;
            k++;
        }
    }
    if (k == 0)
        cout << "\nНет подходящих поездов" << endl;
    return 0;
}

//Функция для вывода запрашиваемых данных таблицы, отсортированных по пункту назначения
int sort_naznach() {
    string naznach;
    int k = 0;

    p:
    cout << "Введите пункт назначения:" << endl;
    cin >> naznach;

    //Функции проверки введенного значения на правильность
    for (unsigned int i = 0; i < naznach.size(); i++)
        if (!(naznach[i] >= 'a' && naznach[i] <= 'z') && !(naznach[i] >= 'A' && naznach[i] <= 'Z'))
        {
            cout << "Вы случайно ввели число. Пожалуйста, введите день буквами" << endl;
            goto p;
        }
    //Функция сортировки
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (strcmp(trains[i].otkuda.c_str(), trains[j].otkuda.c_str()) > 0)//сравниваем длину двоичного кода данных таблицы
            {
                swap(trains[i], trains[j]);//меняем 2 элемента таблицы местами
            }
        }
    }

    cout << setiosflags(ios::left);
    cout << "Пункт отправления \t" << "Пункт назначения\t" << "Номер\t" << "     День отправления\t" << "Время отправления\t" << endl;

    //Функция сортировки
    for (int i = 0; i < N; i++)
    {
        if (_stricmp(naznach.c_str(), trains[i].kuda.c_str()) == 0)//сравниваем длину двоичного кода данных таблицы
        {
            cout << setw(24) << trains[i].otkuda;
            cout << setw(25) << trains[i].kuda;
            cout << setw(16) << trains[i].number;
            cout << setw(21) << trains[i].day;
            printf("%02d:%02d", trains[i].hour, trains[i].min);
            cout << endl;
            k++;
        }
    }
    if (k == 0)
        cout << "Нет подходящих поездов" << endl;
    return 0;
}

//Функция для вывода запрашиваемых данных таблицы, отсортированных по дню и времени отправления
int sort_vrem() {
    string den;
    int k = 0;
    int hour{ 0 }, min{ 0 };

    d:   
    cout << "Введите день:" << endl;
    cin >> den;

    //Функции проверки введенного значения на правильность
    for (unsigned int i = 0; i < den.size(); i++)
        if (!(den[i] >= 'a' && den[i] <= 'z') && !(den[i] >= 'A' && den[i] <= 'Z'))
        {
            cout << "Вы случайно ввели число. Пожалуйста, введите день буквами" << endl;
            goto d;
        }
    h:
    cout << "Введите нужный час: " << endl;
    
    //Функции проверки введенного значения на правильность
    cin >> hour;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Это не цифра" << std::endl;
        goto h;
    }
    else {
        std::cout << "Наконец-то, ваш час: " << hour << std::endl;
    }
    
    m:
    cout << "Введите нужную минуту: " << endl;
    
    //Функции проверки введенного значения на правильность
    cin >> min;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Это не цифра" << std::endl;
        goto m;
    }
    else {
        std::cout << "Наконец-то, ваша(и) минута(ы): " << min << std::endl;
    }


    cout << " День -> " << den << "\n" << "Время -> " << hour << ":" << min << endl << endl;

    //Функция сортировки
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (trains[i].hour > trains[j].hour)
            {
                swap(trains[i], trains[j]);//меняем 2 элемента таблицы местами
            }
        }
    }

    cout << setiosflags(ios::left);
    cout << "Пункт отправления \t" << "Пункт назначения\t" << "Номер\t" << "     День отправления\t" << "Время отправления\t" << endl;

    //Функция сортировки
    for (int i = 0; i < N; i++)
    {
        if (_stricmp(den.c_str(), trains[i].day.c_str()) == 0)//сравниваем длину двоичного кода данных таблицы
        {
            if (trains[i].hour >= hour && trains[i].min >= min)
            {
                cout << setw(24) << trains[i].otkuda;
                cout << setw(25) << trains[i].kuda;
                cout << setw(16) << trains[i].number;
                cout << setw(21) << trains[i].day;
                printf("%02d:%02d", trains[i].hour, trains[i].min);
                cout << endl;
                k++;
            }
        }
    }
    if (k == 0)
        cout << "Нет подходящих поездов" << endl;
    return 0;
}

int main() {
    char a;

    setlocale(LC_ALL, "Russian");

    ifstream F("TRAIN.txt");
    if (!F)
    {
        cout << "Error opening file!" << endl;
        system("pause");
        return 0;
    }
    for (int i = 0; i < N; i++)
        F >> trains[i].otkuda >> trains[i].kuda >> trains[i].number >> trains[i].day >> trains[i].hour >> trains[i].min;
    F.close();


    t: text();


    e:

    cin >> a;

    if (a == '1' || a == '2' || a == '3' || a == '4' || a == '5') {

        stringstream strm;
        strm << a;
        unsigned int num = stoi(strm.str());

        switch (num) {
        case 1:
            sort_data();
            goto t;
        case 2:
            sort_otpravl();
            goto t;
        case 3:
            sort_vrem();
            goto t;
        case 4:
            sort_naznach();
            goto t;
        case 5:
            cout << "Спасибо за пользование нашим приложением!\n";
            system("pause");
            return 0;
        }
    }

    else
    {
        cout << "Необходимо ввести число от 1 до 5: " << endl;
        goto e;
    }
}