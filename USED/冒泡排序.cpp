/*5.2  ��������

		a.	ð������
			void BubbleSort(T Data[], int n)
*/
#include <iostream>
using namespace std;

/*
TODO:ð������,�����Data��Ԫ��Ϊ��������
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
    BubbleSort<int>(a, n); //aΪ����������飬nΪ����Ĵ�С
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
