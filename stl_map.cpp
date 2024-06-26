#include <iostream>
#include <map>

using namespace std;

/*
1.	Использовать объекты pair<,>
2.	Определить собственные типы через typedef
3.	Использовать собственный критерий сортировки.
4.	При сравнение отображений использовать перегруженные операторы


11) Разработать программу для работы с отображениями (map). Информационное поле 
каждого элемента представляет собой: код(целое число), цена (целое число) -ключ.
  Программа должна выводить на экран компьютера меню вида и результаты работы:
1.Добавить  элемент
2.Удалить элементы из заданного диапазона
3.Поиск элементов не меньших заданного ключа(upper_bound или lower_bound)
4.Скопировать элементы в новый multimap
5.Замена значения элемента
6.Выход из программы

*/

struct mm_comp
{
    bool operator()(const int& lhs, const int& rhs) const
    {
        return lhs > rhs;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    
    typedef map<int, int, less<int>> map_type;
    typedef pair<int, int> pair_type;
    typedef map_type::iterator iter_type;

    map_type m = 
    {
        {1, 100},
        {29, 2435},
        {5, 25},
        {30, 50},
        {13, 51},
        {14, 750},
        {21, 135}
    };

    int menuitem = 0;
    while (menuitem != 6)
    {
        cout << "МЕНЮ" << endl;
        cout << "====" << endl;
        cout << "1.Добавить элемент" << endl;
        cout << "2.Удалить элементы из заданного диапазона" << endl;
        cout << "3.Поиск элементов не меньших заданного ключа(upper_bound или lower_bound)" << endl;
        cout << "4.Скопировать элементы в новый multimap" << endl;
        cout << "5.Замена значения элемента" << endl;
        cout << "6.Выход из программы" << endl;

        cin >> menuitem;
        switch (menuitem)
        {
        case 1:
        {
            int code, cost;
            cout << "Введите ключ: ";
            cin >> code;
            cout << "Введите цену: ";
            cin >> cost;
            pair_type p(code, cost);
            m.insert(p);
            cout << "Содержимое map:" << endl;
            for (iter_type it = m.begin(); it != m.end(); ++it)
                cout << it->first << " " << it->second << endl;
            break;
        }
        case 2:
        {
            int lower_range, upper_range;
            cout << "Введите нижнюю границу диапазона: ";
            cin >> lower_range;
            cout << "Введите верхнюю границу диапазона:  ";
            cin >> upper_range;
            iter_type low = m.lower_bound(lower_range);
            iter_type up = m.upper_bound(upper_range);
            m.erase(low, up);
            cout << "Содержимое map:" << endl;
            for (iter_type it = m.begin(); it != m.end(); ++it)
                cout << it->first << " " << it->second << endl;
            break;
        }
        case 3:
        {
            int lower_range;
            cout << "Введите ключ: ";
            cin >> lower_range;
            iter_type it = m.lower_bound(lower_range);
            cout << "Найденный (lower_bound) ключ: " << it->first << endl;
            cout << "Значение: " << it->second << endl;
            break;
        }
        case 4:
        {
            typedef multimap<int, int, mm_comp> multimap_type;
            multimap_type mm(m.begin(), m.end());
            cout << "Содержимое нового multimap:" << endl;
            for (iter_type it = mm.begin(); it != mm.end(); ++it)
                cout << it->first << " " << it->second << endl;
            break;
        }
        case 5:
        {
            int code, cost;
            cout << "Введите ключ: ";
            cin >> code;
            iter_type iter = m.find(code);
            if (iter == m.end())
            {
                cout << "Ключ не найден!" << endl;
                break;
            }
            cout << "Введите новую цену: ";
            cin >> cost;
            iter->second = cost;
            cout << "Содержимое map:" << endl;
            for (iter_type it = m.begin(); it != m.end(); ++it)
                cout << it->first << " " << it->second << endl;
            break;
        }
        case 6:
            break;
        default:
            cout << "Не угадал! Крути барабан ещё раз! " << endl;
            break;
        }
    }

    return 0;
}