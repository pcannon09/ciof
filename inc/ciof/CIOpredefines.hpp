/**
 * EXAMPLEpredefines.h - pcannonProjectStandards
 * Predefines for C and C++ projects
 * STD Information: 20250723 - 1.0S
 * NOTICE: 
 * - RENAMED TO CIOSpredefines.hpp
 */

#pragma once

// Project setup
#define CIOS_DEFAULT_CPP_STD			201103L

// Versioning
#define CIOS_VERSION_MAJOR            0
#define CIOS_VERSION_MINOR            0
#define CIOS_VERSION_PATCH            0

#define CIOS_VERSION_STD              0

// Version states:
// * dev
// * alpha
// * beta
// * build
#define CIOS_VERSION_STATE          "dev"

#define CIOS_VERSION                ((CIOS_VERSION_MAJOR<<16)|(CIOS_VERSION_MINOR<<8)|(CIOS_VERSION_PATCH)|(CIOS_VERSION_STATE << 24))

#define CIOS_VERSION_CHECK(CIOS_VERSION_MAJOR, CIOS_VERSION_MINOR, CIOS_VERSION_PATCH, CIOS_VERSION_STATE) \
    (((CIOS_VERSION_MAJOR)<<16)|((CIOS_VERSION_MINOR)<<8)|(CIOS_VERSION_PATCH)|((CIOS_VERSION_STATE) << 24))

// Macro utils
#define CIOS_STRINGIFY(x) #x
#define CIOS_TOSTRING(x) CIOS_STRINGIFY(x)

#ifndef CIOS_DEV
#   define CIOS_DEV true
#endif // !defined(CIOS_DEV)

// OS Checks
#ifdef WIN32
#	define CIOS_OS_WIN32
#elif defined(__APPLE__) || defined(__MACH__) || defined(Macintosh)
#	define CIOS_OS_MACOS
#elif defined(__linux__) || defined(__unix) || defined(__unix__)
#	define CIOS_OS_UNIX_LINUX
#elif defined(__FreeBSD__)
#	define CIOS_OS_FREEBSD
#else
#	warning "Current platform might not supported"
#endif // defined(WIN32) // Platform check

