# OpenCL.DeviceList
This project is a sample example for showing OpenCL platform and device list using OpenCL C++ wrapper. Originally, OpenCL uses C Language API interface.


Here, we use OpenCL C++ wrapper to demostrate device and platform information because it can show clear, readable, and short code.


If you want to get OpenCL platform list using tranditional C language,

cl_uint num = 0;
cl_int err = 0;

// Get platform number.
err = clGetPlatformIDs(0, 0, &num);

if(err != CL_SUCCESS) {
    ...
    return 0;
}

cl_platform_id *plat_ids = (cl_platform_id*)malloc(sizeof(cl_platform_id) * num);

err = clGetPlatformIDs(num, plat_ids, &num);

if (CL_SUCCESS != err) {
    ...
    return 0;
}

// ... do something ...

free (plat_ids);


They use long code and must free memory manually. If we use OpenCL C++ wrappe, our code can be simpily as follow, 


VECTOR_CLASS<cl::Platform> plat_list;
cl::Platform::get(&plat_list);


C++ wrapping example just use two line to get all platform object. When program end, memory will be released automatically.


Now, we show another example that display plaform name and version. When using tranditaional C Language, we must do as follow

1. Get Information length.
2. Allocate memory space manually.
3. Call OpenCL API interface.
4. Check error message.
5. If get information successfully, display information string.
6. Free memory

Those processes are very nonsene. But, we use the C++ wrapping to display one information, this code can be jus one line.

For example, using C Language:

int main() {

cl_int err = 0;
cl_uint plat_num = 0;
cl_platform_id *plat_ids = NULL;
size_t plat_name_length = 0;
char *plat_name = NULL;

// .....
// Get platform number and ids.
// .....

err = clGetPlatformInfo(plat_ids[0], CL_PLATFORM_NAME, 0, 0, &plat_name_length);
if (err != CL_SUCCESS) {
printf("Get OpenCL platform name length error!\n");
free(plat_ids);
return 0;
}

plat_name = (char*)malloc(sizeof(char) * plat_name_length);

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


We must write much code for getting string length, checking error code, allocting and free memory.

No, we using C++ Wrapping to get platform name and display it as follow,

std::cout << plat_list[0].getInfo<CL_PLATFORM_NAME>() << std::endl;


We can see this method decrease code length. 






