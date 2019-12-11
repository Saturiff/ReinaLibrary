#pragma once
#pragma warning(disable: 4996 6384)
#include <iostream>
#include <Windows.h>
#include <vector>

template <typename T>
void Print1DArray(const char* arrName, T* arr, int size)
{
	printf("%s = ", arrName);
	for (int i = 0; i < size; i++) std::cout << arr[i] << ", ";
	printf("\n");
}

template <typename T>
void Print2DArray(const char* arrName, T** arr, int sizeX, int sizeY)
{
	printf("%s =\n", arrName);
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++) std::cout << arr[i][j] << ", ";
		printf("\n");
	}
	printf("\n");
}

template <typename T1, typename T2>
void ConvertArrayType(T1* src, T2* dst, int size)
{
	if (dst == NULL || dst == nullptr) dst = new T2[size];
	for (int i = 0; i < size; i++) dst[i] = src[i];
}

void Len(const char* s)
{
	printf("s len = %d\n", sizeof(s) / sizeof(*s));
}

// for IDE, console
void PrintDebug(const char* debugMsg)
{
	printf("In function:\"%s\", line: %d, msg:\"%s\"\n", __func__, __LINE__, debugMsg);
}

template <typename... Targs>
void PrintDebug(const char* format, Targs... args)
{
	printf(format, args...);
}

// for DebugView
std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
void OutDebug(const char* debugMsg)
{
	std::string s(debugMsg);
	OutputDebugString(s2ws(s).c_str());
}

template <typename... Targs>
void OutDebug(const char* format, Targs... args)
{
	char buffer[128];
	sprintf_s(buffer, sizeof(buffer), format, args...);
	std::string str(buffer);
	OutputDebugString(s2ws(str).c_str());
}

void PrintDefaultMacro()
{
	printf("line: %d\n", __LINE__);
	printf("file: %s\n", __FILE__);
	printf("function: %s\n", __FUNCTION__);
	printf("function: %s\n", __func__);
	printf("time: %s\n", __TIME__);
	printf("date: %s\n", __DATE__);
	printf("STDC_HOSTED: %d\n", __STDC_HOSTED__);
	printf("TIMESTAMP: %s\n", __TIMESTAMP__);
}
