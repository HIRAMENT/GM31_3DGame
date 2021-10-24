#pragma once
#include "singleton.h"
#include <vector>
#include <string>

class FileManager : public Singleton<FileManager>
{
public:
	friend class Singleton<FileManager>;

	void Load(const std::string& filePath, std::vector<std::string>* str);


protected:
	FileManager() {}
	virtual ~FileManager() {}
};