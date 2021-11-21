#include <iostream>
#include "Functions.h"
#include <chrono>

using namespace std;
using namespace chrono;

void quicksort(int* arr, const int SIZE)
{
    int right = 0,
        left = SIZE - 1,
        mid = arr[SIZE / 2];

    do {
        while (arr[right] < mid)
            right++;

        while (arr[left] > mid)
            left--;

        if (right <= left)
        {
            int tmp = arr[right];
            arr[right] = arr[left];
            arr[left] = tmp;

            right++;
            left--;
        }
    } while (right <= left);

    if (left > 0)
        quicksort(arr, left + 1);
    if (right < SIZE)
        quicksort(&arr[right], SIZE - right);
}

void findMaxMin(int* arr, const int SIZE, int& max, int& min)
{
    for (int i = 0; i < SIZE; i++)
        if (arr[i] > max)
            max = arr[i];

    for (int i = 0; i < SIZE; i++)
        if (arr[i] < min)
            min = arr[i];
}

void binarySearch(int search, int* arr, const int SIZE, int& left, int& right)
{
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        search <= arr[mid] ? right = mid : left = mid + 1;
    }
}

int commonSearch(int search, int* arr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        if (arr[i] == search)
            return i;
    return -1;
}

void arrOutput(int* arr, const int SIZE, int num1, int num2)
{
    int count = 0;
    std::cout << "\nМассив выглядит сейчас так:\n\n";
    for (int i = 0; i < SIZE; i++)
    {
        count++;
        if (i % 10 != 0)
            cout << '\t';

        if (i == num1 || i == num2)
        {
            cout << "\x1b[31m" << '[' << i << ']' << " = " << arr[i] << "\x1b[0m" << ' ';
            continue;
        }

        cout << '[' << i << ']' << " = " << arr[i] << ' ';

        if (count % 10 == 0)
            putchar('\n');
    }
}


void pause()
{
    cout << "\n\n";
    system("Pause");
}

void cleanScreen()
{
    system("Cls");
}


void task1(int* sorted, int* unsorted, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        *(sorted + i) = -99 + rand() % 199; //Случайное число от -99 до 99
        *(unsorted + i) = *(sorted + i);
    }
}

void task2(int* sorted, const int SIZE)
{
    auto begin = steady_clock::now();
    quicksort(sorted, SIZE);
    auto end = steady_clock::now();
    auto nano = duration_cast<nanoseconds>(end - begin);

    arrOutput(sorted, SIZE);

    cout << "\n\nОтсортировано за : " << nano.count() << " наносекунд\n\n"; \
}

void task3(int* sorted, int* unsorted, const int SIZE)
{
    int max = -100,
        min = 100;

    cout << "\n\nВ неотсортированном масиве:\n";

    auto begin = steady_clock::now();
    findMaxMin(unsorted, SIZE, max, min);
    auto end = steady_clock::now();
    auto nano = duration_cast<nanoseconds>(end - begin);

    cout << "    Максимальное значение: " << max << " Минимальное значение: " << min
        << "\n    Найдено за: " << nano.count() << " наносекунд\n\n"
        << "В отсортированном масиве:\n";

    begin = steady_clock::now();
    max = *(sorted + (SIZE - 1)), min = *sorted;
    end = steady_clock::now();
    nano = duration_cast<nanoseconds>(end - begin);

    cout << "    Максимальное значение: " << max << " Минимальное значение: " << min
        << "\n    Hайдено за: " << nano.count() << " наносекунд\n\n";
}

void task4(int* sorted, const int SIZE)
{
    int   mid = (*sorted + *(sorted + (SIZE - 1))) / 2,
        count = 0;

    int right = SIZE - 1,
        left = 0,
        index;
    binarySearch(mid, sorted, SIZE, left, right);
    index = right;

    for (int i = index - 5; i < index + 5; i++)
    {
        if (*(sorted + i) > *(sorted + index))
            break;
        else if (*(sorted + i) == mid)
        {
            cout << i << ' ';
            count++;
        }
    }

    if (count != 0)
        cout << "\n    и их количество: " << count << "\n\n";
    else
        cout << "\n    таких чисел нет";
}

void task5(int* sorted, const int SIZE, int userNum)
{
    int count = 0;

    cout << "    Числа, которые меньше, чем " << userNum << ": ";

    for (int i = 0; i < SIZE; i++)
    {
        if (*(sorted + i) >= userNum)
            break;
        cout << *(sorted + i) << ' ';
        count++;
    }

    if (count == 0)
        cout << "Таких чисел нет";
}

void task6(int* sorted, const int SIZE, int userNum)
{
    int count = 0;

    cout << "    Числа, которые больше, чем " << userNum << ": ";

    for (int i = SIZE - 1; i >= 0; i--)
    {
        if (*(sorted + i) <= userNum)
            break;
        cout << *(sorted + i) << ' ';
        count++;
    }

    if (count == 0)
        cout << "Таких чисел нет";
}

void task7(int* sorted, const int SIZE, int userNum)
{
    int right = SIZE - 1,
        left = 0;

    cout << "\n    Бинарный поиск: \n";
    auto begin = steady_clock::now();
    binarySearch(userNum, sorted, SIZE, left, right);
    auto end = steady_clock::now();
    auto nano = duration_cast<nanoseconds>(end - begin);

    if (*(sorted + right) == userNum)
        cout << "        Найденое число находится под индексом " << right;
    else
        cout << "        Таких чисел нет";

    cout << "\n        Hайдено за: " << nano.count() << " наносекунд\n\n";

    cout << "    Обычный поиск: \n";
    begin = steady_clock::now();
    int index = commonSearch(userNum, sorted, SIZE);
    end = steady_clock::now();
    nano = duration_cast<nanoseconds>(end - begin);

    if (index >= 0)
        cout << "        Найденое число находится под индексом " << right << '\n';
    else
        cout << "        Таких чисел нет\n";

    cout << "        Найдено за: " << nano.count() << " наносекунд\n\n";
}

void task8(int* sorted, const int SIZE)
{
    int num1,
        num2;

    try
    {
        cin >> num1 >> num2;
        cin.sync();
        if (num1 < 0 || num1 > 99 || num2 < 0 || num2 > 99 || num1 == num2)
            throw - 1;
    }
    catch (int e)
    {
        while (num1 < 0 || num1 > 99 || num2 < 0 || num2 > 99 || num1 == num2)
        {
            cout << "\nВы ввели значения либо выходящие за пределы массива, либо равные друг другу, попробуйте еще раз\n";
            cin >> num1 >> num2;
        }
    }

    auto begin = steady_clock::now();
    swap(sorted[num1], sorted[num2]);
    auto end = steady_clock::now();
    auto nano = duration_cast<nanoseconds>(end - begin);

    cout << "\nЭлементы заменены за: " << nano.count() << " наносекунд\n\n";
    arrOutput(sorted, SIZE, num1, num2);
}

void bonus(int* unsorted)
{
    const int MAX = 50;
    int arr1[MAX], arr2[MAX], count = 0;

    for (int i = 0; i < MAX; i++)
    {
        arr1[i] = *(unsorted + i);
        arr2[i] = *(unsorted + (i + 50));
    }

    for (int i = 0; i < MAX; i++)
    {
        if (*(arr1 + i) % 2 != 0)
            for (int j = 0; j < MAX; j++)
                if (*(arr2 + j) % 2 == 0)
                {
                    int temp = arr1[i];
                    arr1[i] = arr2[j];
                    arr2[j] = temp;
                    break;
                }
    }

    for (int i = 0; i < MAX; i++)
        if (arr2[i] % 2 != 0)
            *(arr2 + i) -= 1;

    for (int i = 0; i < MAX; i++)
        if (arr1[i] > arr2[i])
        {
            count++;
        }
    cout << "\n\nКоличество элементов, которые больше в первом массиве, чем во втором: " << count;
}