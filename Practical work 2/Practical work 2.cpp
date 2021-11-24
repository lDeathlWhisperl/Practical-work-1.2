#include <iostream>
#include <windows.h>
#include "Functions.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    void pause();
    void cleanScreen();

    ShowWindow(GetForegroundWindow(), SW_SHOWMAXIMIZED); //fullscreen

    char exit = '#', ask;
    const int SIZE = 100;
    int sorted[SIZE],
        unsorted[SIZE],
        userNum;

    task1(sorted, unsorted, SIZE);  //Для корректного
    quicksort(sorted, SIZE);        //отображения всех заданий

    do
    {
        cleanScreen();

        cout << "[x] Выход\n\n";
        for (int i = 1; i <= 8; i++)
        {
            cout << "[" << i << "] Задание №" << i;
            if (i == 1)
                cout << " (перегенерируется массив)";
            cout << '\n';
        }

        cin >> ask;
        cin.sync();

        switch (ask)
        {
        case '0':
            cleanScreen();

            bonus(unsorted);

            pause();
            break;
            /*------------------------1------------------------*/
        case '1':
            cleanScreen();

            cout << "Задание №1\n"
                << "\"Создает целочисленный массив размерности N = 100. Элементы массивы должны принимать случайное значение в диапазоне от -99 до 99.\""
                << "\n\nСоздался массив:\n";

            task1(sorted, unsorted, SIZE);
            arrOutput(unsorted, SIZE);

            pause();
            break;
            /*------------------------2------------------------*/
        case '2':
            cleanScreen();

            cout << "Задание №2\n"
                << "\"Отсортировать заданный в пункте 1 массив […] сортировкой (от меньшего к большему). Определить время, затраченное на сортировку, используя библиотеку chrono.\"\n";

            task2(sorted, SIZE);

            pause();
            break;
            /*------------------------3------------------------*/
        case '3':
            cleanScreen();

            cout << "Задание №3\n"
                << "\"Найти максимальный и минимальный элемент массива. Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono.\"\n\n";

            arrOutput(sorted, SIZE);

            task3(sorted, sorted, SIZE);

            pause();
            break;
            /*------------------------4------------------------*/
        case '4':
            cleanScreen();

            cout << "Задание №4\n"
                << "\"Выводит среднее значение (если необходимо, число нужно округлить) максимального и минимального значения. Выводит индексы всех элементов, которые равны этому значению, и их количество.\"\n\n";

            arrOutput(sorted, SIZE);

            cout << "\n\nИндексы элементов, равные " << '(' << *sorted << " + " << sorted[SIZE - 1] << ") / 2 = " << (*sorted + sorted[SIZE - 1]) / 2 << ": ";
            task4(sorted, SIZE);

            pause();
            break;
            /*------------------------5------------------------*/
        case '5':
            cleanScreen();

            cout << "Задание №5\n"
                << "\"Выводит количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем.\"\n\n"
                << "Введите число, меньше которого будет выведено на экран: ";

            cin >> userNum;
            cin.sync();

            task5(sorted, SIZE, userNum);

            pause();
            break;
            /*------------------------6------------------------*/
        case '6':
            cleanScreen();

            cout << "Задание №6\n"
                << "\"Выводит количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем.\"\n"
                << "\nВведите число, больше которого будет выведено на экран: ";

            cin >> userNum;
            cin.sync();

            task6(sorted, SIZE, userNum);

            pause();
            break;
            /*------------------------7------------------------*/
        case '7':
            cleanScreen();

            cout << "Задание №7\n"
                << "\"Выводит информацию о том, есть ли введенное пользователем число в отсортированном массиве. Реализуйте алгоритм бинарного поиска. Сравните скорость его работы с обычным перебором. (*)\"\n";

            arrOutput(sorted, SIZE);

            cout << "\n\nВведите число, индекс которого будет выведено на экран: ";
            cin >> userNum;
            cin.sync();

            task7(sorted, SIZE, userNum);

            pause();
            break;
            /*------------------------8------------------------*/
        case '8':
            cleanScreen();

            cout << "Задание №8\n"
                << "\"Меняет местами элементы массива, индексы которых вводит пользователь. Выведите скорость обмена, используя библиотеку chrono.\"\n";

            arrOutput(sorted, SIZE);

            cout << "\n\nКакие два элемента массива поменять местами?\n";
            task8(sorted, SIZE);

            pause();
            break;
        case 'x':
        case 'х':
        case 'X':
        case 'Х':
            exit = 'x';
            break;
        }

    } while (exit != 'x');
    return 0;
}