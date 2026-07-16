#pragma once

// ==========================
// 標準ライブラリ
// ==========================

// メモリ管理
#include <memory>          // std::unique_ptr / shared_ptr

// コンテナ
#include <vector>          // 可変長配列
#include <map>             // 昇順マップ
#include <unordered_map>   // ハッシュマップ（シーン名管理など）
#include <array>           // 固定配列

// 文字列
#include <string>          // シーン名・タグ管理

// ユーティリティ
#include <any>             // 任意型
#include <optional>        // 値の有無管理
#include <cassert>         // デバッグ用アサート
#include <functional>	   // 関数・ラムダ・関数ポインタを変数として保持できるようにするもの

// 時間管理
#include <chrono>          // DeltaTimeなど

// 数学
#include <cmath>           // sqrt, sin, cosなど
#include <algorithm>


// ==========================
// 外部ライブラリ
// ==========================

#include "Dxlib.h"         // DxLib本体


// ==========================
// デバッグ系
// ==========================

#include <iostream>        // コンソール出力
#include <windows.h>       // WinAPI（必要な場合のみ）

