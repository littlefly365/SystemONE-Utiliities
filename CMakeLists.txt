cmake_minimum_required(VERSION 3.10)

project(NO-Name VERSION 1.0.0 LANGUAGES C)

include_directories(${CMAKE_SOURCE_DIR}/Headers)

set(PROGRAMS arch domainname echo false hostid hostname nproc pwd sleep true uname yes)
foreach(prog IN LISTS PROGRAMS)
	add_executable(${prog} Source/${prog}/${prog}.c)
endforeach()
