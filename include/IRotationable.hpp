/**
 * @brief Everything to have a rotation buffer for your sprite.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef IROTATIONABLE_HPP_INCLUDED
#define IROTATIONABLE_HPP_INCLUDED

#include <cstdint>
#include <vector>
#include "ImageLoader.hpp"



typedef std::vector<SDL_Surface*> SpriteBuffer;

/**
 * @brief Create a buffer of sprite for every rotation.
 * The number of slots allocated will be :
 * 360/report
 * Of course, 360 has to be divisable by report
 * By default, it's 10
 */
template<typename Obj, uint8_t report=10>
class IRotationable
{
	protected:
		static SpriteBuffer rotationBuffer;
		
		
		static void initSpriteBuffer(void)
		{
			static_assert(360%report == 0, "report template argument must permit to divide 360 correctly");
			rotationBuffer.resize(360/report, NULL);
			rotationBuffer.at(0) = Obj::sprite;
		};
		
		static void emptySpriteBuffer(void)
		{
			// skip first element, we do not have to free it.
			for(uint32_t i=1;i<rotationBuffer.size();++i)
			{
				unloadImage(&rotationBuffer.at(i));
			}
			rotationBuffer.clear();
		};
		
		SDL_Surface* getSpriteForThisAngle(uint32_t angle) const
		{
			float_t calcul = static_cast<float_t>(angle)/static_cast<float_t>(report);
			uint32_t index = static_cast<uint32_t>(calcul)%rotationBuffer.size();
			SDL_Surface *result = rotationBuffer.at(index);
			if (result == NULL)
			{
				rotationBuffer.at(index) = rotateThisImageOf(rotationBuffer.at(0), static_cast<double_t>(angle));
				result = rotationBuffer.at(index);
			}
			return result;
		};
	
};

template<typename Obj, uint8_t report>
SpriteBuffer IRotationable<Obj, report>::rotationBuffer;

#endif
