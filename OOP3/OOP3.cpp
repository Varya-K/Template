

#include <iostream>
#include "list.h"
#include "point.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    
    List<int> list_int;
    List<Point> list_point;
    
    int f = 1;
    while (f != 0)
    {
        cout << "\nМеню\n";
        cout << "Список чисел\n";
        cout << "1 - Добавить элемент в конец списка\n";
        cout << "2 - Вставить элемент в список\n";
        cout << "3 - Вывести список\n";
        cout << "4 - Изменить значение элемент\n";
        cout << "5 - Удалить элемент\n";
        cout << "6 - Очистить список\n";
        cout << "Список точек\n";
        cout << "7 - Добавить элемент в конец списка\n";
        cout << "8 - Вставить элемент в список\n";
        cout << "9 - Вывести список\n";
        cout << "10 - Изменить значение элемент\n";
        cout << "11 - Удалить элемент\n";
        cout << "12 - Очистить список\n\n";
        cout << "0 - Выход\n";
        cout << "Выберите функцию и введите число от 0 до 12: ";
        cin >> f;
        while (f < 0 || f>12) {
            cout << "Функции с таким номером нет, введите число от 0 до 12: ";
            cin >> f;
        }
        if (f == 1 || f == 7) {
            cout << "Введите количество элементов, которые хотите ввести: ";
            int n = 0;
            cin >> n;
            for (int i = 0; i < n; i++) {
                if (f == 1) {
                    cout << "Введите " << i+1 << " число: ";
                    int a;
                    cin >> a;
                    list_int.push_back(a);
                }
                else {
                    cout << "Введите координаты x и y " << i+1 << " точки: ";
                    double x, y;
                    cin >> x >> y;
                    list_point.push_back(Point(x, y));
                }
            }
        }
        else if (f == 2 || f == 8) {
            cout << "Введите, на какой номер вы хотите поставить новый элемент: ";
            int i = 0;
            cin >> i;
            if (f == 2) {
                if ((i > list_int.get_count() + 1)||(i<1)) {
                    cout << "Вы можете поставить элемент только на позиции от 1 до " << list_int.get_count() + 1 << ".\n";
                }
                else
                {
                    cout << "Введите " << i << " число: ";
                    int a;
                    cin >> a;
                    list_int.insert(i - 1, a);
                }
            }
            else {
                if ((i > list_point.get_count() + 1)||(i<1)) {
                    cout << "Вы можете поставить элемент только на позиции от 1 до " << list_point.get_count() + 1 << ".\n";
                }
                else
                {
                    cout << "Введите координаты x и y " << i << " точки: ";
                    double x, y;
                    cin >> x >> y;
                    list_point.insert(i - 1, Point(x, y));
                }
            }
        }
        else if (f == 3 || f == 9) {
            if ((f == 3) && (list_int.get_count() == 0) || (f == 9) && (list_point.get_count() == 0)) cout << "Список пуст\n";
            else {
                if (f == 3) {
                    for (int i = 0; i < list_int.get_count(); i++) {
                        cout << i + 1 << ") " << list_int[i] << "\n";
                    }
                }
                else {
                    for (int i = 0; i < list_point.get_count(); i++) {
                        cout << i + 1 << ") x = " << list_point[i].get_x() << "  y = " << list_point[i].get_y() << "\n";
                    }
                }
            }
        }
        else if (f == 4 || f == 10) {
            if ((f==4)&&(list_int.get_count() == 0)|| (f == 10) && (list_point.get_count() == 0)) cout << "Список пуст\n";
            else {
                cout << "Введите номер элемента, который вы хотите изменить: ";
                int i = 0;
                cin >> i;
                if (f == 4) {
                    if ((i > list_int.get_count()) || (i < 1)) {
                        cout << "Вы можете изменить элемент только на позиции от 1 до " << list_int.get_count() << ".\n";
                    }
                    else {
                        cout << "Введите новое число: ";
                        int a = 0;
                        cin >> list_int[i - 1];
                    }
                }
                else {
                    if ((i > list_point.get_count()) || (i < 1)) {
                        cout << "Вы можете изменить элемент только на позиции от 1 до " << list_point.get_count() << ".\n";
                    }
                    else {
                        cout << "Введите координаты x и y новой точки: ";
                        double x, y;
                        cin >> x >> y;
                        list_point[i - 1] = Point(x, y);
                    }
                }
            }
        }
        else if (f == 5 || f == 11) {
            if ((f == 5) && (list_int.get_count() == 0) || (f == 11) && (list_point.get_count() == 0)) cout << "Список пуст\n";
            else {
                cout << "Введите номер элемента, который вы хотите удалить: ";
                int i = 0;
                cin >> i;
                if (f == 5) {
                    if ((i > list_int.get_count()) || (i < 1)) {
                        cout << "Вы можете удалить элемент только на позиции от 1 до " << list_int.get_count() << ".\n";
                    }
                    else {
                        cout << "Элемент " << list_int[i - 1] << "удален.\n";
                        list_int.delete_elem(i - 1);
                    }
                }
                else {
                    if ((i > list_point.get_count()) || (i < 1)) {
                        cout << "Вы можете удалить элемент только на позиции от 1 до " << list_point.get_count() << ".\n";
                    }
                    else {
                        cout << "Элемент  x = " << list_point[i - 1].get_x() << "  y = " << list_point[i - 1].get_y() << " удален.\n";
                        list_point.delete_elem(i - 1);
                    }
                }
            }
        }
        else if ((f == 6) || (f == 12)) {
            if (f == 6) {
                list_int.clear();
            }
            else list_point.clear();
            cout << "Список пуст.\n";
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
