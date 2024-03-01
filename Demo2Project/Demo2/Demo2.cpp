#include "Demo2.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <Windows.h>

using namespace std;

int wmain(int argc, wchar_t* argv[])
{
	// Force console to use UTF-8 encoding
	SetConsoleOutputCP(CP_UTF8);

	std::wstring inputFileName;

	if(argc >= 2)
	{
		std::wstring executablePath{ argv[0] };
		inputFileName = argv[1];

		std::wcout << "Executable Path:" << executablePath << std::endl;
	}
	else
	{
		std::wcerr << "Invalid arguments" << std::endl;
		return -1;
	}


	ifstream inputFile(inputFileName);

	if (!inputFile.is_open()) {
		std::wcerr << "Failed to open " << inputFileName << std::endl;
		return -1;

	}

	nlohmann::json jsonDoc;

	try 
	{
		inputFile >> jsonDoc;
		std::string name{ jsonDoc["name"] };
		std::cout << name << std::endl;

		ofstream outputFile("output.txt");
		if(not outputFile)
		{
			std::cerr << "Failed to open output.txt" << std::endl;
			return -1;
		}

		outputFile << name;
		outputFile.close();

		std::cout << "Output written to output.txt" << std::endl;
	}
	catch (const nlohmann::json::parse_error& e) 
	{
		std::cerr << "JSON Parsing error: " << e.what() << std::endl;
		return -1;
	}


	return 0;
}
