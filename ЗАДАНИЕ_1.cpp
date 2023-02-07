#include <iostream>
#include <ctime>
using namespace std;

//ЗАДАНИЕ 1

const int SIZE = 5;

void Set(int arr[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            arr[i][j] = rand() % 100;
}

void PRINT(int arr[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << arr[i][j] << '\t';
        cout << endl;
    }
}

int LineSearch(int array[][SIZE], int key)
{
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            index++;
            if (array[i][j] == key)
                return index;
        }
    }
    return -1;
}

void main()
{
    setlocale(0, "");

    srand((int)time(0));
    int array[SIZE][SIZE], key;
    Set(array);
    PRINT(array);
    cout << "НУЖНЫЕ НАЙДЕНЫ ";
    cin >> key;

    if (LineSearch(array, key) == -1)
        cout << "\n НЕТУ" << endl;
    else cout << "\n ЭЛЕМЕНТ НАЙДЕН, ЕГО НОМЕРРРР: " << LineSearch(array, key) + 1 << endl;
}