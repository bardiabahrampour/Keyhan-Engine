#include "UUIDGen.h"

void Keyhan::ID::GenerateID(std::string class_name) {
#ifdef WINDOWS_

	//Windows Implementation

	WIN_UUID uuid;
	UuidCreate(&uuid);

	unsigned char* temp_str;
	UuidToStringA(&uuid, &temp_str);

	id = class_name + '-' + (const char*)temp_str;

	RpcStringFreeA(&temp_str);

#else

	//Linux Implementation

	uuid_t uuid;
	uuid_generate_random(uuid);
	char s[37];
	uuid_unparse(uuid, s);
	id = s + class_name;

#endif  
}

std::string Keyhan::ID::GetStringID() {

	if (this->id.empty()) {
		return "null";
	}

	return this->id;
}
