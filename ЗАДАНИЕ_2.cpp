#include <cstdlib>
#include <iostream>
using namespace std;

//ЗАДАНИЕ 2

template <typename vectorT>
void quick_sort(vectorT& v, const int a, const int b) {
    int i = a, j = b;

    int x = v[(i + j) / 2];
    do {
        while (v[i] < x) ++i;
        while (v[j] > x) --j;

        if (i <= j) {
            if (i < j) swap(v[i], v[j]);
            ++i, --j;
        }
    } while (i <= j);

    if (i < b) quick_sort(v, i, b);
    if (a < j) quick_sort(v, a, j);
}

template <typename vectorT>
bool bin_search(vectorT& v, int size, int x) {
    int l = 0, r = size - 1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (x < v[m]) {
            r = m - 1;
        }
        else if (x > v[m]) {
            l = m + 1;
        }
        else {
            return true;
        }
    }

    return false;
}
template <typename T, const int N, const int M>
class matrix {
public:
    T& operator[](int i) {
        return at(i);
    }

    T& at(int i) {
        return a[i / M][i % M];
    }

    T& at(int x, int y) {
        return a[x][y];
    }

private:
    T a[N][M];
};

int main() {
    setlocale(0, "");
    srand((int)time(0));
    const int m_size = 3;
    matrix<int, m_size, m_size> m;

    for (int i = 0; i < m_size * m_size; ++i)
        m.at(i) = rand() % 100;

    quick_sort(m, 0, m_size * m_size - 1);

    for (;;) {
        for (int i = 0; i < m_size; ++i) {
            cout << "( ";
            for (int j = 0; j < m_size; ++j)
                cout << m.at(i, j) << " ";
            cout << ")\n";
        }

        int n;
        cin >> n;
        if (n == 0) break;

        if (bin_search(m, m_size * m_size, n)) {
            cout << "ЕСТЬ" << endl;
        }
        else {
            cout << "НЕМА" << endl;
        }
    }

    return 0;
}