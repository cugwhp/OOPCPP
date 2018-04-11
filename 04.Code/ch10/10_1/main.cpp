#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <functional>

using namespace std;

int main()
{
    const int N = 3;
    vector<int> s(N);

    //
    for (int i=0; i<N; i++)
        cin >> s[i];

    //
    transform(s.begin(), s.end(), ostream_iterator<int>(cout, "\t"), negate<int>());
    cout << endl;

    /*
    istream_iterator<int>   it1(cin);
    istream_iterator<int>   it2;
    transform(it1, it2, ostream_iterator<int>(cout, "\t"), negate<int>());
    cout << endl;
    */

    return 0;
}
