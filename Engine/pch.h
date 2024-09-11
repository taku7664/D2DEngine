#include <windows.h>

#include <string>
#include <string_view>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

#include <random>
#include <iostream>
#include <sstream>
#include <format> 
#include <system_error>

//DirectX
#include <directxtk/SimpleMath.h>

//Direct2D
#include <d2d1.h>
#include <dwrite.h>
#include <d2d1_1helper.h>
#include <d2d1effects.h>
#include <d2d1effectauthor.h>
#include <wincodec.h>
#include <comdef.h>
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")

// GameInput
#include "Include/GameInput/GameInput.h"

//Custom
#include "Helper/CommonEnum.h"
#include "Helper/CommonDef.h"
#include "Helper/ReferenceCounter.h"

#include "Helper/DataType/Vector.h"
#include "Helper/DataType/Matrix.h"
#include "Helper/DataType/ColorF.h"

#include "Helper/Time/Time.h"
#include "Helper/Input/Input.h"
#include "Helper/Utillity/Utillity.h"
#include "Helper/Debug/Debug.h"

#include "Interface/ILifeCycle.h"