#include "KFoldCV.h"

/**************************************************************************************
* Constructor KFoldCV
* Notes: Automatic construct training and testing index-data on class construnction
* INPUT PARAMETERS
*      K           -   int, number of folds
**************************************************************************************/
KFoldCV::KFoldCV(std::string path, int k, int c) {
	numOfFold = k;
	numOfClass = c;
	//create folder for cv
	if (creatFolders(path, numOfFold, numOfClass)) return;
	
	for (int idx = 1; idx <= numOfFold; idx++) {
		//path for each cv
		std::string outputFolder(path + "/cr" + std::to_string(idx));
		
		std::ofstream training_file(outputFolder+ "/" + "training" + ".txt");
		std::ofstream validation_file(outputFolder + "/" + "validation"  + ".txt");

		//read images from all classes
		std::vector<cv::String> filenames;
		for (int class_idx = 0; class_idx < numOfClass; class_idx++) {
			cv::String imgpath = path + "/" + std::to_string(class_idx) + "/*";
			cv::glob(imgpath, filenames);
			srand((unsigned int)time(NULL));
			for (size_t i = 0; i < filenames.size(); ++i) {
				/*cv::Mat img = cv::imread(filenames[i]);
				if (img.empty()) {
					std::cout << "failed to open img" << filenames[i] << std::endl;
					continue;
				}*/
				std::size_t found = filenames[i].find_last_of("\\");
				int random = rand() % 100 + 1; //random number from 1 to 100
				if (random <= 75) {	// 0.75 = 0.6 / (0.2+0.6)
					std::string filename(outputFolder + "/training/" + std::to_string(class_idx) + "/" + filenames[i].substr(found + 1));
					CopyFile(filenames[i].c_str(), filename.c_str(), false);
					//cv::imwrite(outputFolder + "/training/" + std::to_string(class_idx) + "/" + filenames[i].substr(found + 1), img);
					training_file << filenames[i].substr(found + 1) << " label is " << std::to_string(class_idx) << "\n";
				}
				else {
					std::string filename(outputFolder + "/validation/" + std::to_string(class_idx) + "/" + filenames[i].substr(found + 1));
					CopyFile(filenames[i].c_str(), filename.c_str(), false);
					//cv::imwrite(outputFolder + "/validation/" + std::to_string(class_idx) + "/" + filenames[i].substr(found + 1), img);
					validation_file << filenames[i].substr(found + 1) << " label is " << std::to_string(class_idx) << "\n";
				}
			}
		
		}

		training_file.close();
		validation_file.close();
	}
}

KFoldCV::~KFoldCV() {
}

int KFoldCV::creatFolders(std::string path, int k, int c) {
	for (int i = 1; i <= k; i++) {
		std::string dir(path + "/cr" + std::to_string(i));
		std::string dir1(path + "/cr" + std::to_string(i) + "/training");
		std::string dir2(path + "/cr" + std::to_string(i) + "/validation");
		if (CreateDirectory(dir.c_str(), NULL) && CreateDirectory(dir1.c_str(), NULL) && CreateDirectory(dir2.c_str(), NULL))
			for (int idx = 0; idx < c; idx++) {
				std::string classDir1(path + "/cr" + std::to_string(i) + "/training/" + std::to_string(idx));
				std::string classDir2(path + "/cr" + std::to_string(i) + "/validation/" + std::to_string(idx));
				CreateDirectory(classDir1.c_str(), NULL);
				CreateDirectory(classDir2.c_str(), NULL);
			}
		else
			return -1;
	}

	return 0;
	
}

///**************************************************************************************
//* Method getTrainingIndex(int K)
//* Return vector that contain index-data training for given K
//* INPUT PARAMTERS
//*      K       -   Folds-number for training
//* OUTPUT       -   Vector that contain index-data training
//**************************************************************************************/
//
//std::vector<int> KFoldCV::getTrainingIndex(int K) {
//	return mapTraining[K];
//}
//
///**************************************************************************************
//* Method getTestIndex(int K)
//* Return vector that contain index-data testing for given K
//* INPUT PARAMTERS
//*      K       -   Folds-number for testing
//* OUTPUT       -   Vector that contain index-data testing
//**************************************************************************************/
//std::vector<int> KFoldCV::getTestIndex(int K) {
//	return mapTesting[K];
//}