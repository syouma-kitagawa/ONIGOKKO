#include "Event.h"
#include "DirectGraphics.h"

Event* Event::pInstance = NULL;

Event::~Event()
{
}

void Event::CreateInstance()
{
	if (pInstance == NULL) {
		pInstance = new Event();
	}
}