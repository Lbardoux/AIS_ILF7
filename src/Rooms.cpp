#include "Rooms.hpp"


roomIndex_t Rooms::currentIndex = 0;
std::vector<Room*> Rooms::rooms({nullptr, nullptr});

void Rooms::initRooms(void)
{
	//Rooms::rooms.resize(1);
	// insertion at the good place
}

roomIndex_t Rooms::getCurrentIndex(void)
{
	return Rooms::currentIndex;
}

Room* Rooms::getCurrentRoom(void)
{
	return Rooms::rooms.at(Rooms::currentIndex);
}

Room* Rooms::goToNextRoom(void)
{
	if (static_cast<uint32_t>(Rooms::currentIndex+1) >= Rooms::rooms.size())
	{
		return Rooms::rooms.at(0);
	}
	else
	{
		++Rooms::currentIndex;
		return Rooms::rooms.at(Rooms::currentIndex);
	}
}

Room* Rooms::goToPreviousRoom(void)
{
	if (Rooms::currentIndex-1 <= 0)
	{
		return Rooms::rooms.at(Rooms::rooms.size()-1);
	}
	else
	{
		--Rooms::currentIndex;
		return Rooms::rooms.at(Rooms::currentIndex);
	}
}

Room* Rooms::getRoomByIndex(roomIndex_t dst)
{
	return Rooms::rooms.at(dst);
}
