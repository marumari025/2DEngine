#include "stdafx.h" // TRUE FALSE‚Ì‚½‚ß
#include "Manager/WindowManager/WindowManager.h"

WindowManager::WindowManager() :
	windowSize{ 800,600 },
	colorBit(32),
	color(0x008080),
	windowMode(TRUE),
	mouseDisp(TRUE),
	fixedStep(0.02f),
	fps(60)
{
}