#ifndef ARRAY_H
#define ARRAY_H

template<class T>
class Array<T>
{
public:
    Array();
    virtual ~Array();

    void Append(const T& t);
    T operator[](int i);



protected:
    bool IsEmpty() const;
    bool IsFull() const;
private:
    T*  m_pData;
    int m_nCount;
};


template<class T>
Array<T>::Array()
{

}

template<class T>
Array<T>::~Array()
{

}

template<class T>
void Array<T>::Append(const T& t)
{
    if (IsFull())
    {
        CreateNewMem();

        CopyData();

        FreeOld();
    }
}

#endif // ARRAY_H
