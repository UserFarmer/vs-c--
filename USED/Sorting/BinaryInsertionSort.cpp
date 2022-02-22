/*5.1  插入排序

        b.	折半插入排序
            void BinaryInsertionSort(T Data[], int n)

*/
#include <iostream>
using namespace std;

/*
TODO:折半插入排序,使得排序后Data中的数据按递增排序
 */
template <class T>
void BinaryInsertionSort(T Data[], int n) //参数：待排序数据和待排序元
    //素个数
{
    int p;
    for (int i = 1; i < n; i++) { //Data[i]是当前正在对比的元素
        int lower = 0;
        int higher = i-1;
        p = Data[i]; //将当前正在比较的数据（已排序数列的后一个）放入暂时存储的变量p中

        while (higher>=lower)
        {
            int mid = (lower + higher) / 2;
            if (Data[mid] > p) {
                higher = mid - 1;
            }
            else {
                lower = mid + 1;
            }
        } //折半查找适合当前数据的位置

        for (int j = i - 1; j > higher; j--) {
            Data[j + 1] = Data[j];
        }
        Data[higher + 1] = p;
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

    BinaryInsertionSort<int>(a, n); //a为待排序的数组，10为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}