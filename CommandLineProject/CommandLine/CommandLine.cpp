#include "CommandLine.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <filesystem>
#include <fstream>

#include <Windows.h>


struct Block
{
    bool opaque;
    std::string layer;
    std::vector<glm::vec3> positions;
};

const std::vector<glm::vec3> CUBE_BASE_VERTICES
{
	{ 0.5f,  0.5f, -0.5f},
	{ 0.5f, -0.5f, -0.5f},
	{ 0.5f,  0.5f,  0.5f},
	{ 0.5f, -0.5f,  0.5f},
	{-0.5f,  0.5f, -0.5f},
	{-0.5f, -0.5f, -0.5f},
	{-0.5f,  0.5f,  0.5f},
	{-0.5f, -0.5f,  0.5f}
};

const std::vector<glm::ivec4> CUBE_BASE_FACES
{
    {1, 5, 7, 3},
    {4, 3, 7, 8},
    {8, 7, 5, 6},
    {6, 2, 4, 8},
    {2, 1, 3, 4},
    {6, 5, 1, 2}
};


void ExportObj(const std::string& objString, const std::filesystem::path& filePath)
{
	create_directories(filePath.parent_path());

	std::ofstream outputFile(filePath);
	if (not outputFile)
	{
		std::wcerr << L"Failed to open: " << filePath << '\n';
		return;
	}

	outputFile << objString;
	outputFile.close();

	std::wcout << L"Output written to: " << filePath << '\n';
}

std::vector<Block> loadBlocks(const std::filesystem::path& filePath)
{
	std::vector<Block> blocks{};

	if (not exists(filePath))
		throw std::runtime_error("File does not exist: " + filePath.string());

	std::ifstream inFile;
	inFile.open(filePath);

	if (not inFile.is_open())
		throw std::runtime_error("File already open" + filePath.string());

	// Parse the JSON
	nlohmann::json doc;
	try
	{
		doc = nlohmann::json::parse(inFile);
	}
	catch (nlohmann::json::parse_error& e)
	{
		std::cerr << "Error parsing JSON: " << e.what() << '\n';
		return blocks;
	}

	blocks.reserve(doc.size());

	// Extract the blocks
	for (const auto& obj : doc)
	{
		Block block;
		block.opaque = obj["opaque"];
		block.layer = obj["layer"];

		for (const auto& pos : obj["positions"])
			block.positions.emplace_back(pos[0], pos[1], pos[2]);

		blocks.push_back(block);
	}

	return blocks;	
};

std::string BlocksToObj(const std::vector<Block>& blocks)
{
	std::string obj;

	obj += "# Made using Julian's json to obj converter\n";


	int cubeIndex{0};

	for (const auto& block : blocks)
	{
		obj += "o " + block.layer + '\n';

		for (const auto& pos : block.positions)
		{
			for (const glm::vec3& cubeBaseVertex : CUBE_BASE_VERTICES)
			{
				obj += "v "
					+ std::to_string(pos.x + cubeBaseVertex.x) + ' '
					+ std::to_string(pos.z + cubeBaseVertex.y) + ' ' // TODO: z and y are swapped to get y up
					+ std::to_string(pos.y + cubeBaseVertex.z) + '\n';
			}
		}

		obj += R"(s 0)";
		obj += '\n';

		for (size_t i{}; i < block.positions.size(); i++)
		{
			for (const glm::ivec4& cubeBaseFace : CUBE_BASE_FACES)
			{
				obj += "f "
					+ std::to_string(cubeIndex + cubeBaseFace[0]) + ' '
					+ std::to_string(cubeIndex + cubeBaseFace[1]) + ' '
					+ std::to_string(cubeIndex + cubeBaseFace[2]) + ' '
					+ std::to_string(cubeIndex + cubeBaseFace[3]) + '\n';
			}

			cubeIndex += 8;
		}
	}

	return obj;
}


int wmain(int argc, wchar_t* argv[])
{
	// Force console to use UTF-8 encoding
	SetConsoleOutputCP(CP_UTF8);
	std::wcout << L"UTF8 Enabled 👋\n";


	///////////////////
	/// Parse arguments
	///////////////////
	std::wstring inputFileName;
	std::wstring outputFileName;

	for (size_t argumentIndex = 0; argumentIndex < argc; argumentIndex++)
	{
		std::wstring arg = argv[argumentIndex];
		if(arg.find(L"-i") != std::string::npos)
		{
			inputFileName = argv[argumentIndex + 1];
			argumentIndex++; // Skip parameter
		}
		else if (arg.find(L"-o") != std::string::npos)
		{
			outputFileName = argv[argumentIndex + 1];
			argumentIndex++; // Skip parameter
		}
	}

	if(inputFileName.empty() or outputFileName.empty())
	{
		std::wcerr << "Invalid arguments" << std::endl;
		return -1;
	}


	/////////////////////////////////////
	/// Confirm file paths and extensions
	/////////////////////////////////////
	const std::filesystem::path resourcesPath = "./resources/";
	const std::filesystem::path outputPath = "./output/";

	std::filesystem::path inputFullPath = resourcesPath / inputFileName;
	if(inputFullPath.extension() != ".json")
	{
		if(inputFullPath.has_extension())
		{
			std::wcerr << "Invalid input file extension for input \n";
			return -1;
		}

		inputFullPath += ".json";
	}

	// Force output file to be .obj
	std::filesystem::path outputFullPath = outputPath / outputFileName;
	if (outputFullPath.extension() != ".obj")
	{
		outputFullPath += ".obj";
	}




	const auto blocks = loadBlocks(inputFullPath);

	std::cout << "BLOCKS PARSED: \n";
	for (const auto& block : blocks)
	{
		std::cout << "Block: " << block.layer << '\n';
		std::cout << "  Opaque: " << std::boolalpha << block.opaque << '\n';
		std::cout << "  Positions:\n";
		for (const auto& pos : block.positions)
			std::cout << "    " << pos.x << ", " << pos.y << ", " << pos.z << '\n';
	}


	const std::string& convertedObj = BlocksToObj(blocks);
	std::cout << "OBJ: \n" << convertedObj << '\n';

	ExportObj(convertedObj, outputFullPath);

	return 0;
}
