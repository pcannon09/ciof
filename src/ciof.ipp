#pragma once

#include "../inc/ciof/ciof.hpp"

#ifndef __CIOF_OK
# 	error "CIOF Is not OK, make sure to not have any errors at compile time"
#endif // NOT : __CIOF_OK

#include <tuple>
#include <string>
#include <sstream>
#include <type_traits>
#include <iostream>
#include <cctype>
#include <array>

namespace ciof
{
	namespace impl
	{
    	// Convert arbitrary types to string
    	template <typename T>
    	std::string toString(const T& val)
    	{
        	if constexpr (std::is_convertible_v<T, std::string>)
            	return val;

        	else if constexpr (std::is_arithmetic_v<T>)
            	return std::to_string(val);

        	else
        	{
            	std::ostringstream oss;
            	oss << val;

            	return oss.str();
        	}
    	}

    	template <typename ... Args>
    	std::string parse(const std::string& fmt, Args&& ... args)
    	{
        	std::string totalParsed;
        	std::string paramDigits;

        	auto tup = std::forward_as_tuple(std::forward<Args>(args) ...);

        	for (size_t i = 0; i < fmt.size(); ++i)
        	{
            	const char c = fmt[i];

				// Get param number
            	if (c == '%')
            	{
                	// Escaped with `%%`
                	if (i + 1 < fmt.size() && fmt[i + 1] == '%')
                	{
                    	totalParsed += '%';
                    	++i;

                    	continue;
                	}

                	// Collect digits after %
                	size_t j = i + 1;

                	paramDigits.clear();

                	while (j < fmt.size() && std::isdigit(fmt[j]))
                	{
                    	paramDigits.push_back(fmt[j]);
                    	++j;
                	}

                	if (!paramDigits.empty())
                	{
                    	int idx = std::stoi(paramDigits) - 1; // 1-based
                    	if (idx >= 0 && idx < (int)sizeof ... (Args))
                    	{
                        	std::apply([&](auto&& ... elems) {
                            		std::array<std::string, sizeof ... (Args)> arr{ toString(elems) ... };
                            		totalParsed += arr[idx];
                        			}, tup);
                    	}
                	}

                	i = j - 1; // skip digits
            	}

            	else
            	{
                	totalParsed.push_back(c);
            	}
        	}

        	return totalParsed;
    	}

    	// Printing wrappers
    	template <typename T>
    	void __out(T _t)
    	{
        	std::cout << _t;
    	}

    	template <typename T, typename ... Args>
    	void __out(T _t, Args ... _args)
    	{
			if (ciof::outputConf.processing)
			{
        		std::string parsed = parse(_t, _args ...);

        		std::cout << parsed;
        	}

			else
        	{
				std::cout << _t;

				ciof::impl::__out(_args ...);
        	}
    	}
	}

	// NOTE: OUTPUT
	
	// PRINT
	template <typename T>
	void print(T _t)
	{
		ciof::impl::__out(_t);
		std::cout << std::endl;
	}

	template <typename T, typename ... Args>
	void print(T _t, Args ... _args)
	{
		ciof::impl::__out(_t, _args ...);
		std::cout << std::endl;
	}

	// ECHO
    template <typename T>
    void echo(T _t)
    {
		ciof::impl::__out(_t);
    }

    template <typename T, typename ... Args>
    void echo(T _t, Args ... _args)
    {
		ciof::impl::__out(_t, _args ...);
    }

    // NOTE: UTILS
	template <typename T>
	void input(const std::string &_prompt, T *_var)
	{
		ciof::echo(_prompt);

		std::getline(std::cin, *_var);
	}

	template <typename T>
	void input(T *_var)
	{ std::getline(std::cin, *_var); }

    // NOTE: UTILS

    template <typename T, typename ... Args>
	std::string format(T _t, Args ... _args)
	{
		std::string parsed = ciof::impl::parse(_t, _args ...);

		return parsed;
	}
}

