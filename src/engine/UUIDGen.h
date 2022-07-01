#pragma once

#include "api.h"
#include <string>

#if  defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define WINDOWS_
#pragma comment(lib,"rpcrt4.lib")
#include <rpc.h>

#else // linux
#define LINUX_
#include <uuid/uuid.h>

#endif

namespace Keyhan {
	class KEYHAN_API UUID {
		std::string id;
	public:
		void		GenerateID(std::string class_name);
		std::string GetStringID();
		const char* GetCStringID();
		UUID		GetUUID();
	};
};

