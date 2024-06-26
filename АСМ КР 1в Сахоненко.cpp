/*
На 9 баллов:
Задан массив A  из  N (N<=20) целых (int) чисел и число Х (int).
Числа a,b,c,d- целые 2-х байтовые : __int16  или short или short int.
Входные  данные ввести с консоли или случайным образом.
Вычислить выражение из элементов массива : a/b+c*d.
Из массива чисел А получить массив В,  в котором продублировать числа РАВНЫЕ Х.
Результаты: значение выражения и  новый массив вывести на консоль.

На 10 баллов, сделать ещё:
Для получения выражения написать внешнюю функцию (в *.asm) с передачей параметров
Для получения массива В написать внешнюю функцию (в*.asm) с передачей параметров( массив и размерность).
Все вызовы в основной программе
Результаты: значение выражения и  новый массив вывести на консоль.
*/
#include <iostream>
using namespace std;

int main() 
{
    setlocale(LC_ALL, ".1251");
    const int N = 20; 
    int A[N]; 
    signed int X;
    short int result; 
    cout << "Введите размер массива (N <= " << N << "): ";
    int size;
    cin >> size;
    if (size > N || size < 0)
        cout << "Неверно введён параметр";
    else
    {
        cout << "Введите элементы массива A: ";
        for (int i = 0; i < size; i++)
        {
            cin >> A[i];
        }
        cout << "Введите число X: ";
        cin >> X;
        
        __int16 a, b, c, d;
        cout << "Введите значения a, b, c, d" << endl;
        cin >> a >> b >> c >> d;
        short int t;
        
        _asm 
        {
            xor ax, ax
            mov ax, a
            cwd 
            idiv b
            mov cx, ax
            xor ax, ax
            mov ax, c
            imul d
            add ax, cx
            mov result, ax
        };
        
        int newSize = 0;
        int B[2*N];
        /*
        _asm
        {
            xor eax, eax
            mov ecx, size 
            mov esi, A   
            mov edi, B
            L1:
            mov edx, [esi]  
            mov [edi], edx  
            add edi, 4      
            cmp edx, X   
            jne L2         
            mov [edi], edx  
            add edi, 4     
            L2:
            add esi, 4    
            add newSize, 2  
            loop L1        
            
        }
        */
        
        for (int i = 0; i < size; i++)
        {
            B[newSize++] = A[i];
            if (A[i] == X)
            {
                 B[newSize++] = X;
            }
        }
        

        cout << "Результат выражения a/b + c*d: " << result << endl;
        cout << "Массив B: ";
        for (int i = 0; i < newSize; i++)
        {
            cout << B[i] << " ";
        }
        cout << endl;
        
    }
    system("pause");
    return 0;
}