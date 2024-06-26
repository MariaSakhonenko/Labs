#include <iostream>
#include <map>

using namespace std;

/*
1.	������������ ������� pair<,>
2.	���������� ����������� ���� ����� typedef
3.	������������ ����������� �������� ����������.
4.	��� ��������� ����������� ������������ ������������� ���������


11) ����������� ��������� ��� ������ � ������������� (map). �������������� ���� 
������� �������� ������������ �����: ���(����� �����), ���� (����� �����) -����.
  ��������� ������ �������� �� ����� ���������� ���� ���� � ���������� ������:
1.��������  �������
2.������� �������� �� ��������� ���������
3.����� ��������� �� ������� ��������� �����(upper_bound ��� lower_bound)
4.����������� �������� � ����� multimap
5.������ �������� ��������
6.����� �� ���������

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
        cout << "����" << endl;
        cout << "====" << endl;
        cout << "1.�������� �������" << endl;
        cout << "2.������� �������� �� ��������� ���������" << endl;
        cout << "3.����� ��������� �� ������� ��������� �����(upper_bound ��� lower_bound)" << endl;
        cout << "4.����������� �������� � ����� multimap" << endl;
        cout << "5.������ �������� ��������" << endl;
        cout << "6.����� �� ���������" << endl;

        cin >> menuitem;
        switch (menuitem)
        {
        case 1:
        {
            int code, cost;
            cout << "������� ����: ";
            cin >> code;
            cout << "������� ����: ";
            cin >> cost;
            pair_type p(code, cost);
            m.insert(p);
            cout << "���������� map:" << endl;
            for (iter_type it = m.begin(); it != m.end(); ++it)
                cout << it->first << " " << it->second << endl;
            break;
        }
        case 2:
        {
            int lower_range, upper_range;
            cout << "������� ������ ������� ���������: ";
            cin >> lower_range;
            cout << "������� ������� ������� ���������:  ";
            cin >> upper_range;
            iter_type low = m.lower_bound(lower_range);
            iter_type up = m.upper_bound(upper_range);
            m.erase(low, up);
            cout << "���������� map:" << endl;
            for (iter_type it = m.begin(); it != m.end(); ++it)
                cout << it->first << " " << it->second << endl;
            break;
        }
        case 3:
        {
            int lower_range;
            cout << "������� ����: ";
            cin >> lower_range;
            iter_type it = m.lower_bound(lower_range);
            cout << "��������� (lower_bound) ����: " << it->first << endl;
            cout << "��������: " << it->second << endl;
            break;
        }
        case 4:
        {
            typedef multimap<int, int, mm_comp> multimap_type;
            multimap_type mm(m.begin(), m.end());
            cout << "���������� ������ multimap:" << endl;
            for (iter_type it = mm.begin(); it != mm.end(); ++it)
                cout << it->first << " " << it->second << endl;
            break;
        }
        case 5:
        {
            int code, cost;
            cout << "������� ����: ";
            cin >> code;
            iter_type iter = m.find(code);
            if (iter == m.end())
            {
                cout << "���� �� ������!" << endl;
                break;
            }
            cout << "������� ����� ����: ";
            cin >> cost;
            iter->second = cost;
            cout << "���������� map:" << endl;
            for (iter_type it = m.begin(); it != m.end(); ++it)
                cout << it->first << " " << it->second << endl;
            break;
        }
        case 6:
            break;
        default:
            cout << "�� ������! ����� ������� ��� ���! " << endl;
            break;
        }
    }

    return 0;
}