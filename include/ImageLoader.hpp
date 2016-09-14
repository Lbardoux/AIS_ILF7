/**
 * @brief This file will provide convenience to load SDL_Surface.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef IMAGELOADER_HPP_INCLUDED
#define IMAGELOADER_HPP_INCLUDED

#include <string>
#include <cstdint>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_rotozoom.h"
#include "NameResolver.hpp"
#include "Arguments.hpp"

/**
 * @brief Load \a nameFromRoot with \a alpha or not .
 * It will check for loading and convert into display format.
 * @param[in] nameFromRoot The path from the root of the project to get the image.
 * @param[in] alpha        If you want transparancy or not.
 * @return an address to the allocated image.
 */
SDL_Surface* loadImage(const std::string &nameFromRoot, bool alpha);

/**
 * @brief Unload \a image and set this pointer to NULL.
 * @param[inout] image The SDL_Surface to unload.
 */
void unloadImage(SDL_Surface **image);

/**
 * @brief Create a rotation of \a img of \a angle.
 * You'll have to free it yourself :D
 * @param[in] img   The image to rotate, it must not be null.
 * @param[in] angle The angle you wanna rotate it.
 * @return your rotated image
 */
SDL_Surface* rotateThisImageOf(SDL_Surface *const img, double_t angle);

#endif
