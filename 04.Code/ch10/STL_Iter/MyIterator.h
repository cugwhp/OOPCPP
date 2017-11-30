#ifndef _MYITERATOR_H_
#define _MYITERATOR_H_

template <typename I, typename T>
void fun_impl(I iter, T& a)
{
	*iter = a;
}

template <typename I>
void fun(I iter)
{
	fun_impl(iter, *iter);
}


template<typename T>
struct MyIterator_traits
{
	typedef T value_type;
};

template<typename T>
struct MyIterator_traits<T*>
{
	typedef T value_type;
};

template<typename T>
typename MyIterator_traits<T>::value_type
fun2(MyIterator_traits<T> iter)
{
	return *iter;
}

#endif	//#ifndef _MYITERATOR_H_