#include "CStatistics.h"
#include <cmath>

CStatistics::CStatistics()
{
    //ctor
}

CStatistics::~CStatistics()
{
    //dtor
}
int CStatistics::calRange(int max,int min)//全距(range)=最大值-最小值
{
    int intAns=0;

    intAns=max-min;

    return intAns;
}
double CStatistics::calRange(double max,double min)//全距(range)=最大值-最小值
{
    double intAns=0;

    intAns=max-min;

    return intAns;
}
int CStatistics::calNumberOfClass(int nubmber,bool blnSturge=false)//組數(number of class)= n<=2^m ,n=資料數量
{
    int intAns=0;
    if(!blnSturge)
    {
        do{
            intAns++;
        }while(pow(2,intAns)<nubmber);
    }
    else
    {
        intAns=ceil(log10(nubmber)*3.32+1);
    }

    return intAns;
}
int CStatistics::calInterval(int range,int number_of_class)//組距(class interval)=全距/組數
{
    int intAns=0;

    intAns=ceil((double)range/number_of_class);//ceil((double)range/number_of_class)

    return intAns;
}
double CStatistics::calInterval(double range,int number_of_class)//組距(class interval)=全距/組數
{
    double intAns=0;

    intAns=(range/number_of_class);//ceil((double)range/number_of_class)

    return intAns;
}
