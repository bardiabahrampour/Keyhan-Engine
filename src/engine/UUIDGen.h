#pragma once

#include "api.h"
#include <string>

#if  defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

#define WINDOWS_

#pragma comment(lib,"rpcrt4.lib")
#include <rpc.h>

typedef UUID WIN_UUID;

#else // linux

#define LINUX_
#include <uuid/uuid.h>

#endif

//	UUID Generator for classes, useful for debugging

namespace Keyhan {
	class __declspec(dllexport) ID {
		std::string id;
	public:
		void		GenerateID(std::string class_name);
		std::string GetStringID();
	};
};
