#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

template <typename T>
class Array
{
public:
    Array();
    Array(T* pt, int sz);
    Array(const Array<T>& rhs);
    ~Array();

    Array<T>& operator=(const Array<T>& rhs);

//    friend Array<T>& operator+(const Array<T>& a, const Array<T>& b);

private:
    T   *ptData;
    int nSize;;
};

template<typename T>
Array<T>::Array()
{
    ptData = 0UL;
    nSize = 0;
}

template<typename T>
Array<T>::~Array()
{
    if (ptData)
        delete[] ptData;
    nSize = 0;
}

template<typename T>
Array<T>::Array(T* pt, int sz)
{
    if (pt!=0UL && sz > 0)
    {
        ptData = new T[sz];
        nSize = sz;
        for (int i=0; i<sz; ++i)
            ptData[i] = pt[i];
    }
    else
    {
        ptData = 0UL;
        nSize = 0;
    }
}

template<typename T>
Array<T>::Array(const Array<T>& rhs)
{
    nSize = rhs.nSize;
    ptData = new T[nSize];
    for (int i=0; i<nSize && ptData!=0UL; i++)
    {
        ptData[i] = rhs.ptData[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if (&rhs != this)
    {
        if (ptData)
        {
            delete[] ptData;
            ptData = 0UL;
        }
        nSize = rhs.nSize;
        ptData = new T[nSize];
        for (int i=0; i<nSize && ptData!=0UL; i++)
        {
            ptData[i] = rhs.ptData[i];
        }
    }

    return *this;
}
#endif // ARRAY_H_INCLUDED

