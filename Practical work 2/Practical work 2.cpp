#include <iostream>
#include <chrono>
#include <windows.h>

using namespace std;
using namespace chrono;

void task1(int*, int*, const int);
void task2(int*, const int);
void task3(int*, int*, const int);
void task4(int*, const int);
void task5(int*, const int, int);
void task6(int*, const int, int);
void task7(int*, const int, int);
void task8(int*, const int);
void bonus(int*);

void quicksort(int*, const int);
void findMaxMin(int*, const int, int&, int&);
void binarySearch(int, int*, const int, int&, int&);
int  commonSearch(int, int*, const int);
void arrOutput(int*, const int, int num1 = -1, int num2 = -1);

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
        quicksort(sorted, SIZE); //и это тоже
        cleanScreen();

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
        }

        cleanScreen();
        cout << "Введите х для выхода или любой другой символ для продолжения ";
        cin >> exit;
        cin.sync();

    } while (exit != 'x' && exit != 'X');
    return 0;
}


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
    cout << "\nМассив выглядит сейчас так:\n\n";
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

    cout << "\nЭлементы поменяны за: " << nano.count() << " наносекунд\n\n";
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