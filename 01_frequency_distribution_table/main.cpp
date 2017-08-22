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
4.組中點(class mean)=(min+max)/2
5.樣本平均數(sample mean)=樣本值總和/總個數
6.加權平均數(weight average)=組中點*次數的總和/總個數
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
    CLib::outputData("------------------------------------------------");
    char strdata[400];

    int minvalue=0,maxvalue=0;
    int k=0,count_value=0;;
    float *class_mean = new float[number_of_class];
    int *class_count = new int[number_of_class];
    float sample_mean=0.0f;
    float weight_average=0.0f;
    for(int i=0;i<number_of_class;i++)
    {
        if(i==0)
        {
            minvalue=data[i];
        }
        else
        {
            minvalue=maxvalue+1;
        }
        maxvalue=minvalue+class_interval-1;

        for(int j=0+k;j<number;j++)
        {
           if((data[j]>=minvalue)&&(data[j]<=maxvalue))
           {
               count_value++;
           }
           else
           {
               k=j;
               break;
           }
        }
        class_mean[i]=(minvalue+maxvalue)/2.0;
        class_count[i]=count_value;
        sprintf(strdata,"class[%d]\t%d-%d\t%f\t%d",(i+1),minvalue,maxvalue,(minvalue+maxvalue)/2.0,count_value);
        CLib::outputData(strdata);
        count_value=0;
    }
    CLib::outputData("------------------------------------------------\n");

    for(int i=0;i<number;i++)
    {
        sample_mean+=data[i];
    }
    sample_mean=sample_mean/number;
    CLib::outputData("sample mean",sample_mean);

    for(int i=0;i<number_of_class;i++)
    {
        weight_average+=(class_mean[i]*class_count[i]);
    }
    weight_average=weight_average/number;
    CLib::outputData("weight average",weight_average);

    CLib::pause();
    delete class_mean;
    delete class_count;
    return 0;
}

