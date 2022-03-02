if (WIN32)
    cmake_minimum_required(VERSION 3.12)
elseif (APPLE)
    cmake_minimum_required(VERSION 3.17)
elseif (UNIX)
    cmake_minimum_required(VERSION 3.16)
endif ()

project(OcrLibTest)
set(CMAKE_CXX_STANDARD 11)
add_definitions(-DUNICODE -D_UNICODE)

# OpenMP flags for MACOS
if (APPLE)
    if (CMAKE_C_COMPILER_ID MATCHES "Clang")
        set(OpenMP_C "${CMAKE_C_COMPILER}")
        set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp -I/usr/local/opt/libomp/include")
        set(OpenMP_C_LIB_NAMES "omp")
        set(OpenMP_omp_LIBRARY ${OpenMP_C_LIB_NAMES})
    endif ()
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(OpenMP_CXX "${CMAKE_CXX_COMPILER}")
        set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp -I/usr/local/opt/libomp/include")
        set(OpenMP_CXX_LIB_NAMES "omp")
        set(OpenMP_omp_LIBRARY ${OpenMP_C_LIB_NAMES})
    endif ()
    link_directories("/usr/local/opt/libomp/lib")
endif ()
# End Of OpenMP flags for MACOS

# OpenMP
FIND_PACKAGE(OpenMP REQUIRED)
if (OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
    message(${CMAKE_EXE_LINKER_FLAGS})
endif ()
# End Of OpenMP

# OpenCV for include
set(BUILD_SHARED_LIBS false)
include(${CMAKE_CURRENT_SOURCE_DIR}/opencv-static/OpenCVWrapperConfig.cmake)
find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    message(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")
    message(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
else ()
    message(FATAL_ERROR "opencv Not Found!")
endif (OpenCV_FOUND)

# import OcrLib
include(${CMAKE_CURRENT_SOURCE_DIR}/OcrLib/OcrLibWrapper.cmake)
find_package(OcrLib REQUIRED)
if (OcrLib_FOUND)
    message(STATUS "OcrLib_LIBS: ${OcrLib_LIBS}")
    message(STATUS "OcrLib_INCLUDE_DIRS: ${OcrLib_INCLUDE_DIRS}")
else ()
    message(FATAL_ERROR "OcrLib Not Found!")
endif (OcrLib_FOUND)
# End Of Ocr CLib

# Test CLib Program
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(TESTSRC src/maintest.cpp)
add_executable(OcrLibTest ${TESTSRC})
if (UNIX)
    target_link_libraries(OcrLibTest ${OpenMP_CXX_LIB_NAMES} ${OcrLib_LIBS} ${OpenCV_LIBS})
else ()
    include_directories(${OpenCV_INCLUDE_DIRS})
    target_link_libraries(OcrLibTest ${OpenMP_CXX_LIB_NAMES} ${OcrLib_LIBS})
endif ()

# Install exe
install(TARGETS OcrLibTest EXPORT OcrLibTest)

# Install test script
if (WIN32)
    file(GLOB TEST_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/resource/*.bat)
else ()
    file(GLOB TEST_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/resource/*.sh)
endif ()
install(FILES ${TEST_SCRIPT} DESTINATION ${CMAKE_INSTALL_PREFIX})

# Install images dir
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resource/images DESTINATION ${CMAKE_INSTALL_PREFIX})

# Install models dir
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resource/models DESTINATION ${CMAKE_INSTALL_PREFIX})