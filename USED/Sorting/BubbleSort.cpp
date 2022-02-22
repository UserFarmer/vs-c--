/*5.2  交换排序

        a.	冒泡排序
            void BubbleSort(T Data[], int n)
*/
#include <iostream>
using namespace std;

/*
TODO:冒泡排序,排序后Data中元素为升序排列
 */
template <class T>
void BubbleSort(T Data[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (Data[j] > Data[j+1])
                swap(Data[j], Data[j + 1]);
        }
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
    BubbleSort<int>(a, n); //a为待排序的数组，n为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
