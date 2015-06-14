//
//  cl_example_c.c
//  OpenCL.ShowDevice
//
//  Created by Peter.Li on 2015/6/13.
//  Copyright (c) 2015年 Peter.Li. All rights reserved.
//

#include <stdio.h>
#include "cl_example_c.h"

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

int display_opencl_platform_using_c() {
    
    cl_int err = 0;
    
    // Get platform number.
    cl_uint plat_num = 0;
    err = clGetPlatformIDs(0, 0, &plat_num);
    if(err != CL_SUCCESS) {
        printf("Get OpenCL platform error!\n");
        return 0;
    }
    
    if (plat_num <= 0) {
        printf("OpenCL platform doesn't exist.\n");
        return 0;
    }
    
    cl_platform_id *plat_ids = (cl_platform_id*)malloc(sizeof(cl_platform_id) * plat_num);
    
    err = clGetPlatformIDs(plat_num, plat_ids, &plat_num);
    if (CL_SUCCESS != err) {
        printf("Get platform elist error!\n");
        free(plat_ids);
        return 0;
    }
    
    size_t plat_name_length = 0;
    err = clGetPlatformInfo(plat_ids[0], CL_PLATFORM_NAME, 0, 0, &plat_name_length);
    if (err != CL_SUCCESS) {
        printf("Get OpenCL platform name length error!\n");
        free(plat_ids);
        return 0;
    }
    
    char *plat_name = (char*)malloc(sizeof(char) * plat_name_length);
    
    err = clGetPlatformInfo(plat_ids[0], CL_PLATFORM_NAME, plat_name_length, (void*)plat_name, &plat_name_length);
    
    if (err != CL_SUCCESS) {
        printf("Get OpneCL platform name error!\n");
        free(plat_ids);
        free(plat_name);
        return 0;
    }
    
    printf("OpenCL platform name : %s", plat_name);
    
    free(plat_ids);
    free(plat_name);
    
    return 0;
}

