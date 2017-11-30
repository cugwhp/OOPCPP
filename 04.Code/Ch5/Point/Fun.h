#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED

int Add(int a, int b);
int Sub(int a, int b);
int Mul(int a, int b);
int Div(int a, int b);
int Pwr(int a, int b);
int Mod(int a, int b);

class X;    //dec

class Y
{
public:
    void g(X* px);  //X*->sizeof(X*)=4bytes
};

class X
{
public:
    X(int i=0);
    ~X();
public:
    void show();
    friend void Y::g(X*);   //sizeof(Y)???
private:
    int    m_i;
};


#endif // FUN_H_INCLUDED
