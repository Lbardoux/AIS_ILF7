#include <cstdlib>
#include <iostream>
#include <string>

#include "Options.hpp"

namespace xml2 = tinyxml2;


#define XML_FILE_OPTIONS   "data/assets/options.xml"
#define VALUE_FIELD        "value"
#define MUSIC_FIELD        "musics"
#define SOUND_FIELD        "sounds"
#define DIFFICULTY_FIELD   "difficulty"
#define INPUTS_FIELD       "inputs"
#define INPUT_FIELD        "input"
#define DEFAULT_FIELD      "default"
#define ROTATE_LEFT_FIELD  "rotateLeft"
#define ROTATE_RIGHT_FIELD "rotateRight"
#define GO_LEFT_FIELD      "goLeft"
#define GO_RIGHT_FIELD     "goRight"
#define GO_UP_FIELD        "goUp"
#define GO_DOWN_FIELD      "goDown"
#define PAUSE_GAME         "pause"


bool        Options::MODIFIED         = false;
std::string Options::filename;
bool        Options::DEFAULT_INPUTS   = true;
uint32_t    Options::KEY_GO_UP        = 273;
uint32_t    Options::KEY_GO_DOWN      = 274;
uint32_t    Options::KEY_GO_RIGHT     = 275;
uint32_t    Options::KEY_GO_LEFT      = 276;
uint32_t    Options::KEY_ROTATE_LEFT  = 97;
uint32_t    Options::KEY_ROTATE_RIGHT = 122;
uint32_t    Options::KEY_PAUSE        = 32;
bool        Options::MUSIC_ENABLED    = true;
bool        Options::SOUND_ENABLED    = true;
Difficulty  Options::DIFFICULTY       = EASY;



static std::string getDifficultyName(void)
{
	switch(Options::DIFFICULTY)
	{
		case NORMAL:
			return std::string("normal");
		case INSANE:
			return std::string("insane");
		default:
			return std::string("easy");
	}
}

void Options::dumpOptions(void)
{
	if (Options::MODIFIED == false)
	{
		return;
	}
	std::cout << "[INFO] : Writing new options." << std::endl;
	xml2::XMLDocument doc;
	xml2::XMLNode *root = doc.NewElement("options");
	doc.InsertFirstChild(root);
	
	xml2::XMLElement *element = doc.NewElement(SOUND_FIELD);
	element->SetAttribute(VALUE_FIELD, Options::SOUND_ENABLED);
	root->InsertEndChild(element);
	
	element = doc.NewElement(MUSIC_FIELD);
	element->SetAttribute(VALUE_FIELD, Options::MUSIC_ENABLED);
	root->InsertEndChild(element);
	
	element = doc.NewElement(DIFFICULTY_FIELD);
	element->SetAttribute(VALUE_FIELD, getDifficultyName().c_str());
	root->InsertEndChild(element);
	
	xml2::XMLElement *inputs = doc.NewElement(INPUTS_FIELD);
	inputs->SetAttribute(DEFAULT_FIELD, Options::DEFAULT_INPUTS);
		element = doc.NewElement(GO_LEFT_FIELD);
		element->SetAttribute(INPUT_FIELD, Options::KEY_GO_LEFT);
		inputs->InsertEndChild(element);
		
		element = doc.NewElement(GO_RIGHT_FIELD);
		element->SetAttribute(INPUT_FIELD, Options::KEY_GO_RIGHT);
		inputs->InsertEndChild(element);
		
		element = doc.NewElement(GO_UP_FIELD);
		element->SetAttribute(INPUT_FIELD, Options::KEY_GO_UP);
		inputs->InsertEndChild(element);
		
		element = doc.NewElement(GO_DOWN_FIELD);
		element->SetAttribute(INPUT_FIELD, Options::KEY_GO_DOWN);
		inputs->InsertEndChild(element);
		
		element = doc.NewElement(ROTATE_LEFT_FIELD);
		element->SetAttribute(INPUT_FIELD, Options::KEY_ROTATE_LEFT);
		inputs->InsertEndChild(element);
		
		element = doc.NewElement(ROTATE_RIGHT_FIELD);
		element->SetAttribute(INPUT_FIELD, Options::KEY_ROTATE_RIGHT);
		inputs->InsertEndChild(element);
		
		element = doc.NewElement(PAUSE_GAME);
		element->SetAttribute(INPUT_FIELD, Options::KEY_PAUSE);
		inputs->InsertEndChild(element);
	root->InsertEndChild(inputs);
}

static void selectDifficulty(const std::string &diffString)
{
	if (diffString == "normal")
		Options::DIFFICULTY = NORMAL;
	else if (diffString == "insane")
		Options::DIFFICULTY = INSANE;
	else
		Options::DIFFICULTY = EASY;
}

void Options::initAndReadOptions(void)
{
	getFullNameOfFile(XML_FILE_OPTIONS, Options::filename);
	
	xml2::XMLDocument doc;
	xml2::XMLNode *root = loadXmlFileAndDoChecks(Options::filename, doc);
	
	xml2::XMLElement *element = findThisElement(std::string(MUSIC_FIELD), root);
	element->QueryBoolAttribute(VALUE_FIELD, &Options::MUSIC_ENABLED);
	
	element = findThisElement(std::string(SOUND_FIELD), root);
	element->QueryBoolAttribute(VALUE_FIELD, &Options::SOUND_ENABLED);
	
	element = findThisElement(std::string(DIFFICULTY_FIELD), root);
	std::string difficulty = element->Attribute(VALUE_FIELD);
	selectDifficulty(difficulty);
	
	xml2::XMLElement *inputs  = findThisElement(std::string(INPUTS_FIELD), root);
	inputs->QueryBoolAttribute(DEFAULT_FIELD, &Options::DEFAULT_INPUTS);
	if (Options::DEFAULT_INPUTS == false)
	{
		element = findThisElement(std::string(GO_LEFT_FIELD), inputs);
		element->QueryUnsignedAttribute(INPUT_FIELD, &Options::KEY_GO_LEFT);
		
		element = findThisElement(std::string(GO_RIGHT_FIELD), inputs);
		element->QueryUnsignedAttribute(INPUT_FIELD, &Options::KEY_GO_RIGHT);
		
		element = findThisElement(std::string(GO_UP_FIELD), inputs);
		element->QueryUnsignedAttribute(INPUT_FIELD, &Options::KEY_GO_UP);
		
		element = findThisElement(std::string(GO_DOWN_FIELD), inputs);
		element->QueryUnsignedAttribute(INPUT_FIELD, &Options::KEY_GO_DOWN);
		
		element = findThisElement(std::string(ROTATE_LEFT_FIELD), inputs);
		element->QueryUnsignedAttribute(INPUT_FIELD, &Options::KEY_ROTATE_LEFT);
		
		element = findThisElement(std::string(ROTATE_RIGHT_FIELD), inputs);
		element->QueryUnsignedAttribute(INPUT_FIELD, &Options::KEY_ROTATE_RIGHT);
		
		element = findThisElement(std::string(PAUSE_GAME), inputs);
		element->QueryUnsignedAttribute(INPUT_FIELD, &Options::KEY_PAUSE);
	}
	
	atexit(Options::dumpOptions);
}
