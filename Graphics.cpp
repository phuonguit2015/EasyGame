#include "Graphics.h"


CGraphics::CGraphics()
{
	m_D3DObject = NULL;
	m_D3DDevice = NULL;
}


CGraphics::~CGraphics()
{
	if (m_D3DDevice != NULL){
		m_D3DDevice->Release();
	}

	if (m_D3DObject != NULL){
		m_D3DObject->Release();
	}
}

// Public 
bool CGraphics::InitWithWindowHandle(HWND hwnd)
{
	if (!InitDirect3DObject()){
		return false;
	}
	D3DPRESENT_PARAMETERS presentationParameters;										// Tạo thiết bị vẽ
	ZeroMemory(&presentationParameters, sizeof(presentationParameters));
	presentationParameters.BackBufferCount = 1;											// Số lượng back buffer
	presentationParameters.BackBufferFormat = D3DFMT_UNKNOWN;							// Chọn UNKNOW, DirectX sẽ tự chọn 1 định dạng phù hợp cho Device
	presentationParameters.BackBufferWidth = this->m_Width;								// Chiều rộng back buffer
	presentationParameters.BackBufferHeight = this->m_Height;							// Chiều cao back buffer
	presentationParameters.hDeviceWindow = hwnd;										// Handle của cửa sổ mình sẽ vẽ lên
	presentationParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;							// Phương thức swap của Buffer
	presentationParameters.Windowed = true;												// Chế độ có cửa sổ
	HRESULT hr = m_D3DObject->CreateDevice(D3DADAPTER_DEFAULT,							// Chọn DEFAULT ADAPTER
		D3DDEVTYPE_HAL,																	// su dung ho tro cua phan cung. Có rất nhiều sự lựa chọn.
		hwnd,																			// Cửa sổ vẽ
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,											// Hard ware vertex processing
		&presentationParameters,														// Các thông số cho back buffer
		&this->m_D3DDevice																// Hàm tạo Device
		);
	return HashHRResult(hr);
}

bool CGraphics::RenderSence()
{
	
	//TO DO
	
	return true;

}


void CGraphics::BeginRender()
{
	if (m_D3DDevice == NULL){
		return;
	}
	m_D3DDevice->Clear(1, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1, NULL);				// Xóa cửa số vẽ bằng màu trắng 
	m_D3DDevice->BeginScene();
}

void CGraphics::EndRender()
{
	m_D3DDevice->EndScene();
	m_D3DDevice->Present(0, 0, 0, 0);
}

// Private
bool CGraphics::InitDirect3DObject()
{
	m_D3DObject = Direct3DCreate9(D3D_SDK_VERSION);							// Tạo một đối tượng D3D
	return m_D3DObject != NULL;	
}

bool CGraphics::HashHRResult(HRESULT hResult)
{
	if (SUCCEEDED(hResult)){
		return true;	
	}
}