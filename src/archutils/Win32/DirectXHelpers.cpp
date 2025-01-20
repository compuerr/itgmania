#include "global.h"
#include "DirectXHelpers.h"
#include "RageUtil.h"
#include <cstdarg>
#include <dinput.h>
#include <d3d9.h>
#include <mmsystem.h> // dsound.h needs this
#include <dsound.h>
#include <stdexcept>

RString GetErrorString(HRESULT hr);

RString hr_ssprintf( int hr, const char *fmt, ... )
{
	va_list	va;
	va_start(va, fmt);
	RString s = vssprintf( fmt, va );
	va_end(va);

	RString szError = GetErrorString(hr);
	return s + ssprintf(" (%s)", szError.c_str());
}

#define DXERRMSG(hrcode, dummy) case hrcode: return #hrcode;

RString GetErrorString(HRESULT hr)
{
	switch (hr)
	{
#include "DirectXErrorList.h"
	default: return ssprintf("unknown HRESULT 0x%8.8X", hr);
	}
}

/*
 * Copyright (c) 2001-2005 Chris Danford, Glenn Maynard
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
