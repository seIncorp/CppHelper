#include "fast.h"

int cartesianProduct(int a[], int a_len, int b_len, int b[], int* ret)
{
    if (a_len == 0 || b_len == 0)
        return 1;

    for (size_t ii = 0; ii < a_len; ii++)
        for (size_t jj = 0; jj < a_len; jj++)
            for (size_t xx = 0; xx < 2; xx++)
            {
                if (xx == 0)
                    ret[OFFSET_3D_ARRAY_ONE_POINTER(a_len, a_len, 2, ii, jj, xx)] = *(a + ii);
                else
                    ret[OFFSET_3D_ARRAY_ONE_POINTER(a_len, a_len, 2, ii, jj, xx)] = *(b + jj);
            }

    return 0;
}

void power_set(int os[], int len)
{
    int noc = pow(2, len);

    for (int ci = 0; ci < noc; ci++)
    {
        for (int si = 0; si < len; si++)
        {
            if (ci & (1 << si))
            {
                o << "-- " << os[si] << " ";
            }
        }
        ee;
    }
}

void fisherYates(int originalArray[], int len_original, int res[])
{
    for (int aa = 0; aa < len_original; aa++)
        res[aa] = originalArray[aa];

    for (int ii = (len_original - 1); ii > 0; ii -= 1)
    {
        int randomIndex = floor(rand() % (ii + 1));

        int temp = res[ii];
        res[ii] = res[randomIndex];
        res[randomIndex] = temp;
    }
}

string longest_common_subsequence(string set1, int set1_len, string set2, int set2_len)
{
    int lcsMatrix[set2_len + 1][set1_len + 1];

    for (int columnIndex = 0; columnIndex <= set1_len; columnIndex += 1)
        lcsMatrix[0][columnIndex] = 0;

    for (int rowIndex = 0; rowIndex <= set2_len; rowIndex += 1)
        lcsMatrix[rowIndex][0] = 0;

    for (int rowIndex = 1; rowIndex <= set2_len; rowIndex += 1)
    {
        for (int columnIndex = 1; columnIndex <= set1_len; columnIndex += 1)
        {
            if (set1[columnIndex - 1] == set2[rowIndex - 1])
            {
                lcsMatrix[rowIndex][columnIndex] = lcsMatrix[rowIndex - 1][columnIndex - 1] + 1;
            }
            else
            {
                lcsMatrix[rowIndex][columnIndex] = fmax(
                    lcsMatrix[rowIndex - 1][columnIndex],
                    lcsMatrix[rowIndex][columnIndex - 1]
                );
            }
        }
    }

    if (!lcsMatrix[set2_len][set1_len])
    {
        return "";
    }

    string longestSequence = "";
    int columnIndex = set1_len;
    int rowIndex = set2_len;

    while (columnIndex > 0 || rowIndex > 0)
    {
        if (set1[columnIndex - 1] == set2[rowIndex - 1])
        {
            longestSequence = set1[columnIndex - 1] + longestSequence;

            columnIndex -= 1;
            rowIndex -= 1;
        }
        else if (lcsMatrix[rowIndex][columnIndex] == lcsMatrix[rowIndex][columnIndex - 1])
        {
            columnIndex -= 1;
        }
        else
        {
            rowIndex -= 1;
        }
    }

    return longestSequence;
}

int* longest_increasing_subsequence(int X[], int len)
{
    int P[len]{ 0 };
    int M[len + 1]{ 0 };

    int L = 0;
    for (int ii = 0; ii < len; ii++)
    {
        int lo = 1;
        int hi = L + 1;
        while (lo < hi)
        {
            int mid = lo + floor((hi - lo) / 2);
            if (X[M[mid]] < X[ii])
                lo = mid + 1;
            else
                hi = mid;
        }

        int newL = lo;

        P[ii] = M[newL - 1];
        M[newL] = ii;

        if (newL > L)
            L = newL;
    }

    int* S = new int[L];

    int k = M[L];
    for (int ii = L - 1; ii >= 0; ii--)
    {
        S[ii] = X[k];
        k = P[k];
    }

    return S;
}

int longest_increasing_subsequence_length(int X[], int len)
{
    int lengthsArray[len]{ 0 };

    for (int ii = 0; ii < len; ii++)
        lengthsArray[ii] = 1;

    int previousElementIndex = 0;
    int currentElementIndex = 1;

    while (currentElementIndex < len)
    {
        if (X[previousElementIndex] < X[currentElementIndex])
        {
            int newLength = lengthsArray[previousElementIndex] + 1;

            if (newLength > lengthsArray[currentElementIndex])
                lengthsArray[currentElementIndex] = newLength;
        }

        previousElementIndex++;

        if (previousElementIndex == currentElementIndex)
        {
            currentElementIndex += 1;
            previousElementIndex = 0;
        }
    }

    int longestIncreasingLength = 0;

    for (int ii = 0; ii < len; ii += 1)
        if (lengthsArray[ii] > longestIncreasingLength)
            longestIncreasingLength = lengthsArray[ii];

    return longestIncreasingLength;
}













