/**
 * @brief This class will manage the chain between each rooms.
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef ROOMS_HPP_INCLUDED
#define ROOMS_HPP_INCLUDED

#include <vector>
#include <cstdint>
#include "Room.hpp"

typedef int32_t roomIndex_t;

class Rooms final
{
	private:
		static roomIndex_t currentIndex;
		static std::vector<Room*> rooms;
		
	public:
		static void initRooms(void);
		
		static roomIndex_t getCurrentIndex(void);
		
		static Room* getCurrentRoom(void);
		static Room* goToNextRoom(void);
		static Room* goToPreviousRoom(void);
		static Room* getRoomByIndex(roomIndex_t dst);

};



#endif
