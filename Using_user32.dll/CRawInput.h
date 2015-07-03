#ifndef _CRAWINPUT_H_
#define _CRAWINPUT_H_

class CRawInput {
public:
	CRawInput();
	~CRawInput();

	DWORD AddInputDevice(IN USHORT usUsagePage, IN USHORT usUsage, IN DWORD dwFlags, IN HWND hwndTarget);
	BOOL StartRawInputData();
	LRESULT WindowProcedure(IN HWND hWnd, IN UINT message, IN WPARAM wParam, IN LPARAM lParam);

protected:
	PRAWINPUTDEVICE		m_pRawInputDevice;
	USHORT				m_nDevices;
};

#endif