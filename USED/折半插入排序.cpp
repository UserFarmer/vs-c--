/*5.1  ��������

		b.	�۰��������
			void BinaryInsertionSort(T Data[], int n)

*/
#include <iostream>
using namespace std;

/*
TODO:�۰��������,ʹ�������Data�е����ݰ���������
 */
template <class T>
void BinaryInsertionSort(T Data[], int n) //���������������ݺʹ�����Ԫ
    //�ظ���
{
    int p;
    for (int i = 1; i < n; i++) { //Data[i]�ǵ�ǰ���ڶԱȵ�Ԫ��
        int lower = 0;
        int higher = i-1;
        p = Data[i]; //����ǰ���ڱȽϵ����ݣ����������еĺ�һ����������ʱ�洢�ı���p��

        while (higher>=lower)
        {
            int mid = (lower + higher) / 2;
            if (Data[mid] > p) {
                higher = mid - 1;
            }
            else {
                lower = mid + 1;
            }
        } //�۰�����ʺϵ�ǰ���ݵ�λ��

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

    BinaryInsertionSort<int>(a, n); //aΪ����������飬10Ϊ����Ĵ�С
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
