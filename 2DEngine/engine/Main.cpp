#include "Dxlib.h"
#include "Master/Master.h"

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevinstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	if (!Master::Instance().InitSystem())
	{
		return -1;
	}

	Master::Instance().InitContents();
	Master::Scene().Init();
	Master::Instance().GameLoop();

	return 0;
}

