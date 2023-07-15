#include <iostream>
#include <time.h>

const int ARRAY_SIZE = 10;
const int MAX_NUM = 99;

void InitArray(int *array);
void HeapSort(int *array);

int main()
{
    int array[ARRAY_SIZE];

    InitArray(array);
    HeapSort(array);

    return 0;
}

void PrintArray(int array[])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
        std::cout << array[i] << ", ";

    std::cout << std::endl;
}

void InitArray(int *array)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++)
        array[i] = rand() % MAX_NUM + 1;

    std::cout << "初期値" << std::endl;
    PrintArray(array);
}

void Swap(int *array, int x, int y)
{
    int tmp = array[x];
    array[x] = array[y];
    array[y] = tmp;
}

void DownHeap(int *array, int root, int size)
{
    int parent = root;
    int child = parent * 2 + 1;

    while (child <= size)
    {
        if ((child < size) && (array[child] < array[child + 1]))
        {
            child++;
        }

        if (array[parent] < array[child])
        {
            Swap(array, parent, child);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int *array)
{
    for (int i = ARRAY_SIZE / 2 - 1; i >= 0; i--)
    {
        DownHeap(array, i, ARRAY_SIZE - 1);
    }

    for (int i = ARRAY_SIZE - 1; i >= 0; i--)
    {
        Swap(array, 0, i);
        DownHeap(array, 0, i - 1);

        std::cout << ARRAY_SIZE - i << "回目のソート" << std::endl;
        PrintArray(array);
    }
}