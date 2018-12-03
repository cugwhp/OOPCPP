#include <iostream>

using namespace std;

void Move(char, char);
void hanoi(int, char, char, char);

int main()
{
    int m;
    cout << "Enter the number of disks: ";
    cin >> m;
    cout << "the steps to moving " << m << " disks:" << endl;
    hanoi(m,'A','B','C');
    return 0;
}

void Move(int n, char src, char dst)
{
    cout << "Move " << n << " from " << src << " -> " << dst << endl;
}

void hanoi(int n, char src, char med, char dst)
{
    if (1 == n)
    {
        Move(n, src, dst);
    }
    else
    {
        hanoi(n-1, src, dst, med);
        Move(n, src, dst);
        hanoi(n-1, med, src, dst);
    }
}
