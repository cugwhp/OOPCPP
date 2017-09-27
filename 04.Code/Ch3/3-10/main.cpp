#include <iostream>

using namespace std;

void Move(char, char);
void hanoi(int, char, char, char);

int main()
{
    int m;
    cout << "Enter the number of diskes: ";
    cin >> m;
    cout << "the steps to moving " << m << " diskes:" << endl;
    hanoi(m,'A','B','C');
    return 0;
}

void Move(char src, char dst)
{
    cout << "Move " << src << " -> " << dst << endl;
}

void hanoi(int n, char src, char med, char dst)
{
    if (1 == n)
    {
        Move(src, dst);
    }
    else
    {
        hanoi(n-1, src, dst, med);
        Move(src, dst);
        hanoi(n-1, med, src, dst);
    }
}
