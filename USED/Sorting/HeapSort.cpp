/*5.3  选择排序

		b.	堆排序
			void HeapSort(T Data[], int n)
			void BuildHeap(T Data[], int n)
			void SiftDown(T Data[], int i, int n)

*/

#include <iostream>
using namespace std;

/*
TODO:用来保持以结点i为根的最大堆的性质，n是所有元素的个数,找到i结点的两个孩子的下标.
和左子结点进行比较;和右子结点进行比较;判断是否需要进行调整;递归对子结点进行调整
 */
template <class T>
void SiftDown(T Data[], int i, int n)
{ //i标识父结点
	int j = 2 * i + 1; //标识左子结点
	T temp = Data[i]; //保存父结点的关键码
						   //过筛
	while (j < n)
	{
		if ((j < n - 1) && (Data[j] < Data[j + 1]))
			j++;
		//该结点有右孩子且右孩子的关键码大于左孩子的关键码时，j 指向右子结点
		if (temp<Data[j])
		{ //该结点的关键码小于左右孩子中比较大的那个时
			Data[i] = Data[j]; //交换对应值
			i = j;
			j = 2 * j + 1; //向下继续判断是否满足最大堆的性质
		}
		else break;
	}
	Data[i] = temp;
}
/*
TODO:建立一个最大堆，求出非叶子结点的最大下标,循环调用SiftDown函数，保持最大堆的性质
 */
template <class T>
void BuildHeap(T Data[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        SiftDown(Data, i, n);
}

/*
TODO: 进行堆排序，首先建立一个最大堆，进行循环，次取出最大元素后不断调整最大堆
 排序完成后，使得Data中元素按升序排列
 */
template <class T>
void HeapSort(T Data[], int n)
{
    for (int i = n / 2 - 1; i >= 0;i--)
        BuildHeap(Data, n-i);
    for (int j = n - 1; j > 0;j--)
    {
        swap(Data[0], Data[j]);
        BuildHeap(Data, j);
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
    HeapSort<int>(a, n); //a为待排序的数组，n为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
