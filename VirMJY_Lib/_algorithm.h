#pragma once
#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

namespace vstl
{
    //冒泡排序
    template<typename T>
    void bubbleSort(T* rhand, size_tp size = 0)
    {
        if(size <= 0)   return;

        auto temp = rhand[0];
        size tp n = size;
        //Core
        for(int i = 0; i < n-1; ++i)
        {
            if(rhand[i] > rhand[i+1])
            {
                temp = rhand[i];
                rhand[i] = rhand[i + 1];
                rhand[i + 1] = temp;
            }
        }
    }

    //快速排序
    template<typename T>
    void qsort(T* rhand, idx_tp start, idx_tp end)
    {
        if(start > end)
            return;

        indx_tp mid = start + end >> 1;
        T temp = rhand[end];
        rhand[end] = rhand[mid];
        rhand[mid] = temp;

        int i = start, j = end;
        while(i < mid && end > mid)
        {
            while(rhand[mid] > rhand[start])
            {
                ++i;
            }
            while(rhand[mid] <= rhand[end] )
            {
                --j;
            }
            temp = rhand[start];
            rhand[start] = rhand[end];
            rhand[end] = temp;
        }

        qsort(rhand, start, mid-1);
        qsort(rhand, mid-1, end);
    }

    //相加不使用加减乘除 适用于unsigned int/shor/char
    unsigned long long add(unsigned long long lhand, unsigned long long rhand)
    {
        if(lhand == 0 || rhand == 0)
            return lhand|rhand;

        unsigned long long and = lhand&rhand;
        unsigned long long xor = lhand^rhand;
        and << 1;

        return add(and, xor);
    }

    //字符串翻转  E : string ->gnirts 
    void reverse(char* _str, idx_tp start, idx_tp end)
    {   
        while(start < end)
        {
            char temp = _str[start];
            _str[start] = _str[end];
            _str[end] = temp;

            ++start;
            --end;
        }
    }

    //字符串翻转 E : this is a string. -> .string a is this
    void __Reverse(char* _str)
    {
        size_tp size = Strlen(_str);
        if(size <= 0)   return;

        idx_tp start = 0;
        idx_tp temp = start;
        idx_tp end = size;

        while(temp < end)
        {
            while(_str[temp] != ' ' && temp < end)
            {
                ++temp;
            }
            reverse(_str, start, temp-1);
            ++temp;
            start = temp;
        }

        reverse(_str, 0, end);
    }
}

#endif