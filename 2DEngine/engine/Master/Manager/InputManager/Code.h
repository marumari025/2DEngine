#pragma once

enum class KeyBoardCode {
	BackSpace,      // KEY_INPUT_BACK
	Tab,            // KEY_INPUT_TAB
	Enter,          // KEY_INPUT_RETURN

	LShift,         // KEY_INPUT_LSHIFT
	RShift,         // KEY_INPUT_RSHIFT
	LControl,       // KEY_INPUT_LCONTROL
	RControl,       // KEY_INPUT_RCONTROL
	Escape,         // KEY_INPUT_ESCAPE
	Space,          // KEY_INPUT_SPACE
	PageUp,         // KEY_INPUT_PGUP
	PageDown,       // KEY_INPUT_PGDN
	End,            // KEY_INPUT_END
	Home,           // KEY_INPUT_HOME
	Left,           // KEY_INPUT_LEFT
	Up,             // KEY_INPUT_UP
	Right,          // KEY_INPUT_RIGHT
	Down,           // KEY_INPUT_DOWN
	Insert,         // KEY_INPUT_INSERT
	Delete,         // KEY_INPUT_DELETE

	Minus,          // KEY_INPUT_MINUS
	Yen,            // KEY_INPUT_YEN
	PrevTrack,      // KEY_INPUT_PREVTRACK
	Period,         // KEY_INPUT_PERIOD
	Slash,          // KEY_INPUT_SLASH
	LAlt,           // KEY_INPUT_LALT
	RAlt,           // KEY_INPUT_RALT
	ScrollLock,     // KEY_INPUT_SCROLL
	Semicolon,      // KEY_INPUT_SEMICOLON
	Colon,          // KEY_INPUT_COLON
	LBracket,       // KEY_INPUT_LBRACKET
	RBracket,       // KEY_INPUT_RBRACKET
	At,             // KEY_INPUT_AT
	Backslash,      // KEY_INPUT_BACKSLASH
	Comma,          // KEY_INPUT_COMMA
	Kanji,          // KEY_INPUT_KANJI
	Convert,        // KEY_INPUT_CONVERT
	NoConvert,      // KEY_INPUT_NOCONVERT
	Kana,           // KEY_INPUT_KANA
	Apps,           // KEY_INPUT_APPS
	CapsLock,       // KEY_INPUT_CAPSLOCK
	SysRq,          // KEY_INPUT_SYSRQ
	Pause,          // KEY_INPUT_PAUSE
	LWin,           // KEY_INPUT_LWIN
	RWin,           // KEY_INPUT_RWIN

	NumLock,        // KEY_INPUT_NUMLOCK
	NumPad0,        // KEY_INPUT_NUMPAD0
	NumPad1,        // KEY_INPUT_NUMPAD1
	NumPad2,        // KEY_INPUT_NUMPAD2
	NumPad3,        // KEY_INPUT_NUMPAD3
	NumPad4,        // KEY_INPUT_NUMPAD4
	NumPad5,        // KEY_INPUT_NUMPAD5
	NumPad6,        // KEY_INPUT_NUMPAD6
	NumPad7,        // KEY_INPUT_NUMPAD7
	NumPad8,        // KEY_INPUT_NUMPAD8
	NumPad9,        // KEY_INPUT_NUMPAD9
	Multiply,       // KEY_INPUT_MULTIPLY
	Add,            // KEY_INPUT_ADD
	Subtract,       // KEY_INPUT_SUBTRACT
	Decimal,        // KEY_INPUT_DECIMAL
	Divide,         // KEY_INPUT_DIVIDE
	NumPadEnter,    // KEY_INPUT_NUMPADENTER

	F1,				// KEY_INPUT_F1
	F2, 			// KEY_INPUT_F2
	F3, 			// KEY_INPUT_F3
	F4, 			// KEY_INPUT_F4
	F5, 			// KEY_INPUT_F5
	F6, 			// KEY_INPUT_F6
	F7, 			// KEY_INPUT_F7
	F8, 			// KEY_INPUT_F8
	F9, 			// KEY_INPUT_F9
	F10, 			// KEY_INPUT_F10
	F11, 			// KEY_INPUT_F11
	F12,			// KEY_INPUT_F12

	A,				// KEY_INPUT_A
	B, 				// KEY_INPUT_B
	C, 				// KEY_INPUT_C
	D, 				// KEY_INPUT_D
	E, 				// KEY_INPUT_E
	F, 				// KEY_INPUT_F
	G, 				// KEY_INPUT_G
	H, 				// KEY_INPUT_H
	I, 				// KEY_INPUT_I
	J, 				// KEY_INPUT_J
	K, 				// KEY_INPUT_K
	L, 				// KEY_INPUT_L
	M, 				// KEY_INPUT_M
	N, 				// KEY_INPUT_N
	O, 				// KEY_INPUT_O
	P, 				// KEY_INPUT_P
	Q, 				// KEY_INPUT_Q
	R, 				// KEY_INPUT_R
	S, 				// KEY_INPUT_S
	T, 				// KEY_INPUT_T
	U, 				// KEY_INPUT_U
	V, 				// KEY_INPUT_V
	W, 				// KEY_INPUT_W
	X, 				// KEY_INPUT_X
	Y, 				// KEY_INPUT_Y
	Z,				// KEY_INPUT_Z

	D0,				// KEY_INPUT_0 
	D1, 			// KEY_INPUT_1
	D2, 			// KEY_INPUT_2
	D3, 			// KEY_INPUT_3
	D4, 			// KEY_INPUT_4
	D5, 			// KEY_INPUT_5
	D6, 			// KEY_INPUT_6
	D7, 			// KEY_INPUT_7
	D8, 			// KEY_INPUT_8
	D9				// KEY_INPUT_9
};

enum class MouseCode
{
	Left,			// MOUSE_INPUT_LEFT
	Right,			// MOUSE_INPUT_RIGHT
	Middle,			// MOUSE_INPUT_MIDDLE

	Btn1,			// MOUSE_INPUT_1
	Btn2,			// MOUSE_INPUT_2
	Btn3,			// MOUSE_INPUT_3
	Btn4,			// MOUSE_INPUT_4
	Btn5,			// MOUSE_INPUT_5
	Btn6,			// MOUSE_INPUT_6
	Btn7,			// MOUSE_INPUT_7
	Btn8,			// MOUSE_INPUT_8
};