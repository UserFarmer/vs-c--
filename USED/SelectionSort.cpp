/*5.3  ѡ������

		a.	��ѡ������
			void SelectionSort(T Data[], int n)

*/

#include <iostream>
using namespace std;

/*
TODO:��ѡ������,�����Data��Ԫ����������
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
    SelectionSort<int>(a, n); //aΪ����������飬nΪ����Ĵ�С
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}
