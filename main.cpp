#include <iostream>
#include "SiteMan.h"
#include "Program.h"



int main(int argc, const char* argv[]) 
{
	if (argc < 2) {
		std::cerr << "Please specify the filename !" << std::endl;
		return 1;
	}

	SiteMan* siteman = new SiteMan();
	Program* p = new Program();

	const char* filename = argv[1];

	int ret = siteman->parse(filename);
	if (ret != 0) {
		std::cerr << "An error occured during file parsing." << std::endl;
		return ret;
	}

	std::cout << "Parsing successfully done !" << std::endl;

	std::cout << "Creating linear program..." << std::endl;
	ret = p->build(siteman);
	if (ret == 0)
		std::cout << "Linear program successfully built !" << std::endl;
	else {
		std::cerr << "An error occured during program building." << std::endl;
		return ret;
	}

	std::cout << "Solving program..." << std::endl;
	std::cout << "Result: [" << p->solve() << "]" << std::endl;

	delete p;
	delete siteman;
}
