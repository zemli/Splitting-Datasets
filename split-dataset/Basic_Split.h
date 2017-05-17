#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <opencv2/opencv.hpp>

class Basic_Split
{
public:
	Basic_Split(std::string path, int c);
	~Basic_Split();

protected:
	int Basic_Split::creatFolders(std::string path, int c);
};

