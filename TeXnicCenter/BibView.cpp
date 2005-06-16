// BibView.cpp: implementation of the CBibView class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "texniccenter.h"
#include "global.h"
#include "BibView.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBibView::CBibView()
{

}

CBibView::~CBibView()
{

}

// Took code from CEnvironmentView
void CBibView::OnUpdate(CProjectView* pSender, LPARAM lHint, LPVOID pHint) {
	switch( lHint )
	{
		case COutputDoc::hintParsingFinished:
			{
				//-----------------------------------------------------------
				// remember expanded items
				CString 			strSelectedItem = GetItemPath( GetSelectedItem() );
				CStringArray	astrExpandedItems;
				GetExpandedItems( astrExpandedItems );

				//-----------------------------------------------------------
				// fill view with parsing results
				const CStructureItemArray &a = GetProject()->m_aStructureItems;

				// initialization
				DeleteAllItems();

				HTREEITEM hBibParent, hBibRoot;
				hBibRoot = InsertItem(AfxLoadString(STE_BIB_FILES), 
							CStructureParser::bibFile, CStructureParser::bibFile, 
							TVI_ROOT, TVI_SORT);
				// fill view
				for(int i = 0; i < a.GetSize(); i++ )
				{
					const CStructureItem &si = a.GetAt( i );

					switch( si.m_nType )
					{
					case CStructureParser::bibFile:
							hBibParent = InsertItem( 
								si.m_strPath, 
								si.m_nType, si.m_nType, 
								hBibRoot, TVI_SORT );
							SetItemData( hBibParent, i );
						break;
					case CStructureParser::bibItem:
						{
							//Better display all stuff, even without a title
							//if (si.m_strTitle.GetLength() == 0)
							//	break; //no title -> no display

							HTREEITEM hItem = InsertItem( 
								si.m_strCaption, 
								si.m_nType, si.m_nType, 
								hBibParent, TVI_SORT );
							SetItemData( hItem, i );
						}
						break;
					}
				}

				//-----------------------------------------------------------
				//try to expand items
				ExpandItems( astrExpandedItems );
				SelectItem( GetItemByPath( strSelectedItem ) );
			}
			break;
	}
}