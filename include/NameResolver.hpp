/**
 * @brief Provide a function to get absolute path for every file you need.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef NAMERESOLVER_HPP_INCLUDED
#define NAMERESOLVER_HPP_INCLUDED

#include "Arguments.hpp"

/**
 * @brief Find the absolute name of \a nameFromRoot.
 * @param[in]  nameFromRoot The file name from the root of the application.
 * @param[out] out          The result string
 */
void getFullNameOfFile(const std::string &nameFromRoot, std::string &out);

#endif
