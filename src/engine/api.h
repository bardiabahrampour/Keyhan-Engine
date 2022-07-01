#pragma once

#ifdef ENGINE_EXPORTS
#define KEYHAN_API __declspec(dllexport)
#else
#define KEYHAN_API_API __declspec(dllimport)
#endif