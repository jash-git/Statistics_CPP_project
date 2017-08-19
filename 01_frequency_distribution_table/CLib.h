#ifndef CLIB_H
#define CLIB_H


class CLib
{
    public:
        CLib();
        virtual ~CLib();
        static void Swap(int* array, int x, int y);
        static void BubbleSort(int* array, int size);
        static void outputData(char *title,int data);
        static void outputData(char *title,int* data,int number);
        static void pause();
    protected:
    private:
};

#endif // CLIB_H
