// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__FDE1479E_562F_4636_97C6_8A798ACBB6DA__INCLUDED_)
#define AFX_STDAFX_H__FDE1479E_562F_4636_97C6_8A798ACBB6DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <stdio.h>

#include <windows.h>
#include "winternl.h"
#include <iostream>
#include "ntstatus.h"

#pragma comment(lib,"ntdll.lib")

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__FDE1479E_562F_4636_97C6_8A798ACBB6DA__INCLUDED_)

