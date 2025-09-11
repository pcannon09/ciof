#pragma once

#include "CIOpredefines.hpp"

#if __cplusplus >= CIOS_DEFAULT_CPP_STD

#define __CIOF_OK

#include <string>

namespace ciof
{
	typedef struct CIOFOutputConfig
	{
		// Add a space between parameter automaticalliy
		bool spacing = false;
		
		// Ignore custom and predefined formatting keywords
		bool ignoreAllFormating = false;

		// Process config
		bool processing = true;

		std::string spacingDelimeter = " ";
	} CIOFOutputConfig;

	extern CIOFOutputConfig outputConf;

	namespace impl
	{
    	template <typename T>
    	std::string toString(const T& val);

    	template <typename... Args>
    	std::string parse(const std::string& fmt, Args&&... args);

    	template <typename T>
    	void __out(T _t);

    	template <typename T, typename... Args>
    	void __out(T _t, Args... _args);
    }

	// NOTE: OUTPUT
	
	// PRINT
	template <typename T>
	void print(T _t);

	template <typename T, typename ... Args>
	void print(T _t, Args ... _args);

	// ECHO
	template <typename T>
	void echo(T _t);

	template <typename T, typename ... Args>
	void echo(T _t, Args ... _args);

	// NOTE: INPUT
	template <typename T>
	void input(const std::string &_prompt, T *_var);

	template <typename T>
	void input(T *_var);

	// NOTE: UTILS
    template <typename T, typename ... Args>
	std::string format(T _t, Args ... _args);
}

#include "../../src/ciof.ipp"

#else
# 	error "Cannot compile with the current C++ standard"
# 	pragma message("Use C++ " CIOS_TOSTRING(CIOS_DEFAULT_CPP_STD) " or higer instead of " CIOS_TOSTRING(__cplusplus))
#endif // __cplusplus

