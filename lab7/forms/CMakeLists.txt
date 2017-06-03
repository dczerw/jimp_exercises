
project(form)

set(HEDEAR_FILES Form.h)
set(SOURCE_FILES Form.cpp)

add_library(libform STATIC ${SOURCE_FILES})
target_include_directories(libform PUBLIC .)

add_executable(form ${SOURCE_FILES} main.cpp)

target_link_libraries(form libform)
