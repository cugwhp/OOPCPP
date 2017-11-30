#ifndef CPOINT_H
#define CPOINT_H


class CPoint
{
    public:
        CPoint();
        virtual ~CPoint();

        void ShowCount();

    protected:
        static int      m_nCount;

    private:
};

#endif // CPOINT_H
