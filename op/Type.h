#pragma once
#ifndef __TYPE_H_
#define __TYPE_H_
//version �� �� �޶� ����
#define MAKE_VERSION(a,b,c,d) (a<<24)|(b<<16)|(c<<8)|d

#define SAFE_CLOSE(h)if(h) CloseHandle(h);h=NULL;

#define SAFE_DELETE(ptr) if(ptr)delete ptr;ptr=nullptr

#define SAFE_DELETE_ARRAY(ptr) if(ptr)delete[] ptr;ptr=nullptr

#include <string>
#include <boost/locale.hpp>
#define _sto_wstring(s) boost::locale::conv::to_utf<wchar_t>(s, "GBK")
#define _wsto_string(s)  boost::locale::conv::from_utf(s,"GBK")

enum BACKTYPE { NORMAL,WINDOWS, GDI, DX, OPENGL };

long inline show_error(wchar_t* format,...) {
	va_list args;
	wchar_t buf[256];
	va_start(args, format);
	vswprintf(buf, format, args);
	va_end(args);
	return ::MessageBox(NULL, buf, L"op error", 0);
}
#endif