// (C) Copyright 2002-2003 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- IPieSectorColor.h : Declaration of the CPieSectorColor
//-----------------------------------------------------------------------------
#pragma once

#include "resource.h"

#include "DeepPropInspectorUI.h"
#include "DynPropBase.h"
#include "../DeepPropInspector/AsdkPie.h"

//-----------------------------------------------------------------------------
//----- CPieSectorColor
class ATL_NO_VTABLE CPieSectorColor : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPieSectorColor, &CLSID_PieSectorColor>,
	public ISupportErrorInfo,
	public IDispatchImpl<IPieSectorColor, &IID_IPieSectorColor, &LIBID_AsdkDeepPropInspectorUILib, 1, 0>,
    public DynPropBaseImpl<CPieSectorColor>
{
protected:
	IDynamicPropertyNotify2 *m_pNotify ;

public:
	CPieSectorColor () {}

	DECLARE_REGISTRY_RESOURCEID(IDR_PIESECTORCOLOR)
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(CPieSectorColor)
		COM_INTERFACE_ENTRY(IPieSectorColor)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(ICategorizeProperties)
		COM_INTERFACE_ENTRY(IAcPiPropertyDisplay)
		COM_INTERFACE_ENTRY(IDynamicProperty2)
	END_COM_MAP()

	BEGIN_PERPROPDISPLAY_MAP()
	END_PERPROPDISPLAY_MAP()

	//- ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo) (REFIID riid) ;

	HRESULT FinalConstruct () {
		return (S_OK) ;
	}
	
	void FinalRelease () {
	}

public:
	//- IDynamicProperty2
	STDMETHOD(GetGUID) (GUID *propGUID) ;
	STDMETHOD(GetDisplayName) (BSTR *bstrName) ;
	STDMETHOD(IsPropertyEnabled) (IUnknown *pUnk, BOOL *pbEnabled) ;
	STDMETHOD(IsPropertyReadOnly) (BOOL *pbReadonly) ;
	STDMETHOD(GetDescription) (BSTR *bstrName) ;
	STDMETHOD(GetCurrentValueName) (BSTR *pbstrName) ;
	STDMETHOD(GetCurrentValueType) (VARTYPE *pVarType) ;
	STDMETHOD(GetCurrentValueData) (IUnknown *pUnk, VARIANT *pvarData) ;
	STDMETHOD(SetCurrentValueData) (IUnknown *pUnk, const VARIANT varData) ;
	STDMETHOD(Connect) (IDynamicPropertyNotify2 *pSink) ;
	STDMETHOD(Disconnect) () ;

	//- IPerPropertyDisplay
	//STDMETHOD(GetCustomPropertyCtrl) (VARIANT varId, LCID lcid, BSTR *pProgId) ;

	//- IPieSectorColor

} ;

//-----------------------------------------------------------------------------
OBJECT_ENTRY_AUTO(__uuidof(PieSectorColor), CPieSectorColor)
//- See DynPropOrder.h for details
//OPM_DYNPROP_OBJECT_ENTRY_AUTO(CPieSectorColor, AsdkPie)
#include "DynPropOrder.h"
