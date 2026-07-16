#include "TimeManager.h"
#include "Master.h"

TimeManager::TimeManager(float _timeScale) :
	timeScale(_timeScale),
	deltaTime(0),
	fixedDeltaTime(0)
{
	startTimar = high_resolution_clock::now();
	lastFrameTime = high_resolution_clock::now();
	lastFixedTime = high_resolution_clock::now();
}

void TimeManager::ResetLastTime() {
	lastFrameTime = high_resolution_clock::now();
	lastFixedTime = high_resolution_clock::now();
}

void TimeManager::UpdateTime() {

	// ラグ等で時間が飛んでしまうと
	// 地面を通り抜けてしまうようなことがあるので
	// fixedTime以上の時間は禁止する。

	high_resolution_clock::time_point now = high_resolution_clock::now();
	float fixedStep = Master::Window().FixedStep();

	// 秒に変換しながらdeltaTimeに入れる
	deltaTime = std::chrono::duration<float>(now - lastFrameTime).count();

	if (deltaTime > fixedStep) {
		deltaTime = fixedStep;
	}

	lastFrameTime = now;

}

void TimeManager::UpdateFixedTime() {

	// ラグ等で時間が飛んでしまうと
	// 地面を通り抜けてしまうようなことがあるので
	// fixedTime*2以上の時間は禁止する。

	high_resolution_clock::time_point now = high_resolution_clock::now();
	float fixedStep = Master::Window().FixedStep();

	// 秒に変換しながらfixedTimeに入れる
	fixedDeltaTime = std::chrono::duration<float>(now - lastFixedTime).count();

	if (fixedDeltaTime > fixedStep * 2) {
		fixedDeltaTime = fixedStep * 2;
	}

	lastFixedTime = now;

}

// スタートからの経過時間
float TimeManager::Time() {
	return GetTime(lastFrameTime);
}
float TimeManager::TimeUnscaled() {
	return GetTime(lastFrameTime, false);
}

// 前回のアップデートからどの程度たったか
float TimeManager::DeltaTime() {
	return deltaTime * timeScale;
}
float TimeManager::DeltaTimeUnscaled() {
	return deltaTime;
}

// スタートからの経過時間(Fixed)
float TimeManager::FixedTime() {
	return GetTime(lastFixedTime);
}
float TimeManager::FixedTimeUnscaled() {
	return GetTime(lastFixedTime, false);
}

// 前回のアップデートからどの程度たったか(Felix)
float TimeManager::FixedDeltaTime() {
	return fixedDeltaTime * timeScale;
}
float TimeManager::FixedDeltaTimeUnscaled() {
	return fixedDeltaTime;
}

float TimeManager::GetTime(high_resolution_clock::time_point _lastTime, bool _scaled)
{
	std::chrono::duration<float> delta = _lastTime - startTimar;
	// フラグでアンスケールかどうか
	return _scaled ? timeScale * delta.count() : delta.count();
}
