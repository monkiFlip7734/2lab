#include <iostream>
#include <ctime>
#include <chrono>
#include <locale.h>

using namespace std;

int shellSort(int arr[], int N)
{
    for (int gap = N / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < N; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
    return 0;
}

int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value) {
            return mid;
        }

        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }
        if (arr[mid] < value) {
            return binarySearch(arr, value, mid+1, end);
        }

        return binarySearch(arr, value, mid + 1, end);
    }

    return -1;
}


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void combSort(int arr[], int n) {
    float s = n - 1;
    int swap;
    int count = 0;
    float k = 1.247;
    while (s >= 1)
    {
        for (int i = 0; i + s < n; i++)
        {
            if (arr[i] > arr[int(i + s)])
            {
                swap = arr[int(i + s)];
                arr[int(i + s)] = arr[i];
                arr[i] = swap;
            }
        }
        s /= k;
    }

    while (true)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = swap;
            }
            else count++;
        }
        if (count == n - 1)
            break;
        else
            count = 0;
    }
}

void anotherArray(int arr[], int n, int bar[]) {

    for (int i = 0; i < n; i++)
    {
        bar[i] = arr[i];
    }
}

void cocktailSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

void quickSort(int* arr, int  end, int begin)
{
    int mid;
    int f = begin;
    int l = end;
    mid = arr[(f + l) / 2];
    while (f < l)
    {
        while (arr[f] < mid)
            f++;
        while (arr[l] > mid)
            l--;
        if (f <= l)
        {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (begin < l)
        quickSort(arr, l, begin);
    if (f < end)
        quickSort(arr, end, f);
}

int maxArray(int arr[], int n) {
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int minArray(int arr[], int n) {
    int min = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}



void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int bananchiki = 1;

    while (bananchiki)
    {
        int test1;

        
        const int size = 100;
        int arr[size];
        int bar[size];

        srand(static_cast<int>(time(0)));

        for (int i = 0; i < size; ++i) {
            arr[i] = (rand() % 199) - 99;
        }
        anotherArray(arr, size, bar);
        bubbleSort(bar, size);
        int brusnichka = 1;
        while (brusnichka)
        {
            cout
                << "Что вы хотите сделать?" << '\n'
                << "1.Вывести массив" << '\n'
                << "2.Отсортировать массив и вывести время, за которое он отсортируется" << '\n'
                << "3.Найти максимальный и минимальный элемент массива и вывести время, за которое они найдутся" << '\n'\
                << "4.Выветси среднее значение максимального и минимального значения."
                << " Вывести индексы всех элементов, которые равны этому значению, и их количество." << '\n'
                << "5.Вывести количество элементов в отсортированном массиве, которые меньше числа a, которое задается вами." << '\n'
                << "6.Вывести количество элементов в отсортированном массиве, которые больше числа b, которое задается вами." << '\n'
                << "7.Вывести информацию о том, есть ли введенное вами число в отсортированном массиве. "
                << "Сравнить скорость работы бинарного поиска с обычным перебором." << '\n'
                << "8.Поменять местами элементы массива, индексы которых вводите вы. Вывести время, за которые они поменяются." << '\n'
                << "0.ПЕРЕСОЗДАНИЕ МАССИВА/ВЫХОД" << '\n';


            int f;
            cin >> f;
            switch (f)
            {
                case(0):
                {
                    cout << "Вы уверены?" << '\n'
                        << "1.Нет" << '\n'
                        << "2.Да" << '\n';
                    int test;
                    cin >> test;
                    if (test == 1) {
                        break;
                    }
                    else{
                        brusnichka = 0;
                        break;
                    }
                }
                case(1):
                {
                    cout
                        << "1.Неотсортированный" << '\n'
                        << "2.Остортированный" << '\n';
                    int k;
                    cin >> k;
                    if (k == 1)
                    {
                        printArray(arr, size);
                        break;
                    }
                    else if (k == 2)
                    {
                        bubbleSort(bar, size);
                        printArray(bar, size);
                        break;
                    }
                    else
                    {
                         cout << "Введите 1 или 2!" << '\n';
                        break;
                    }
                }


                case(2):
                {
                    cout
                        << "Каким способом?" << '\n'
                        << "1.Пузыркем" << '\n'
                        << "2.Шейкер-сортировка" << '\n'
                        << "3.Расческой" << '\n'
                        << "4.Вставками" << '\n'
                        << "5.Быстрая сортировка" << '\n'
                        << "6.Шелла" << '\n';
                    int d;
                    cin >> d;
                    switch (d)
                    {
                        default:
                        {
                            cout << "Введите номер операции, которую хотите выполнить!" << '\n';
                            break;
                        }
                        case (1):
                        {
                            anotherArray(arr, size, bar);
                            auto bubstart = chrono::high_resolution_clock::now();
                            bubbleSort(bar, size);
                            auto bubend = chrono::high_resolution_clock::now();
                            printArray(bar, size);
                            chrono::duration<float> bubduration = bubend - bubstart;
                            cout.setf(ios::fixed);
                            cout << bubduration.count() << "s" << '\n';
                            break;
                        }
                        case (2):
                        {
                            anotherArray(arr, size, bar);
                            auto tailstart = chrono::high_resolution_clock::now();
                            cocktailSort(bar, size);
                            auto tailend = chrono::high_resolution_clock::now();
                            printArray(bar, size);
                            chrono::duration<float> tailduration = tailend - tailstart;
                            cout.setf(ios::fixed);
                            cout << tailduration.count() << "s" << '\n';
                            break;
                        }
                        case (3):
                        {
                            anotherArray(arr, size, bar);
                            auto combstart = chrono::high_resolution_clock::now();
                            combSort(bar, size);
                            auto combend = chrono::high_resolution_clock::now();
                            printArray(bar, size);
                            chrono::duration<float> combduration = combend - combstart;
                            cout.setf(ios::fixed);
                            cout << combduration.count() << "s" << '\n';
                            break;
                        }
                        case (4):
                        {
                            anotherArray(arr, size, bar);
                            auto insstart = chrono::high_resolution_clock::now();
                            insertionSort(bar, size);
                            auto insend = chrono::high_resolution_clock::now();
                            printArray(bar, size);
                            chrono::duration<float> insduration = insend - insstart;
                            cout.setf(ios::fixed);
                            cout << insduration.count() << "s" << '\n';
                            break;
                        }
                        case(5):
                        {
                            anotherArray(arr, size, bar);
                            auto quickstart = chrono::high_resolution_clock::now();
                            quickSort(bar, size - 1, 0);
                            auto quickend = chrono::high_resolution_clock::now();
                            printArray(bar, size);
                            chrono::duration<float> quickduration = quickend - quickstart;
                            cout.setf(ios::fixed);
                            cout << quickduration.count() << "s" << '\n';
                            break;
                        }
                        case(6): {
                            anotherArray(arr, size, bar);
                            auto quickstart = chrono::high_resolution_clock::now();
                            shellSort(bar, size);
                            auto quickend = chrono::high_resolution_clock::now();
                            printArray(bar, size);
                            chrono::duration<float> quickduration = quickend - quickstart;
                            cout.setf(ios::fixed);
                            cout << quickduration.count() << "s" << '\n';
                            break;
                        }
                    }
                    break;
                }
                case(3): {
                    cout
                        << "В каком массиве?" << '\n'
                        << "1.Неотсортированном" << '\n'
                        << "2.Отсортированном" << '\n';
                    int p;
                    cin >> p;
                    if (p == 1)
                    {
                        int max = -100;
                        int min = 100;
                        auto maxminsortedstart = chrono::high_resolution_clock::now();
                        cout
                            << maxArray(arr, size) << ' '
                            << minArray(arr, size) << '\n';
                        auto maxminsortedend = chrono::high_resolution_clock::now();
                        chrono::duration<float> maxminsortedduration = maxminsortedend - maxminsortedstart;
                        cout.setf(ios::fixed);
                        cout << maxminsortedduration.count() << "s" << '\n';
                    }
                    else if (p == 2)
                    {
                        auto maxminnsstart = chrono::high_resolution_clock::now();
                        cout <<
                            bar[0] << ' ' << bar[99] << '\n';
                        auto maxminnsend = chrono::high_resolution_clock::now();
                        chrono::duration<float> maxminnsduration = maxminnsend - maxminnsstart;
                        cout.setf(ios::fixed);
                        cout << maxminnsduration.count() << "s" << '\n';
                    }
                    else
                        cout << "Введите 1 или 2!" << '\n';
                    break;
                }
                case(4):
                {
                    cout
                        << "В каком массиве?" << '\n'
                        << "1.Неотсортированном" << '\n'
                        << "2.Отсортированном" << '\n';
                    int mi;
                    cin >> mi;
                    if (mi == 1)
                    {
                        auto midnsstart = chrono::high_resolution_clock::now();
                        int middlens = (maxArray(arr, size) + minArray(arr, size)) / 2;
                        cout << "Среднее число массива: " << middlens << '\n';
                        int countns = 0;
                        for (int i = 0; i < size; i++)
                        {
                            if (arr[i] == middlens)
                            {
                                ++countns;
                                cout << "Индекс " << countns << " числа: " << i << '\n';
                            }
                        }
                        if (countns == 0) {
                            cout << "Такого числа в массиве нет :(" << '\n';
                        }
                        else {
                            cout << countns << '\n';
                        }
                        auto midnsend = chrono::high_resolution_clock::now();
                        chrono::duration<float> midnsduration = midnsend - midnsstart;
                        cout.setf(ios::fixed);
                        cout << midnsduration.count() << "s" << '\n';
                    }
                    else if (mi == 2)
                    {
                        auto midsstart = chrono::high_resolution_clock::now();
                        int middles = (bar[0] + bar[99]) / 2;
                        cout << "Среднее число массива: " << middles << '\n';
                        int counts = 0;
                        for (int i = 0; i < size; i++)
                        {
                            if (bar[i] == middles)
                            {
                                ++counts;
                                cout << "Индекс " << counts << " числа: " << i << '\n';
                            }
                            if (bar[i] > middles)
                            {
                                break;
                            }
                        }
                        if (counts == 0) {
                            cout << "Такого числа в массиве нет :(" << '\n';
                        }
                        else {
                            cout << counts << '\n';
                        }
                        auto midsend = chrono::high_resolution_clock::now();
                        chrono::duration<float> midsduration = midsend - midsstart;
                        cout.setf(ios::fixed);
                        cout << midsduration.count() << "s" << '\n';
                    }
                    else
                        cout << "Введите 1 или 2!";
                    break;
                }
                case(5): {
                    int sifrmen, countmen = 0;
                    cout << "Введите свое число" << '\n';
                    cin >> sifrmen;
                    int mid = binarySearch(bar, sifrmen, 0, size - 1);
                    if (mid == -1) {
                        cout << "Такого чилсла нет в массиве(" << '\n';
                    }
                    else {
                        cout << size - (size - mid) - 1 << '\n';
                    }
                    break;
                }
                case(6):
                {
                    int sifrbol;
                    cout << "Введите свое число" << '\n';
                    cin >> sifrbol;
                    int mid = binarySearch(bar, sifrbol, 0, size-1);
                    if (mid == -1) {
                        cout << "Такого чилсла нет в массиве(" << '\n';
                    }
                    else {
                        cout << size - mid - 1 << '\n';
                    }
                    break;
                }
                case(7):
                {
                    cout << "Какое число вам найти?" << '\n';
                    int value;
                    cin >> value;
                    auto binstart = chrono::high_resolution_clock::now();
                    int result = binarySearch(bar, value, 0, size - 1);

                    if (result == -1) {
                     cout << "Такого числа нет(" << '\n';
                    }
                    else {
                        cout << "Такое число есть)" << '\n';
                    }
                    auto binend = chrono::high_resolution_clock::now();
                    chrono::duration<float> binduration = binend - binstart;
                    cout.setf(ios::fixed);
                    cout << "Бинарным поиском: " << binduration.count() << "s" << '\n';

                    auto perstart = chrono::high_resolution_clock::now();
                    int per = 0;
                    for (int i = 0; i < size; ++i) {
                        if (arr[i] == value) {
                            per = 1;
                        }
                    }
                    if (per == 0) {
                        cout << "Такого числа нет(" << '\n';
                    }
                    if (per == 1) {
                        cout << "Такое число есть)" << '\n';
                    }
                    auto perend = chrono::high_resolution_clock::now();
                    chrono::duration<float> perduration = perend - perstart;
                    cout.setf(ios::fixed);
                    cout << "Перебором: " << perduration.count() << "s" << '\n';
                    if (perduration > binduration) {
                        chrono::duration<float> razn = perduration - binduration;
                        cout << "Перебором дольше на: " << razn.count() << '\n';
                    }
                    else if (perduration < binduration) {
                        chrono::duration<float> razn = binduration - perduration;
                        cout << "Бинарным поиском дольше на:" << razn.count() << '\n'
                    }
                    else {
                        cout << "Одинаково" << '\n';
                    }
                    break;
                }
                case(8):
                {
                    cout
                        << "В каком массиве?" << '\n'
                        << "1.В отсортированном" << '\n'
                        << "2.В неотсортированном" << '\n';
                    int k;
                    cin >> k;
                    if (k == 1) {
                        int l, d, sr;
                        bubbleSort(bar, size);
                        cout << "Введите 2 индекса, которые хотите поменять: ";
                        cin >> l >> d;
                        auto changestart = chrono::high_resolution_clock::now();
                        sr = bar[l];
                        bar[l] = bar[d];
                        bar[d] = sr;
                        auto changeend = chrono::high_resolution_clock::now();
                        chrono::duration<float> changedur = changeend - changestart;
                        cout.setf(ios::fixed);
                        printArray(bar, size);
                        cout << changedur.count() << "s" << '\n';
                    }
                    else if (k == 2) {
                        int l, d, sr;
                        cout << "Введите 2 индекса, которые хотите поменять: ";
                        cin >> l >> d;
                        anotherArray(arr, size, bar);
                        auto changesstart = chrono::high_resolution_clock::now();
                        sr = bar[l];
                        bar[l] = bar[d];
                        bar[d] = sr;
                        auto changesend = chrono::high_resolution_clock::now();
                        chrono::duration<float> changesdur = changesend - changesstart;
                        cout.setf(ios::fixed);
                        printArray(bar, size);
                        cout << changesdur.count() << "s" << '\n';
                    }
                    else
                        cout << "Введите 1 или 2!";
                    break;

                }
            }
        }


        cout << "Пересоздаем массив или выходим?" << '\n'
            << "1.Выходим(" << '\n'
            << "2.Пересоздать массив)" << '\n';
        cin >> test1;
        if (test1 == 1) {
            bananchiki = 0;
            break;
        }
        else {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
                cout << "";
        }
    }
    return 0;
}
