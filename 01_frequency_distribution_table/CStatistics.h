#ifndef CSTATISTICS_H
#define CSTATISTICS_H


class CStatistics
{
    public:
        CStatistics();
        virtual ~CStatistics();
        static int calRange(int max,int min);//全距(range)=最大值-最小值
        static int calNumberOfClass(int nubmber,bool blnSturge);//組數(number of class)= n<=2^m ,n=資料數量;Sturge's法 1+3.32log(n)
        static int calInterval(int range,int number_of_class);//組距(class interval)=全距/組數
    protected:
    private:
};

#endif // CSTATISTICS_H
