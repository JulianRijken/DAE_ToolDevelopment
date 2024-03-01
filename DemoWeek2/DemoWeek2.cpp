#include "DemoWeek2.h"
#include <filesystem>

using namespace std;

int main()
{
	cout << "Current Directory:" << filesystem::current_path() << endl;

	return 0;
}
