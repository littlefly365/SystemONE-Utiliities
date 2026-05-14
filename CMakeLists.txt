cmake_minimum_required(VERSION 3.10)

project(SystemONE-Utilities VERSION 1.0.0 LANGUAGES C)

include_directories(${CMAKE_SOURCE_DIR}/Headers)

set(COREUTILS
	arch 
	basename
	cat
	chroot
	dirname 
	domainname 
	echo 
	factor
	false 
	hostid 
	hostname 
	link
	nproc 
	pwd 
	readlink
	realpath
	rmdir
	seq
	sleep 
	true 
	tty
	uname 
	unlink
	whoami
	yes
)

set(CUSTOM
	prime
	ldd
	SystemONE-version	
)

foreach(prog IN LISTS COREUTILS)
	add_executable(${prog} Source/Coreutils/${prog}/${prog}.c)
endforeach()

foreach(prog IN LISTS CUSTOM)
	add_executable(${prog} Source/Custom/${prog}/${prog}.c)
endforeach()
