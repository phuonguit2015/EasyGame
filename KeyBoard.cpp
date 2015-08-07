////--------------------------------------------------------------
//// Mô tả: Lớp bao gồm các chức năng khởi tạo, xử lí việc nhập xuất với bàn phím
////
////
////--------------------------------------------------------------
//#include "KeyBoard.h"
//#include "Trace.h"
//
//KeyBoard::KeyBoard(HWND hWnd, HINSTANCE hInstance)
//{
//	_di = 0;
//	_Keyboard = 0;
//	_hInstance = hInstance;
//	_hWnd = hWnd;
//	ZeroMemory(&this->_KeyBuffer, sizeof(_KeyBuffer));
//}
//
//bool KeyBoard::InitKeyBoard()
//{
//	HRESULT hr = DirectInput8Create(
//		_hInstance,
//		DIRECTINPUT_VERSION,
//		IID_IDirectInput8, (VOID**)&_di, NULL
//		);
//	if (hr != DI_OK) return false;
//	trace("DirectInput has been created");
//
//	hr = _di->CreateDevice(GUID_SysKeyboard, &_Keyboard, NULL);
//	if (hr != DI_OK) return false;
//	trace("DirectInput keyboard has been created");
//
//	hr = _Keyboard->SetDataFormat(&c_dfDIKeyboard);
//	trace("SetDataFormat for keyboard successfully");
//
//	hr = _Keyboard->SetCooperativeLevel(_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
//	trace("SetCooperativeLevel for keyboard successfully");
//
//	DIPROPDWORD dipdw;
//
//	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
//	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
//	dipdw.diph.dwObj = 0;
//	dipdw.diph.dwHow = DIPH_DEVICE;
//	dipdw.dwData = KEYBOARD_BUFFER_SIZE; // Arbitary buffer size
//
//	trace("SetProperty for keyboard successfully");
//
//	hr = _Keyboard->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
//	if (hr != DI_OK) return false;
//
//	hr = _Keyboard->Acquire();
//	if (hr != DI_OK) return false;
//
//	trace("Keyboard has been acquired successfully");
//	return true;
//}
//
//
//void KeyBoard::GetState()
//{
//	// Lấy trạng thái của bàn phím
//	HRESULT hr = this->_Keyboard->GetDeviceState(sizeof(_KeyBuffer), (LPVOID)&_KeyBuffer);
//	if (FAILED(hr))
//	{
//		// Nếu bàn phím đang bị nhả ra thì yêu cầu lại
//		while (this->_Keyboard->Acquire() == DIERR_INPUTLOST);
//	}
//}
//
//int KeyBoard::IsKeyDown(int Key)
//{
//	// Trả về phím có được nhấn hay không. 0x80 nhằm xác định giá trị các bit đàu tiên
//	return (_KeyBuffer[Key] & 0x80) > 0;
//}
//
//KeyBoard::~KeyBoard()
//{
//}
