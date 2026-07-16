#include "Master/Master.h"

void Master::GameLoop() {
	for (;;) {
		ManagerUpdate();

		scene.UpdateGame();

		scene.UpdateFixed();

		scene.DeleteObj();

		scene.Render();

		scene.SetNewObj();

		if (IsGameEnd()) { return; }
	}
}

void Master::ManagerUpdate() {
	// 時間を最初にアップデートする
	time.UpdateTime();
	// キーの状態アップデート
	input.UpdateInput();
	// シーン状態のアップデート
	scene.SceneChange();
}

bool Master::IsGameEnd() {
	if (Input().KeyBoard().IsDown(KeyBoardCode::Escape) ||
		ProcessMessage() == -1) {
		return true;
	}
	return false;
}