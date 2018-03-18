#ifndef FUNC_HPP_INCLUDED
#define FUNC_HPP_INCLUDED

template <class T>
void sort(T* pAry, int n)
{
    if (pAry = 0L)
        return;

    T   tmp;
    int i, j;

    for (i=0; i<n; ++i)
    {
        for (j=i+1; j<n; ++j)
        {
            if (pAry[i] < pAry[j])
            {
                tmp = pAry[i];
                pAry[i] = pAry[j];
                pAry[j] = tmp;
            }
        }
    }

    return;
}
#endif // FUNC_HPP_INCLUDED
