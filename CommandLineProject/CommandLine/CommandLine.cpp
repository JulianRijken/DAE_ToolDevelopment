#include "CommandLine.h"
#include <nlohmann/json.hpp>
//#include <glm/vec3.hpp>

#include <filesystem>
#include <fstream>


using namespace std;

//struct Block
//{
//	std::string layer;
//	bool opaque;
//	std::vector<glm::vec3> positions;
//};

int main()
{
	const std::filesystem::path filePath = "./resources/minecraftscene.json";

	if (not exists(filePath))
		throw std::runtime_error("File does not exist: " + filePath.string());

	std::ifstream inFile;
	inFile.open(filePath);

	if (not inFile.is_open())
		throw std::runtime_error("File already open" + filePath.string());

	std::cout << "File Opened: " << filePath << '\n' << '\n';
	std::cout << "Json Input: " << inFile.get() << '\n' << '\n';

	try
	{
		nlohmann::json doc;
		inFile >> doc;

		std::cout << "Parsing successful" << '\n';

		//std::unordered_set<Block> blocks{};

		for (const auto& obj : doc)
		{
			// Extract the "type" and "loc" values
			std::string type = obj["type"];
			std::vector<int> loc = obj["loc"].get<std::vector<int>>();


			// Print the extracted values
			std::cout << "Type: " << type << ", Location: " << "[";
			for (size_t i = 0; i < loc.size(); ++i)
			{
				std::cout << loc[i];
				if (i < loc.size() - 1)
					std::cout << ", ";
			}
			std::cout << "]" << '\n';
		}
	}
	catch (nlohmann::json::parse_error& e)
	{
		std::cerr << "Error parsing JSON: " << e.what() << '\n';
		return -1;
	}


#ifdef EXAMPLE1
	const char* jsonFragment = R"([{"type":"dirt","loc":[2, 3, 4]},{"type":"dirt","loc":[2,3,5]}])";


	std::cout << "Json Input: " << jsonFragment << '\n' << '\n';


	// Parse the JSON fragment

	try
	{
		nlohmann::json doc = nlohmann::json::parse(jsonFragment);
		std::cout << "Parsing successful" << '\n';

		for (const auto& obj : doc)
		{
			// Extract the "type" and "loc" values
			std::string type = obj["type"];
			std::vector<int> loc = obj["loc"].get<std::vector<int>>();


			// Print the extracted values
			std::cout << "Type: " << type << ", Location: " << "[";
			for (size_t i = 0; i < loc.size(); ++i) 
			{
				std::cout << loc[i];
				if (i < loc.size() - 1)
					std::cout << ", ";
			}
			std::cout << "]" << '\n';
		}
	}
	catch (nlohmann::json::parse_error& e)
	{
		std::cerr << "Error parsing JSON: " << e.what() << '\n';
		return -1;
	}
#endif


	return 0;
}
