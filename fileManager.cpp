#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include "main.h"
#include "fileManager.h"

void FileManager::Load(const std::string& filePath, std::vector<std::string>* str)
{
	FILE* fp = fopen(filePath.c_str(), "r");
	if (fp == NULL)
	{
		//while (fscanf(fp, "%s"));
	}
}
