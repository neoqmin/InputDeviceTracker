#include "stdafx.h"
#include <winuser.h>
#include "CRawInput.h"

/**
	@brief		Constructor
	@date		2015.07.03
	@author		Kevinh Hwang
*/
CRawInput::CRawInput() :
	m_pRawInputDevice(NULL),
	m_nDevices(0)
{

}

/**
	@brief		Destructor
	@date		2015.07.03
	@author		Kevin Hwang
*/
CRawInput::~CRawInput()
{

}

/**
	@brief		Adding a input device.
	@param[in]	usUsagePage
	@param[in]	usUsage
	@param[in]	dwFlags
	@param[in]	hwndTarget
	@return		ERROR_SUCCESS		
	@return		DWORD				Error code
	@date		2015.07.03
	@author		Kevin Hwang
*/
DWORD
CRawInput::AddInputDevice(IN USHORT usUsagePage,
						  IN USHORT usUsage,
						  IN DWORD dwFlags,
						  IN HWND hwndTarget)
{
	DWORD	dwRet = ERROR_SUCCESS;

	do {
		PRAWINPUTDEVICE		pNewInputDevice;

		if(m_pRawInputDevice) {
			m_pRawInputDevice = (PRAWINPUTDEVICE)realloc(m_pRawInputDevice, (m_nDevices+1)*sizeof(RAWINPUTDEVICE));

			pNewInputDevice = &m_pRawInputDevice[m_nDevices];
		} else {
			pNewInputDevice = m_pRawInputDevice = (PRAWINPUTDEVICE)malloc(sizeof(RAWINPUTDEVICE));
		}

		pNewInputDevice->usUsagePage = usUsagePage;
		pNewInputDevice->usUsage = usUsage;
		pNewInputDevice->dwFlags = dwFlags;
		pNewInputDevice->hwndTarget = hwndTarget;		

		m_nDevices++;
	} while(FALSE);

	return dwRet;
}

/**
	@brief		Start notification that raw input devices.
	@return		TRUE			Success
	@return		FALSE			Fail
	@date		2015.07.03
	@authro		Kevin Hwang
*/
BOOL
CRawInput::StartRawInputData()
{
	return RegisterRawInputDevices(m_pRawInputDevice, m_nDevices, sizeof(RAWINPUTDEVICE));
}