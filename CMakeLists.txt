# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(modDBSCAN)

# Specify the source files for your algorithm (header-only library)
add_library(ModDbscanCluster INTERFACE)

# Make sure that the headers are available
target_include_directories(ModDbscanCluster INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Install headers to the correct directory
install(FILES ModDbscanCluster.h ModDbscanCluster_Factory.h DESTINATION include/modDBSCAN)

# If necessary, link dependencies (only if needed, adjust accordingly)
# target_link_libraries(ModDbscanCluster INTERFACE ${GAUDI_LIBRARIES} ${JUGGLER_LIBRARIES})