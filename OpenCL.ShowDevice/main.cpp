//
//  main.cpp
//  OpenCL.ShowDevice
//
//  Created by Peter.Li on 2015/6/7.
//  Copyright (c) 2015年 Peter.Li. All rights reserved.
//

#include <iostream>
#include <string>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#define __CL_ENABLE_EXCEPTIONS
#include "cl.hpp"

#include "cl_example_c.h"
#include "cl_example_cpp.h"

int main(int argc, const char * argv[]) {
    
    std::cout << "== OpenCL using C Language:" << std::endl;
    
    display_opencl_platform_using_c();
    
    std::cout << std::endl << std::endl << "== OpenCL using C++ Wrapper:" << std::endl;
    
    display_opencl_platform_using_cpp();
    
    return 0;
}
