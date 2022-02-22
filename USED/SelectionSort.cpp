/*5.3  选择排序

		a.	简单选择排序
			void SelectionSort(T Data[], int n)

*/

#include <iostream>
using namespace std;

/*
TODO:简单选择排序,排序后Data中元素升序排列
 */
template <class T>
void SelectionSort(T Data[], int n)
{
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(Data[j]<Data[min])
            min=j;
        }
        swap(Data[min],Data[i]);
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
    SelectionSort<int>(a, n); //a为待排序的数组，n为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}
