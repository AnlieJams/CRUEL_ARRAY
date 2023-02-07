#include <iostream>
#include <time.h>
using namespace std;

//ЗАДАНИЕ 3

void Unoarray(int* arr, int size)
{
    cout << "Нахождение максимального значения в одномерном массиве: " << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << endl;
    }
    cout << endl;
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "\nМаксимальное значение в одномерном массиве: " << max << endl << endl;

    cout << endl << endl;
}
void Dosarray(int** arr, int size) {
    cout << "Нахождение максимального значения в двухмерном массиве;." << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    int max = arr[0][0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    cout << "\nМаксимальное значение во двухмерном массиве: " << max << endl << endl;
    cout << endl << endl;
}

void tresarray(int*** arr, int size) {
    cout << "Нахождение максимального значения в трехмерном массиве;." << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int z = 0; z < size; z++)
            {
                arr[i][j][z] = rand() % 100;
                cout << arr[i][j][z] << "\t";
            }
            cout << endl;
        }
        int max = arr[0][0][0];
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                for (int z = 0; z < size; z++)
                {
                    if (arr[i][j][z] > max)
                    {
                        max = arr[i][j][z];
                    }
                }
            }
        }
        cout << "\nМаксимальное значение в трехмерном  массиве: " << max << endl << endl;
    }

    cout << endl << endl;
}
int main() {

    setlocale(0, "");
    srand(time(0));
    int*** arr;
    int size;
    cout << "Введите число = ";
    cin >> size;
    arr = new int** [size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int* [size];

        for (int j = 0; j < size; j++) {
            arr[i][j] = new int[size];
        }
    }
    Unoarray(**arr, size);
    Dosarray(*arr, size);
    tresarray(arr, size);
    delete[] arr;
    system("pause");
    return 0;

    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                
                arr[j] = arr[j + 1];
                
            }
        }
    }

    
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
