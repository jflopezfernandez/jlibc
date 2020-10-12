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

#include <check.h>
#include <jlibc.h>

/**
 * Ensure that the value returned by the call to the memory
 * allocation function points to a valid memory block.
 *
 */
START_TEST(test_allocation_returns_valid_pointer)
{
    char* test_string = allocate_memory_block(strlen("Hello, world!") + 1);
    ck_assert_ptr_nonnull(test_string);
    free(test_string);
}

/**
 * Memory Module Test Suite
 *
 */
Suite* memory_test_suite(void) {
    TCase* test_case_allocation_returns_valid_pointer = tcase_create("Allocation returns valid pointer");
    tcase_add_test(test_case_allocation_returns_valid_pointer, test_allocation_returns_valid_pointer);

    /**
     * Create the memory module test suite and initialize it
     * by adding all of the test cases defined above to it.
     *
     */
    Suite* test_suite = suite_create("Memory Module Test Suite");
    suite_add_tcase(test_suite, test_case_allocation_returns_valid_pointer);

    /**
     * Return the initialized test suite for execution by
     * the primary test runner.
     *
     */
    return test_suite;
}
