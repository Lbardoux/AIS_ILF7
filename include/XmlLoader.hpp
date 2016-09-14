/**
 * @brief This file proposes to store tinyxml2
 * and a lot of utilitary functions to use it.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef XMLLOADER_HPP_INCLUDED
#define XMLLOADER_HPP_INCLUDED

#include <string>
#include "tinyxml2.h"

namespace xml2 = tinyxml2;


/**
 * @brief Load \a fname on \a doc and check some conditions (opening, existence of
 * the first element).
 * Any error will abort the execution thread.
 * @param[in]    fname The filename of the xml configuration.
 * @param[inout] doc   The XMLDocument to fill.
 * @return an address on the first element of the document.
 */
xml2::XMLNode* loadXmlFileAndDoChecks(const std::string &fname, xml2::XMLDocument &doc);

/**
 * @brief Look for \a elementName on the current \a node.
 * If this element wasn't find, it will abort the execution thread.
 * @param[in] elementName The element (by name) you want to find.
 * @param[in] node        The node you're working with.
 * @return An address to the element you're seeking.
 */
xml2::XMLElement* findThisElement(const std::string &elementName, xml2::XMLNode *node);

/**
 * @brief Save \a doc as \a fname and check for the return value.
 * In case of issue, it will exit the application.
 * @param[inout] doc   The XMLDocument to save.
 * @param[in]    fname The name of the file you want.
 */
void saveXMLFileAs(xml2::XMLDocument &doc, const std::string &fname);


#endif
