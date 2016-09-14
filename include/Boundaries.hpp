/**
 * @brief A container for bounds.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef BOUNDARIES_HPP_INCLUDED
#define BOUNDARIES_HPP_INCLUDED

#include <cstdint>

/**
 * @brief Boundaries are describe by two 2 dimensionals points
 * One is the top left corner, and the other the bottom right corner.
 */
class Boundaries
{
	public:
		int32_t xmin;
		int32_t ymin;
		int32_t xmax;
		int32_t ymax;
};

#endif
