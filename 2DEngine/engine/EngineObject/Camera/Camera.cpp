#include "Camera.h"
#include "Utils/Math/Math.h"

Side<float> Camera::WorldCameraSide() {
	Vector2<float> tmpSize = size / zoom;
	Side<float> worldCamera = Utils::Math::RectToSide({ worldPos ,tmpSize }, anchor);

	return worldCamera;
}

Rect<float> Camera::GetRect() const {
	return { worldPos, size };
}
