/********************************************************************
*
* $Workfile:$
* $Revision$
* $Modtime:$
* $Author$
*
* �nderungen:
*	$History:$
*
*********************************************************************/

/********************************************************************
*
* Declarations for files generated by COM Interface Wrapper Wizard
* (CIWW)
*
* Copyright � 2001 Sven Wiegand (sven.wiegand@web.de)
*
********************************************************************/

#ifndef __INTERFACEWRAPPERTOOLS_H__
#define __INTERFACEWRAPPERTOOLS_H__

#define GETTHIS(AggregatingClass, InterfaceImpl) \
	AggregatingClass	*pThis = \
		((AggregatingClass*)((BYTE*)this - offsetof(AggregatingClass, InterfaceImpl))); \


#endif //__INTERFACEWRAPPERSTOOLS_H__