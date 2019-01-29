cmake_minimum_required (VERSION 3.0)
project(Geant4) 

# include file
include(${Geant4_USE_FILE})

# Locate sources and headers for this project
include_directories(${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_INCLUDE_DIR})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include(/*.hh))


add_executable(Demo test.cc ${sources} ${headers})
target_link_libraries(Demo ${Geant4_LIBRARIES} ${AIDA_LIBRARIES})