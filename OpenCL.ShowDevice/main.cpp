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


void showPlatformInfo(cl::Platform& platform) {
    std::cout << platform.getInfo<CL_PLATFORM_NAME>();
    std::cout << "(" << platform.getInfo<CL_PLATFORM_VERSION>() << ")" << std::endl;
    std::cout << "Vendor: " << platform.getInfo<CL_PLATFORM_VENDOR>() << std::endl;
    std::cout << "Extension: " << platform.getInfo<CL_PLATFORM_EXTENSIONS>() << std::endl;
}

void showDeviceInfor(cl::Device& device) {
    std::cout << device.getInfo<CL_DEVICE_NAME>();
    std::cout << "(" << device.getInfo<CL_DEVICE_VERSION>() << ")" << std::endl;
    std::cout << "Driver Version: " << device.getInfo<CL_DRIVER_VERSION>() << std::endl;
    std::cout << "Address bit : " << device.getInfo<CL_DEVICE_ADDRESS_BITS>() << std::endl;
    std::cout << "Global Memory size: " << device.getInfo<CL_DEVICE_GLOBAL_MEM_SIZE>() / (1024*1024) << " MB" << std::endl;
    std::cout << "Local Memory size: " << device.getInfo<CL_DEVICE_LOCAL_MEM_SIZE>() / 1024 << " KB" << std::endl;
    std::cout << "Work Group size: " << device.getInfo<CL_DEVICE_MAX_WORK_GROUP_SIZE>() << std::endl;
    std::cout << "Max Allocated size : " << device.getInfo<CL_DEVICE_MAX_MEM_ALLOC_SIZE>() / 1024 << " KB" << std::endl;
}

int main(int argc, const char * argv[]) {

    try {
        VECTOR_CLASS<cl::Platform> plat_list;
        cl::Platform::get(&plat_list);
        
        for (auto plat : plat_list) {
            std::cout << "===== Platform Info Start ===== " << std::endl;
            showPlatformInfo(plat);
            std::cout << std::endl;
            
            VECTOR_CLASS<cl::Device> dev_list;
            plat.getDevices(CL_DEVICE_TYPE_ALL, &dev_list);
            for (auto dev : dev_list) {
                std::cout << "----- Device Info Start -----" << std::endl;
                showDeviceInfor(dev);
                std::cout << "----- Device Info Start -----" << std::endl << std::endl;
            }
            std::cout << "===== Platform Info End ===== " << std::endl << std::endl;
        }
        
    } catch (std::exception e) {
        std::cout << "C++ Excpetion:" << std::endl << e.what() << std::endl;
    } catch (cl::Error err) {
        std::cout << "OpenCL Error:" << std::endl;
        std::cout << err.what() << std::endl;
    }
    
    return 0;
}
