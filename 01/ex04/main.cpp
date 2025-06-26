#include <string>
#include <iostream>
#include <fstream>

std::string my_replace(const std::string& s1, const std::string& s2, const std::string& line)
{
	std::string newLine;
	size_t pos = 0;
	size_t start = 0;

	while ((pos = line.find(s1, start)) != std::string::npos)
	{
		newLine += line.substr(start, pos - start);
		newLine += s2;
		start = pos + s1.length();
	}
	newLine += line.substr(start);
	return (newLine);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cerr << "Need <filename> <s1> <s2>" << std::endl, 1);
	
	std::ifstream file(argv[1], std::ios::in);
	std::ofstream newFile("newFile", std::ios::out);
	if (!file || !newFile)
		return (std::cerr << "Error opening file." << std::endl, 1);
	
	std::string line;
	while (std::getline(file, line))
	{
		std::string newLine = my_replace(argv[2], argv[3], line);
		newFile << newLine << "\n";
	}
	file.close();
	newFile.close();
	return (0);
}
