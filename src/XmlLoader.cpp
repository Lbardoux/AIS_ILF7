#include <iostream>
#include <cstdlib>

#include "XmlLoader.hpp"


xml2::XMLNode* loadXmlFileAndDoChecks(const std::string &fname, xml2::XMLDocument &doc)
{
	xml2::XMLError err = doc.LoadFile(fname.c_str());
	if (err != xml2::XML_SUCCESS)
	{
		std::cerr << "[ERROR]: while loading " << fname << ", abort." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	xml2::XMLNode *root = doc.FirstChild();
	if (root == nullptr)
	{
		std::cerr << "[ERROR]: First element of " << fname << " does not exist, abort." << std::endl;
		exit(EXIT_FAILURE);
	}
	return root;
}

xml2::XMLElement* findThisElement(const std::string &elementName, xml2::XMLNode *node)
{
	xml2::XMLElement *element = node->FirstChildElement(elementName.c_str());
	if (element == nullptr)
	{
		std::cerr << "[ERROR] : The element " << elementName << " does not exist, abort." << std::endl;
		exit(EXIT_FAILURE);
	}
	return element;
}

void saveXMLFileAs(xml2::XMLDocument &doc, const std::string &fname)
{
	xml2::XMLError err = doc.SaveFile(fname.c_str());
	if (err != xml2::XML_SUCCESS)
	{
		std::cerr << "[ERROR] : Unable to save " << fname << " properly." << std::endl;
		exit(EXIT_FAILURE);
	}
}
