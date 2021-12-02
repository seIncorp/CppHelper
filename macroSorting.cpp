#include "fast.h"


/**********************************************************************************************/
/* Top-down implementation */
void top_down_merge_sort(int a_arr[], int b_arr[], int len)
{
    for (int k = 0; k < len; k++)
        b_arr[k] = a_arr[k];

    top_down_split_and_merge(b_arr, 0, len, a_arr);
}

void top_down_split_and_merge(int b_arr[], int begin, int end, int a_arr[])
{
    if (end - begin <= 1)
        return;

    int middle = (end + begin) / 2;              

    top_down_split_and_merge(a_arr, begin, middle, b_arr);  
    top_down_split_and_merge(a_arr, middle, end, b_arr);  

    top_down_merge(b_arr, begin, middle, end, a_arr);
}

void top_down_merge(int a_arr[], int begin, int middle, int end, int b_arr[])
{
    int ii = begin, jj = middle;

    for (int k = begin; k < end; k++)
    {
        if ((ii < middle) && (jj >= end || a_arr[ii] <= a_arr[jj]))
        {
            b_arr[k] = a_arr[ii];
            ii++;
        }
        else
        {
            b_arr[k] = a_arr[jj];
            jj++;
        }
    }
}

/**********************************************************************************************/
/* Bottom-up implementation */
void bottom_up_merge_sort(int a_arr[], int b_arr[], int len)
{
    for (int width = 1; width < len; width = 2 * width)
    {
        for (int ii = 0; ii < len; ii = ii + 2 * width)
            bottom_up_merge(a_arr, ii, fmin(ii + width, len), fmin(ii + 2 * width, len), b_arr);

        for (int ii = 0; ii < len; ii++)
            a_arr[ii] = b_arr[ii];
    }
}

void bottom_up_merge(int a_arr[], int left, int right, int end, int b_arr[])
{
    int ii = left, jj = right;

    for (int k = left; k < end; k++)
    {
        if ((ii < right) && (jj >= end || a_arr[ii] <= a_arr[jj]))
        {
            b_arr[k] = a_arr[ii];
            ii++;
        }
        else
        {
            b_arr[k] = a_arr[jj];
            jj++;
        }
    }
}















