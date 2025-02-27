
#ifndef WRAPPER_H
#define WRAPPER_H

#ifdef _WIN32
	#define EXPORT_API __declspec(dllexport)
#else
	#define EXPORT_API __attribute__((visibility("default")))
#endif

extern "C" {
	EXPORT_API void process_csv(const char* finename);
}

#endif
