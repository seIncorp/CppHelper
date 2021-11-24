#include "fast.h"   

void combinations_Without_Repetitions(int n[], int len, int c_len)
{
    // {1,2,3}
    o << "[ ";
    for (int aa = 0; aa < len; aa++)
        o << n[aa] << " ";
    o << "]" << e;
    ee;

    int temp[c_len];

    combinations_Without_Repetitions_subpart(n, temp, 0, len - 1, 0, c_len);
    ee;
}

void combinations_Without_Repetitions_subpart(int arr[], int temp[], int start, int end, int index, int c_len)
{
    if (index == c_len)
    {
        for (int j = 0; j < c_len; j++)
            o << temp[j] << " ";
        o << e;
        return;
    }

    for (int ii = start; ii <= end && (end - ii + 1) >= (c_len - index); ii++)
    {
        temp[index] = arr[ii];
        combinations_Without_Repetitions_subpart(arr, temp, ii + 1, end, index + 1, c_len);
    }
}

void combinations_With_Repetitions(int n[], int len, int c_len)
{
    o << "[ ";
    for (int aa = 0; aa < len; aa++)
        o << n[aa] << " ";
    o << "]" << e;
    ee;

    int temp[c_len];

    combinations_With_Repetitions_subpart(n, temp, 0, len - 1, 0, c_len);
    ee;

}

void combinations_With_Repetitions_subpart(int arr[], int temp[], int start, int end, int index, int c_len)
{
    if (index == c_len)
    {
        for (int j = 0; j < c_len; j++)
            o << temp[j] << " ";
        o << e;
        return;
    }

    for (int ii = start; ii <= end; ii++)
    {
        temp[index] = arr[ii];
        combinations_With_Repetitions_subpart(arr, temp, ii, end, index + 1, c_len);
    }
}