#include "CLib.h"
#include <cstdio>
CLib::CLib()
{
    //ctor
}

CLib::~CLib()
{
    //dtor
}
//元素互換
void CLib::Swap(int* array, int x, int y)
{
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}
//氣泡排序
void CLib::BubbleSort(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 1; j < size - i; j++)
        {
            if(array[j] < array[j - 1])
            {
                Swap(array, j, j - 1);
            }
        }
    }
}
void CLib::outputData(char *str)
{
    printf("%s\n",str);
}
void CLib::outputData(char *title,int data)
{
    printf("%s: %d\n",title,data);
}
void CLib::outputData(char *title,float data)
{
    printf("%s: %f\n",title,data);
}
void CLib::outputData(char *title,int* data,int number)
{

    printf("%s:",title);
    for(int i=0;i<number;i++)
    {
        printf("%d,",data[i]);
    }
    printf("\n");
}
void CLib::pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
