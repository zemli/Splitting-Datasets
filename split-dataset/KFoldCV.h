#pragma once

#ifndef KFOLDCV_H
#define KFOLDCV_H
#include <opencv2/opencv.hpp>
#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <fstream>
#include <algorithm>

class KFoldCV
{
public:
	KFoldCV(std::string path, int k, int c);
	virtual ~KFoldCV();

protected:
	int numOfClass;
	int numOfFold;
private:
	int KFoldCV::creatFolders(std::string path, int k, int c);
};
#endif // KFOLDCV_H