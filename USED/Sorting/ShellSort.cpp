/*5.1  插入排序

    c.	希尔排序
        void ShellSort(T Data[], int n)

*/
#include <iostream>
using namespace std;

/*
TODO:希尔排序,排序后使得Data中元素为升序排列
 */
template <class T>
void ShellSort(T Data[], int n)
{
    int p = 1;
    while (p<n/3)
    {
        p = 3 * p + 1;
    }
    while (p>=1)
    {
        for (int i = p; i < n; i++) {
            for (int j = i; j >= p && Data[j] < Data[j - p]; j -= p) {
                swap(Data[j], Data[j - p]);
            }
        }
        p = p / 3;
    }
}

int main()
{
    int n, num;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }

    ShellSort<int>(a, n); //a为待排序的数组，n为数组的大小
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
