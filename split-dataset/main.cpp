#include <iostream>
#include "KFoldCV.h"
#include "Basic_Split.h"

using namespace std;

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage : " << argv[0] << std::endl
			<< " --mode(cross_validation or basic_split) path_to_folder K(int) num_of_class(int)"
			<< std::endl;
		cin.get();
		return -1;
	}

	int count = 0;
	std::string mode(argv[++count]);
	if (mode == "--cross_validation") {
		std::string path(argv[++count]);
		int k = atoi(argv[++count]);
		int c = atoi(argv[++count]);
		KFoldCV cv(path, k, c);
		std::cout << "finished";
		cin.get();
	}
	else if (mode == "--basic_split") {
		std::string path(argv[++count]);
		int c = atoi(argv[++count]);
		Basic_Split split(path, c);
		std::cout << "finished";
		cin.get();
	}
	else {
		std::cerr << "Usage : " << argv[0] << std::endl
			<< " mode(cross_validation or basic_split) path_to_folder K(int) num_of_class(int)"
			<< std::endl;
		cin.get();
		return -1;
	}
	
	return 0;
}