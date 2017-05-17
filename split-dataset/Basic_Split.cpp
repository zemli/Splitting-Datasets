#include "Basic_Split.h"



Basic_Split::Basic_Split(std::string path, int c)
{
	if (creatFolders(path, c)) return;
	std::string trainDir(path + "/training");
	std::string testDir(path + "/test");

	std::ofstream training_file(trainDir + "/" + "training" + ".txt");
	std::ofstream test_file(testDir + "/" + "test" + ".txt");

	std::vector<cv::String> filenames;
	for (int class_idx = 0; class_idx < c; class_idx++) {
		cv::String imgpath = path + "/" + std::to_string(class_idx) + "/*";
		cv::glob(imgpath, filenames);
		srand((unsigned int)time(NULL));
		for (size_t i = 0; i < filenames.size(); ++i) {
			//cv::Mat img = cv::imread(filenames[i]);
			//if (img.empty()) {
			//	std::cout << "failed to open img" << filenames[i] << std::endl;
			//	continue;
			//}
			std::size_t found = filenames[i].find_last_of("\\");
			int random = rand() % 100 + 1; //random number from 1 to 100
			if (random <= 80) {
				std::string filename(trainDir + "/" + std::to_string(class_idx) + "/" + filenames[i].substr(found + 1));
				CopyFile(filenames[i].c_str(), filename.c_str(), false);
				//cv::imwrite(trainDir + "/" + std::to_string(class_idx) + "/" + filenames[i].substr(found + 1), img);
				training_file << filenames[i].substr(found + 1) << " label is " << std::to_string(class_idx) << "\n";
			}
			else {
				std::string filename(testDir + "/" + std::to_string(class_idx) + "/" + filenames[i].substr(found + 1));
				CopyFile(filenames[i].c_str(), filename.c_str(), false);
				//cv::imwrite(testDir + "/" + std::to_string(class_idx) + "/" + filenames[i].substr(found + 1), img);
				test_file << filenames[i].substr(found + 1) << " label is " << std::to_string(class_idx) << "\n";
			}
		}
	}
}


Basic_Split::~Basic_Split()
{
}

int Basic_Split::creatFolders(std::string path, int c) {
	std::string dir1(path +  "/training");
	std::string dir2(path + "/test");
	if (CreateDirectory(dir1.c_str(), NULL) && CreateDirectory(dir2.c_str(), NULL)) {
		for (int idx = 0; idx < c; idx++) {
			std::string classDir1(path + "/training/" + std::to_string(idx));
			std::string classDir2(path + "/test/" + std::to_string(idx));
			CreateDirectory(classDir1.c_str(), NULL);
			CreateDirectory(classDir2.c_str(), NULL);
		}
		return 0;
	}
	else return -1;
}
