#pragma once

#include "stdafx.h"
#include "Manager/Manager.h"

using namespace std::chrono;

class TimeManager
{
private:
	// 初期は1倍のスピード
	TimeManager(float _timeScale = 1);
	friend class Master;

	// プロジェクトの開始時刻
	high_resolution_clock::time_point startTimar;


	// デルタタイム計算用
	high_resolution_clock::time_point lastFrameTime;
	float deltaTime;

	// フィックスドタイム計算用
	high_resolution_clock::time_point lastFixedTime;
	float fixedDeltaTime;

	// 時間を何倍で進めるか
	float timeScale;

	float GetTime(high_resolution_clock::time_point now, bool scaled = true);

public:
	// 時間に空きができるような重い処理の後に動かして空きをなくす
	void ResetLastTime();

	void UpdateTime();
	void UpdateFixedTime();

	// どのぐらいのスピードで時間を進めるか
	void SetTimeScale(float _timeScale = 1) {
		timeScale = _timeScale;
	}

	// スタートからの経過時間
	float Time();
	float TimeUnscaled();

	// 前回のアップデートからどの程度たったか
	float DeltaTime();
	float DeltaTimeUnscaled();

	// スタートからの経過時間(Felix)
	float FixedTime();
	float FixedTimeUnscaled();

	// 前回のアップデートからどの程度たったか(Felix)
	float FixedDeltaTime();
	float FixedDeltaTimeUnscaled();
};