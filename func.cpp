#include "func.h"

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


int square(int n) {
	return n * n;
}

int sqdist(int x1, int y1, int x2, int y2) {
	return square(x1 - x2) + square(y1 - y2);
}

std::string num2str(int n) {
    std::string result;          // string which will contain the result

    std::ostringstream convert;   // stream used for the conversion

    convert << n;      // insert the textual representation of 'Number' in the characters in the stream

    result = convert.str(); // set 'Result' to the contents of the stream

    return result;
}