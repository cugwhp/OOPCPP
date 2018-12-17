#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle
{
public:
    bool setTriangle(float a, float b, float c);
    float TriPrimer();
    float TriArea();
protected:
    bool isTriangle();
private:
    float   a, b, c;
};
#endif // TRIANGLE_H
