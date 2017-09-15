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
}

#endif