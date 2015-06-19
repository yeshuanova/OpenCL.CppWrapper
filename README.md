#OpenCL C++ Wrapper
The project is a sample example for showing OpenCL platform and device list using traditional C language and OpenCL C++ wrapper. Originally, OpenCL uses traditional C language API interface. Here, we use OpenCL C++ wrapper to demonstrate device and platform information because it can show clear, readable, and short code.

If you want to get OpenCL platform list using traditional C language, as follows:

```c
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

```
The reference of OpenCL platform is `cl_platform_id` type. All platforms in host are stored in `plat_ids` array. The example uses long code and must free memory manually. If we use OpenCL C++ wrapper, our code can be simply as follow:

```cpp
VECTOR_CLASS<cl::Platform> plat_list;
cl::Platform::get(&plat_list);
```
`VECTOR_CLASS` is a vector type defined by `std::vector` or `cl::vector` and `cl::Platform` is platform wrapper class. `cl::Platform::get` function gets all platforms as `cl::Platform` and add to vector `plat_list` variable. OpenCL C++ Wrapper just use two lines to get all platform object, and when program ends, memory will be released automatically.

Now, we show another example that displays platform name and version. When using traditional C Language, we must do some steps as follow:

1. Get length of information string.
2. Allocate memory space manually.
3. Call OpenCL API interface.
4. Check error code.
5. Display information string if get information successfully.
6. Free memory

Those processes are long and don't be safe. But, we use the C++ wrapping to display one information, this code can be just one line. For example, using C Language:

```c
cl_int err = 0;
cl_platform_id *plat_ids = NULL;

// ...
// Get platform list.
// ...
    
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
	printf("Get OpenCL platform name error!\n");
	free(plat_ids);
	free(plat_name);
	return 0;
}
    
printf("OpenCL platform name : %s", plat_name);

free(plat_ids);
free(plat_name);
```

We must write much code to get string length, checking error code, allocate and free memory. Now, we using C++ wrapping to get platform name and display it as follows:

```cpp
std::cout << plat_list[0].getInfo<CL_PLATFORM_NAME>() << std::endl;
```

Again, OpenCL C++ Wrapper writes simply and clearly code. We recommend to use it to replace with original C style API.
