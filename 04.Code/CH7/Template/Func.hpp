#ifndef FUNC_HPP_INCLUDED
#define FUNC_HPP_INCLUDED

template <typename T>
void sort(T* pBeg, T* pEnd)
{
    if (pBeg==0L || pEnd==0L || pBeg>pEnd)
        return;

    T*   p1;
    T*   p2;
    T    tmp;

    for (p1=pBeg; p1<pEnd; ++p1)
    {
        for (p2=p1+1; p2<pEnd; ++p2)
        {
            if (*p1 < *p2)
            {
                tmp = *p1;
                *p1 = *p2;
                *p2 = tmp;
            }
        }
    }

    return;
}
#endif // FUNC_HPP_INCLUDED
