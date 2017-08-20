#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include "CLib.h"
#include "CStatistics.h"
using namespace std;
/*===================
次數分配表[ frequency distribution table ]
公式定義:
1.全距(range)=最大值-最小值
2.組數(number of class)= n<=2^m ,n=資料數量
3.組距(class interval)=全距/組數
====================*/

int main()
{
    //p2-13,ex2-7
    int data[]={65,82,47,33,14,22,16,81,57,62,21,83,66,43,47,27,36,51,27,19,66,42,38,29,51,27,40,41};

    int number=sizeof(data)/sizeof(int);//數量
    CLib::outputData("data",data,number);
    CLib::outputData("number",number);

    CLib::BubbleSort(data,number);
    CLib::outputData("data_Sort",data,number);

    int range=CStatistics::calRange(data[number-1],data[0]);
    CLib::outputData("range",range);

    int number_of_class=0;
    number_of_class=CStatistics::calNumberOfClass(number,true);//Sturge's法
    CLib::outputData("number of class",number_of_class);

    int class_interval= CStatistics::calInterval(range,number_of_class);
    CLib::outputData("class interval",class_interval);
    //cout << "Hello world!" << endl;
    CLib::pause();
    return 0;
}

