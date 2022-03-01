# serac_build_example
a dummy project showing how to use cmake to build/consume mixed C++/CUDA libraries with separable compilation

# building and running (with and without CUDA enabled)

```bash
serac_build_example$ mkdir build && cd build                                     
serac_build_example/build$ cmake ..                                                 
-- The CXX compiler identification is GNU 9.3.0                                     
-- Detecting CXX compiler ABI info                                                  
-- Detecting CXX compiler ABI info - done                                           
-- Check for working CXX compiler: /usr/bin/c++ - skipped                           
-- Detecting CXX compile features                                                   
-- Detecting CXX compile features - done                                            
-- Configuring done                                                                 
-- Generating done                                                                  
-- Build files have been written to: serac_build_example/build                      
serac_build_example/build$ make                                                     
[ 16%] Building CXX object axom/CMakeFiles/axom.dir/core.cpp.o                      
[ 33%] Linking CXX static library libaxom.a                                         
[ 33%] Built target axom                                                            
[ 50%] Building CXX object CMakeFiles/serac.dir/main.cpp.o                          
[ 66%] Linking CXX executable serac                                                 
[ 66%] Built target serac                                                           
[ 83%] Building CXX object axom/CMakeFiles/host_main.dir/main.cpp.o                 
[100%] Linking CXX executable host_main                                             
[100%] Built target host_main                                                       
serac_build_example/build$ ./serac                                                  
running some calculation on host                                                    
serac_build_example/build$ cmake .. -DENABLE_CUDA=TRUE                              
-- The CUDA compiler identification is NVIDIA 11.4.120                              
-- Detecting CUDA compiler ABI info                                                 
-- Detecting CUDA compiler ABI info - done                                          
-- Check for working CUDA compiler: /usr/local/cuda/bin/nvcc - skipped              
-- Detecting CUDA compile features                                                  
-- Detecting CUDA compile features - done                                           
-- Configuring done                                                                 
-- Generating done                                                                  
-- Build files have been written to: serac_build_example/build                      
serac_build_example/build$ make                                                     
Consolidate compiler generated dependencies of target axom                          
[  9%] Building CXX object axom/CMakeFiles/axom.dir/core.cpp.o                      
[ 18%] Building CUDA object axom/CMakeFiles/axom.dir/core.cu.o                      
[ 27%] Linking CXX static library libaxom.a                                         
[ 27%] Built target axom                                                            
[ 36%] Building CUDA object CMakeFiles/serac_cuda.dir/main.cu.o                     
[ 45%] Linking CXX executable serac_cuda                                            
[ 45%] Built target serac_cuda                                                      
Consolidate compiler generated dependencies of target serac                         
[ 54%] Linking CXX executable serac                                                 
[ 63%] Built target serac                                                           
Consolidate compiler generated dependencies of target host_main                     
[ 72%] Linking CXX executable host_main                                             
[ 81%] Built target host_main                                                       
[ 90%] Building CUDA object axom/CMakeFiles/device_main.dir/main.cu.o               
[100%] Linking CXX executable device_main                                           
[100%] Built target device_main                                                     
serac_build_example/build$ ./serac                                                  
running some calculation on host                                                    
serac_build_example/build$ ./serac_cuda                                             
running calculation on device
```
