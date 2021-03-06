﻿#pragma once

#include <vector>
#include <list>
#include <sstream>
#include <iostream>
#include <iostream>
#include <stdarg.h> 
#include <cstdint>
#include <random>  
#include <intrin.h>
#include <map>

using namespace std;

#ifdef _DEBUG
    #define FUKU_DEBUG {printf("%s:%d | %s\n",__FILE__,__LINE__,__FUNCTION__);}
#else
    #define FUKU_DEBUG __nop();
#endif

#define FUKU_GET_RAND(_min,_max) ((_min) == (_max) ? (_min) : ((_min) + ( (rand() | rand() << 16) %(((_max) + (((_max) == UINT_MAX) ? 0 : 1)) - (_min)))))
#define GET_BITES(src, mask) ( (src) & (mask) )
#define HAS_FULL_MASK(src, mask) ( ( (src) & (mask) ) == (mask) )

#define FUKU_ASSERT(cond) if( !(cond)){FUKU_DEBUG}   
#define FUKU_ASSERT_NEQ(lhs, rhs) if( !((lhs) == (rhs)) ){FUKU_DEBUG}
#define FUKU_ASSERT_EQ(lhs, rhs) if( ((lhs) == (rhs)) ){FUKU_DEBUG}
#define FUKU_ASSERT_GT(lhs, rhs) if( ((lhs) >  (rhs)) ){FUKU_DEBUG}

#include "capstone\include\capstone\capstone.h"
#include "fukutasm.h"

