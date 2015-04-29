///////////////////////////////////////////////////////////////////////////////
// vim:         ts=4 sw=4
// Name:        wxm/def.h
// Description: wxMEdit Common Definitions
// Copyright:   2013-2015  JiaYanwei   <wxmedit@gmail.com>
// License:     GPLv3
///////////////////////////////////////////////////////////////////////////////

#ifndef _WXM_DEF_H_
#define _WXM_DEF_H_

#ifdef _MSC_VER
# pragma warning( push )
# pragma warning( disable : 4996 )
#endif
// disable 4996 {
#include <wx/string.h>
#include <wx/version.h>
// disable 4996 }
#ifdef _MSC_VER
# pragma warning( pop )
#endif

#include <vector>

#define WXMEDIT_VERSION	"2.9.9.3"

#if wxMAJOR_VERSION==2
  typedef int wxPrintOrientation;
# define wxGetSelectedChoices wxGetMultipleChoices
#endif

typedef std::vector<size_t> LineNumberList;

namespace wxm
{
	static const wxString MonoFontName =
#ifdef __WXMSW__
		wxT("Courier New")
#elif defined(__APPLE__) && defined(__MACH__)
		wxT("Monaco")
#else
		wxT("Monospace")
#endif
	;

	static const wxString ASCIIArtFontName =
#ifdef __WXMSW__
		wxT("Courier New")
#elif defined(__APPLE__) && defined(__MACH__)
		wxT("Andale Mono")
#else
		wxT("Monospace")
#endif
	;

	static const long MINVAL_MAXLINELEN = 80;
	static const long MAXVAL_MAXLINELEN = 65536;

	static const size_t FIRSTLINE_SYNTAXPATTEN_MAXLEN = 16;

	static const int DEFAULT_WINDOW_WIDTH = 990;
	static const int DEFAULT_WINDOW_HEIGHT = 660;

}; // namespace wxm

#endif //_WXM_DEF_H_
