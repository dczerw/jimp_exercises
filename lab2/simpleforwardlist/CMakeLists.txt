
project(forwardlist)

set(HEDEAR_FILES ForwardList.h)
set(SOURCE_FILES ForwardList.cpp)

add_library(libforwardlist STATIC ${SOURCE_FILES})
target_include_directories(libforwardlist PUBLIC .)

add_executable(forwardlist ${SOURCE_FILES} main.cpp)

target_link_libraries(forwardlist libforwardlist)

