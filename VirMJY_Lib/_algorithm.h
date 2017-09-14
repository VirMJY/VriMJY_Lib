#pragma once
#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

namespace vstl
{
    //冒泡排序
    template<typename T>
    void bubbleSort(const T& rhand, size_tp size = 0)
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

    //
}

#endif