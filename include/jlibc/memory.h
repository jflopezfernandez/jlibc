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

#ifndef PROJECT_INCLUDES_JLIBC_MEMORY_H
#define PROJECT_INCLUDES_JLIBC_MEMORY_H

/**
 * Avoid needlessly looking for and opening the main library
 * header if it has already been included.
 *
 */
#ifndef PROJECT_INCLUDES_JLIBC_H
#include <jlibc/jlibc.h>
#endif

/**
 * This function is meant to replace direct calls to malloc,
 * performing the necessary error-checking on the return
 * value from the memory-allocation function, which at the
 * moment is malloc(3).
 *
 */
JLIBC_API void* allocate_memory_block(size_t size);

#endif /** PROJECT_INCLUDES_JLIBC_MEMORY_H */
