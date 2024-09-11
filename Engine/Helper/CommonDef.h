#pragma once

#define _ABSTRACT class
#define _INTERFACE class
#define _CALLBACK void

#define SAFE_RELEASE(ptr)  if( (ptr) ) { (ptr)->Release(); (ptr) = nullptr; }
#define SAFE_DELETE(ptr)   if( (ptr) ) { delete (ptr); (ptr) = nullptr; }
