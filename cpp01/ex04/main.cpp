#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string str, const std::string& s1, const std::string& s2) {
	if (s1.empty())
		return str;

	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = str.find(s1, pos)) != std::string::npos) {
		result.append(str, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(str, pos, str.length() - pos);

	return result;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return 1;
	}

	std::string content;
	std::string line;
	while (std::getline(infile, line)) {
		content += line;
		if (!infile.eof())
			content += "\n";
	}
	infile.close();

	std::string replaced = replaceAll(content, s1, s2);

	std::string outfilename = filename + ".replace";
	std::ofstream outfile(outfilename.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: could not create file " << outfilename << std::endl;
		return 1;
	}

	outfile << replaced;
	outfile.close();

	return 0;
}
