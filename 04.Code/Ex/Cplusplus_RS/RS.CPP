#include <iostream>
using namespace std;

void Usage(void);

int main()
{
	// 显示提示信息
	Usage();

	char	chTxt;
	do
	{
		cin >> chTxt;
		switch(chTxt)
		{
		case 'O':	//Open Image
		case 'o':
		case '1':
			break;
		case 'C':	//Close Image
		case 'c':
			break;
		case 'A':	//Save as file
		case 'a':
			break;
		case 'S':
		case 's':
			break;
		case 'R':
		case 'r':
			break;
		case 'Z':
		case 'z':
			break;
		case 'F':
		case 'f':
			break;
		case 'X':
		case 'x':
			exit(0);

		default:
			Usage();
			break;
		}
	}while(true);

	return 0;
}

void Usage(void)
{
	cout << endl;
	cout << "####### Remote Sensing Image Process Programming (RSIPP)######" << endl;
	cout << "##Menu\t\t\t\t\t##" << endl;
	cout << "1. O - Open Image <srcpath>" << endl;
	cout << "2. C - Close Image" << endl;
	cout << "3. A - Save as file <dstpath>" << endl;
	cout << "4. S - Statistics of the image" << endl;
	cout << "5. R - Rotate image <angle (0°--360°)>" << endl;
	cout << "6. Z - Zoom image <scale (01.--10)>" << endl;
	cout << "7. F - Filetering image <Filter Kernel matrix>" << endl;
	cout << "8. X - Exit" << endl;
	cout << "##################### End of Usage #########################" << endl;
}