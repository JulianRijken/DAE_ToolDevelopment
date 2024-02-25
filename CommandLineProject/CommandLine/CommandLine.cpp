#include "CommandLine.h"
#include <nlohmann/json.hpp>

using namespace std;

int main()
{
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


	return 0;
}
