/**
 * jlibc - C Standard Library and Utilities
 * Copyright (C) 2020 Jose Fernando Lopez Fernandez
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef PROJECT_INCLUDES_JLIBC_H
#define PROJECT_INCLUDES_JLIBC_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifndef JLIBC_INTERNAL
    #ifndef JLIBC_API
    #define JLIBC_API __attribute__((visibility ("default")))
    #endif
#else
    #ifndef JLIBC_API
    #define JLIBC_API
    #endif
#endif /** JLIBC_INTERNAL */

#include <jlibc/memory.h>

#endif /** PROJECT_INCLUDES_JLIBC_H */
