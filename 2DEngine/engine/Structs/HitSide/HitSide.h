#pragma once

// “–‚½‚Á‚½•Ó‚ð•Ô‚·‚½‚ß‚Ì‚à‚Ì
enum HitSide {
    HIT_NONE = 0,
    HIT_LEFT = 1 << 0,
    HIT_RIGHT = 1 << 1,
    HIT_TOP = 1 << 2,
    HIT_BOTTOM = 1 << 3,
};