#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

#include "GameInitializer.hpp"


namespace xml2 = tinyxml2;


#define XML_CONFIGURATION_FILE "data/assets/config.xml"
#define FPS_FIELD              "fps"
#define FULLSCREEN_FIELD       "fullscreen"
#define SCREENSIZE_FIELD       "screenSizes"
#define SCREEN_HEIGHT_FIELD    "height"
#define SCREEN_WIDTH_FIELD     "width"
#define VALUE_FIELD            "value"
#define ROOT_FIELD_XML         "gameConfiguration"

#define NB_MS_BY_SECOND 1000


uint32_t    GameInitializer::FRAME_RATE    = 0;
bool        GameInitializer::FULLSCREEN    = false;
uint32_t    GameInitializer::SCREEN_HEIGHT = 0;
uint32_t    GameInitializer::SCREEN_WIDTH  = 0;
uint32_t    GameInitializer::FPS_READ      = 0;
std::string GameInitializer::fullName;
bool        GameInitializer::MODIFIED      = false;


//! @brief Log a line to confirm loading of the xml file.
static void confirmationLogs(void)
{
	std::cout << "[INFO] : Loading "      << XML_CONFIGURATION_FILE << " successfully !" << std::endl;
	std::cout << "[INFO] : Delay : "      << GameInitializer::FRAME_RATE << std::endl;
	std::cout << "[INFO] : Fullscreen : " << GameInitializer::FULLSCREEN << std::endl;
	std::cout << "[INFO] : Height : "     << GameInitializer::SCREEN_HEIGHT << std::endl; 
	std::cout << "[INFO] : Width : "      << GameInitializer::SCREEN_WIDTH << std::endl; 
}


//! @brief Loading \a fname with tinyxml2. Nothing else to do here.
static void loadConfigurationFile(void)
{
	GameInitializer::MODIFIED = false;
	xml2::XMLDocument configXml;
	xml2::XMLNode *root = loadXmlFileAndDoChecks(GameInitializer::fullName, configXml);
	
	xml2::XMLElement *fps = findThisElement(std::string(FPS_FIELD), root);
	fps->QueryUnsignedAttribute(VALUE_FIELD, &GameInitializer::FPS_READ);
	GameInitializer::FRAME_RATE = NB_MS_BY_SECOND / GameInitializer::FPS_READ;
	
	xml2::XMLElement *fullscreen = findThisElement(std::string(FULLSCREEN_FIELD), root);
	fullscreen->QueryBoolAttribute(VALUE_FIELD, &GameInitializer::FULLSCREEN);
	if (GameInitializer::FULLSCREEN == false)
	{
		xml2::XMLElement *sizes  = findThisElement(std::string(SCREENSIZE_FIELD), root);
		xml2::XMLElement *width  = findThisElement(std::string(SCREEN_WIDTH_FIELD ), sizes);
		xml2::XMLElement *height = findThisElement(std::string(SCREEN_HEIGHT_FIELD), sizes);
		width->QueryUnsignedAttribute(VALUE_FIELD, &GameInitializer::SCREEN_WIDTH);
		height->QueryUnsignedAttribute(VALUE_FIELD, &GameInitializer::SCREEN_HEIGHT);
	}
	else
	{
		GameInitializer::SCREEN_HEIGHT = 480;
		GameInitializer::SCREEN_WIDTH  = 640;
	}
	confirmationLogs();
}

//! @brief Write a fresh new configuration file with our modifications.
void dumpConfiguration(void)
{
	if (GameInitializer::MODIFIED == false)
	{
		return;
	}
	std::cout << "[INFO] : Writing modifications on " << XML_CONFIGURATION_FILE << std::endl;
	xml2::XMLDocument newDoc;
	xml2::XMLNode *root = newDoc.NewElement(ROOT_FIELD_XML);
	newDoc.InsertFirstChild(root);
	
	xml2::XMLElement *fps = newDoc.NewElement(FPS_FIELD);
	fps->SetAttribute(VALUE_FIELD, GameInitializer::FPS_READ);
	root->InsertEndChild(fps);
	
	xml2::XMLElement *fullscreen = newDoc.NewElement(FULLSCREEN_FIELD);
	fullscreen->SetAttribute(VALUE_FIELD, GameInitializer::FULLSCREEN);
	root->InsertEndChild(fullscreen);
	
	xml2::XMLElement *screenInfos = newDoc.NewElement(SCREENSIZE_FIELD);
		xml2::XMLElement *width = newDoc.NewElement(SCREEN_WIDTH_FIELD);
		width->SetAttribute(VALUE_FIELD, GameInitializer::SCREEN_WIDTH);
		screenInfos->InsertEndChild(width);
		
		xml2::XMLElement *height = newDoc.NewElement(SCREEN_HEIGHT_FIELD);
		height->SetAttribute(VALUE_FIELD, GameInitializer::SCREEN_HEIGHT);
		screenInfos->InsertEndChild(height);
	root->InsertEndChild(screenInfos);
	
	saveXMLFileAs(newDoc, GameInitializer::fullName);
	
	std::cout << "[INFO] : Shutting down game..." << std::endl;
}

void GameInitializer::initGame(int argc, char **argv)
{
	Arguments::linkingArgcArgv(argc, argv);
	getFullNameOfFile(XML_CONFIGURATION_FILE, GameInitializer::fullName);
	loadConfigurationFile();
	atexit(dumpConfiguration);
	
	SDLLoader::loadSDL(GameInitializer::SCREEN_WIDTH, GameInitializer::SCREEN_HEIGHT, GameInitializer::FULLSCREEN);
	
	Backgrounds::loadBackgrounds();
	
	// the order is important, sprites before objects !
	Sprites::loadSprites();
	Options::initAndReadOptions();
	Objects::loadObjects();
	
}
