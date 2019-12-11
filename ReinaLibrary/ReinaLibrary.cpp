#include "ReinaLibrary.h"

#define LIB_MAIN
#ifdef LIB_MAIN

int main()
{
	// debug message
	PrintDefaultMacro();
	PrintDebug("this is a debug message");
	PrintDebug("In function:\"%s\", line: %d, msg:\"%s\"\n", __func__, __LINE__, "this debug message use template");
	OutDebug("this is a debug message to DebugViewer");
	OutDebug("In function:\"%s\", line: %d, msg:\"%s\"\n", __func__, __LINE__, "this is a debug message use template to DebugViewer");

	// misc
	Len("1234");

	// array
	int size = 3;
	int* a = new int[size];
	for (int i = 0; i < size; i++) a[i] = i;
	Print1DArray<int>("a", a, size);

	int sizeX = 3, sizeY = 3;
	int** b = new int*[sizeX];
	for (int i = 0; i < sizeX; i++) b[i] = new int[sizeY];
	for (int i = 0; i < sizeX; i++) for (int j = 0; j < sizeY; j++) b[i][j] = i * 3 + j;
	Print2DArray<int>("b", b, sizeX, sizeY);
	system("pause");

	return 0;
}
#endif // MAIN
