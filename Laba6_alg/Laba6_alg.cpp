#include <iostream>
#include <ctime>
#include <iomanip>
#define N 20
using namespace std;
int k = 0;
void inclusionSort(int* num);
void quicksort(int* s_arr, int first, int last);

int main()
{
    setlocale(LC_ALL, "russian");
    srand(time(NULL));
    int a[N], b[N];
    cout << "Изначально: ";
    for (int i = 0; i < N; i++) 
    {
        a[i] = rand() % 201-100;
        b[i] = a[i];
        cout << a[i] << " ";
    }
    cout << endl << endl;
    cout << "#1 сортировка вставками:" << endl;
    inclusionSort(a);
    cout << "Итог: ";
    for (int i = 0; i < N; i++)
        cout << setw(3)<< a[i] << " ";
    cout <<endl<< "Кол-во сравнений: " << k << endl << endl;
    k = 0;
    cout << "Изначально: ";
    for (int i = 0; i < N; i++)
        cout << b[i] << " ";
    cout << endl << endl << "#2 быстрая сортировка:" << endl;;
    quicksort(b, 0, N - 1);
    cout << "Итог: ";
    for (int i = 0; i < N; i++)
        cout << setw(3) << b[i] << " ";
    cout << endl;
    cout << "Кол-во сравнений: " << k << endl;
    system("pause");
    return 0;
}

void quicksort(int* a, int first, int last)
{
    if (first < last)
    {
        k++;
        int left = first, right = last, middle = a[(left + right) / 2];
        while (left <= right)
        {
            k++;
            while (a[left] < middle) { left++; k++; } //Идем слева массива пока элемнт меньше опорного
            while (a[right] > middle) { right--; k++; } //Идем справа пока элемент больше опорнного
            if (left <= right) //если индекс слева меньше или равен индексу справа, то меняем их местами
            {
                int tmp = a[left]; 
                a[left] = a[right];
                a[right] = tmp;
                left++;//сдвигамем индекс слева на 1
                right--;//сдвигамем индекс справа на 1
                k++;
            }
            for (int i = 0; i < N; i++)
            {
                cout << setw(3) << a[i] << " ";
            }
            cout << "\tОпорный: " << setw(3) << middle << endl;
        } 
        quicksort(a, first, right); //рекурсинвно вызываем эту функцию для левой части
        quicksort(a, left, last); //рекурсивно вызываем эту функцию для правой части
    }
}

void inclusionSort(int* a)
{
    for (int i = 1; i < N; i++) // Для всех элементов кроме начального
    {
        k++;
        int value = a[i]; // запоминаем значение элемента
        int index = i;     // и его индекс
        while (index > 0 && a[index - 1] > value)
        {   
            a[index] = a[index - 1]; // смещаем другие элементы к концу массива пока они меньше index
            index--; // смещаем просмотр к началу массива
            k+=2;
        }
        a[index] = value; // рассматриваемый элемент помещаем на освободившееся место
        cout << setw(3) << i << ": ";
        for (int i = 0; i < N; i++)
            cout << setw(3) << a[i] << " ";
        cout << endl;
    }
}