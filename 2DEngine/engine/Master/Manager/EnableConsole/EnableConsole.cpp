#include "stdafx.h"
#include "EnableConsole.h"

EnableConsole::EnableConsole() {
	static bool isConsoleAllocated = false;
	if (!isConsoleAllocated) {
		if (!AllocConsole()) {
			std::cerr << "コンソールの作成に失敗しました" << std::endl;
			MessageBox(nullptr, "コンソールの作成に失敗しました", "Error", MB_OK | MB_ICONERROR);
			FreeConsole();
			return;
		}
		isConsoleAllocated = true;
	}

	FILE* fpOut = nullptr;
	FILE* fpIn = nullptr;

	if (freopen_s(&fpOut, "CONOUT$", "w", stdout) != 0 ||
		freopen_s(&fpIn, "CONIN$", "r", stdin) != 0) {
		MessageBox(nullptr, "コンソールのリダイレクトに失敗しました", "Error", MB_OK | MB_ICONERROR);
		FreeConsole();
		return;
	}

	FILE* fpErr = nullptr;
	freopen_s(&fpErr, "CONOUT$", "w", stderr);

	SetConsoleTitle("Debug Console");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (consoleHandle != INVALID_HANDLE_VALUE) {
		COORD bufferSize = { 120, 300 };
		SetConsoleScreenBufferSize(consoleHandle, bufferSize);

		SMALL_RECT windowSize = { 0, 0, bufferSize.X - 1, 30 }; // 30 行だけ表示するように設定
		SetConsoleWindowInfo(consoleHandle, TRUE, &windowSize);
	}
}