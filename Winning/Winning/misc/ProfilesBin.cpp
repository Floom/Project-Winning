// Written by Patrick Quintal

#include "ProfilesBin.h"

#include <iostream>
#include <string>
using namespace std;

ProfileBin::ProfileBin()
{

}
ProfileBin::~ProfileBin()
{

}

int ProfileBin::Create(std::string FileName, std::string Extension)
{
	binaryFile.open(FileName + Extension,ios::in|ios::binary);

	if (binaryFile.good())
		return 0;
	else
	{
		binaryFile.open(FileName + Extension,ios::out|ios::binary);
		binaryFile.clear();
		binaryFile.close();
		return 1;
	}
	binaryFile.clear();
	binaryFile.close();
}

int ProfileBin::Load(std::string FileName, std::string Extension, void *obj, int iSize)
{
	binaryFile.open(FileName + Extension,ios::in|ios::binary);

	if(binaryFile.is_open())
	{
		binaryFile.read((char*)obj,iSize);
		binaryFile.clear();
		binaryFile.close();
		return 1;
	}else
	{
		return 0;
		binaryFile.clear();
		binaryFile.close();
	}
}

void ProfileBin::Save(std::string FileName, std::string Extension, void *obj, int iSize)
{
	binaryFile.open(FileName + Extension,ios::in|ios::out|ios::binary);
	if(binaryFile.good())
	{
		binaryFile.write((char*)obj, iSize);
	}
	binaryFile.clear();
	binaryFile.close();
}

