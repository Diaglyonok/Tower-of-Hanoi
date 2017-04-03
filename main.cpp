// hanoi_tower.cpp: определяет точку входа для консольного приложения.
// Программа, рекурсивно решающая задачу "Ханойская башня"

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

void tower(int, int, int, int); // объявление прототипа рекурсивной функции
int count = 1; // глобальная переменная для подсчёта количества шагов

int main()
{
       cout << "Enter  of  numbers  of  disks: ";// введите количество дисков, которые надо переместить
       int number;
       cin >> number;
       cout << "Enter the number of basic rod: "; // введите номер стержня, на котором диски будут находится изначально
       int basic_rod;
       cin >> basic_rod;
       cout << "Enter the number of final rod: "; // введите номер стержня, на который необходимо переместить диски
       int final_rod;
       cin >> final_rod;
       int help_rod;
      // блок определения номера вспомогательного стержня, анализируя номера начального и финального стержня
       if (basic_rod != 2 && final_rod != 2 )
             help_rod = 2;
       else
             if (basic_rod != 1 && final_rod != 1 )
                    help_rod = 1;
             else
                    if (basic_rod != 3 && final_rod != 3 )
                        help_rod = 3;
       tower(number, //  переменная, хранящая количество дисков, которые надо переместить
             basic_rod, // переменная, хранящая номер стержня, на котором диски будут находится изначально
             help_rod , // переменная, хранящая номер стержня, который используется, как вспомогательный
             final_rod);  // переменная, хранящая номер стержня, на который необходимо переместить диски
       system("pause");
       return 0;
}

void tower(int count_disk, int baza, int help_baza, int new_baza)
{
       if ( count_disk == 1) // условие завершения рекурсивных вызовов
       {
           cout << count << ") "<< baza << " " << "->" << " " << new_baza << endl;
           count++;
       }
       else
       {
             tower(count_disk -1, baza, new_baza, help_baza); // перемещаем все диски кроме самого последнего на вспомогательный стержень
             tower(1, baza, help_baza, new_baza); // перемещаем последний диск с начального стержня на финальный стержень
             tower(count_disk -1, help_baza, baza, new_baza); // перемещаем все диски со вспомогательного стержня на финальный
       }
}
