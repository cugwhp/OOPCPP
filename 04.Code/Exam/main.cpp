#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ofstream out("chars.txt");
	if(!out)
	{
		cerr << "不能打开输出文件" << endl;
		exit(0);
	}
	unsigned char ch;
	for(ch=0; ch<=255; ch++)
        out << ch << endl;
	out.close();

	return 1;
}
