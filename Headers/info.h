/*
*  Copyright (c) 2026, littlefly365
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1. Redistributions of source code must retain the above copyright notice, this
*     list of conditions and the following disclaimer.
*
*  2. Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3. Neither the name of the copyright holder nor the names of its
*     contributors may be used to endorse or promote products derived from
*     this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
*  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
*  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
*  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
*  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*  (BSD 3-Clause License)
*/

#ifndef _INFO_H
#define _INFO_H	1

#define PROG_VERSION	"1.0.0"
#define SYSTEM_VERSION "1.0.0"
#define PROJECT_VERSION "26.5"
#define AUTHOR "littlefly365"

#if defined(USERLAND_ARCH)
#undef USERLAND_ARCH
#endif

#if defined(__x86_64__)
#define USERLAND_ARCH "x86_64"
#elif defined(__i386__)
#define USERLAND_ARCH "i386"
#elif defined(__aarch64__)
#define USERLAND_ARCH "aarch64"
#elif defined(__arm__)
#define USERLAND_ARCH "armv7l"
#elif defined(__riscv) && (__riscv_xlen == 64)
#define USERLAND_ARCH "riscv64"
#elif defined(__ppc64__) && defined(__LITTLE_ENDIAN__)
#define USERLAND_ARCH "ppc64le"
#elif defined(__s390x__)
#define USERLAND_ARCH "s390x"
#elif defined(__loongarch64)
#define USERLAND_ARCH "loongarch64"
#elif defined(__mips64)
#define USERLAND_ARCH "mips64"
#elif defined(__sparc__) && (defined(__arch64__) || defined(__sparcv9))
#define USERLAND_ARCH "sparc64"
#else
#define USERLAND_ARCH "unknown"
#endif

#if defined(__linux__)
#define OS_NAME "GNU/Linux"
#else
#define OS_NAME u.sysname
#endif

#endif
