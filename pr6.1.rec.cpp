#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
int Number(int* c, const int size ,int& num, int i) {
    if (i < size) {
        if (!(c[i] % 2 == 0 || i % 13 == 0))
            num++; i++;
        Number(c, size, num, i);
    }
    return num;
}
void Create(int* c, const int size, const int Low, const int High, int i)
{
    if (i < size) {
        c[i] = Low + rand() % (High - Low + 1);
        i++;
        Create(c, size, Low, High, i);
    }
}
void Print(int* c, const int size, int i)
{
    if (i < size) {
        cout << setw(4) << c[i];
        i++;
        Print(c, size, i);
    }
}

int Sum(int* c, const int size, int& sum, int i) {
    if (i < size) {
        if (!(c[i] % 2 == 0 || i % 13 == 0)) {
            sum += c[i];             
        }
     i++;
     Sum(c, size, sum, i);
    }
    return sum;
}

void Change(int* c, const int size, int i) {
    if (i < size) {
        if (c[i] % 2 == 0 || i % 13 == 0)
            c[i] = 0; i++;
        Change(c, size, i);
    }
}

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    const int n = 21;
    int c[n];
    int i = 0;
    int num = 0;
    int sum = 0;
    int Low = 15;
    int High = 85;
    Create(c, n, Low, High, i);
    Print(c, n, i);
    cout << endl;
    int number = Number(c, n, num, i);
    cout << "Numbers: ";
    cout << number << endl;
    int suma = Sum(c, n, sum, i);
    cout << "Sum: ";
    cout << suma << endl;
    Change(c, n, i);
    Print(c, n, i);

    return 0;

}