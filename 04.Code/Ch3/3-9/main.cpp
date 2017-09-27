/******************************************************************************
 * PPT 例3-9
 *****************************************************************************/

#include <iostream>

using namespace std;

/// 递归组合
int comm(int n, int k)
{
    /// n个人分为2组，一组n-1个人，另一组1人。
    /// 若新增的1人选不选为例，若选，则为C(n-1,k-1)；若不选，则为C(n-1,k)
    /// 故：C(n,k) = C(n-1,k) + C(n-1,k-1)
    if (k > n)
        return 0;
    else if (n == k || k == 0)
        return 1;
    else
        return comm(n - 1, k) + comm(n - 1, k - 1);
}

int main()
{
    int comm(int n, int k);
    int n, k;
    cout << "Please enter two integers n and k: ";
    cin >> n >> k;

    cout << "C(n, k) = " << comm(n, k) << endl;

    return 0;
}
