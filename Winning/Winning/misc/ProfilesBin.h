// Written by Patrick Quintal

#ifndef PROFILEBIN_H
#define PROFILEBIN_H
#include<fstream>
#include <string>

class ProfileBin
{
private:

public:
	std::fstream binaryFile;
	int Create(std::string FileName, std::string Extension);
	int Load(std::string FileName, std::string Extension, void *obj, int iSize);
	void Save(std::string FileName, std::string Extension, void *obj, int iSize);
	void Read(std::string FileName, std::string Extension, void *obj, int iSize);

	ProfileBin();
	~ProfileBin();
};

#endif