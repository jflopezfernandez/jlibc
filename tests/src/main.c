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

#include "memory-test-suite.h"

/**
 * This is the entry point for the jlibc test suite driver.
 *
 * This function handles all of the test suite
 * initialization indirectly, by invoking each module's test
 * suite constructor function.
 *
 * @return Total number of tests failed across all test suites.
 *
 */
int main(void)
{
    /**
     * Initialize the test suite runner by creating a main
     * test suite container to which each library module's
     * test suite will be added.
     *
     */
    Suite* main = suite_create("jlibc Main Test Suite Container");
    SRunner* main_test_suite_runner = srunner_create(main);

    /**
     * Add the library module test suites to the main suite
     * runner container.
     *
     */
    srunner_add_suite(main_test_suite_runner, memory_test_suite());

    /**
     * Run all of the test suites, outputting verbose status
     * information during test suite execution.
     *
     */
    srunner_run_all(main_test_suite_runner, CK_VERBOSE);

    /**
     * Rather than simply returning the value from
     * srunner_ntests_failed(...) as our exit status, we
     * first store this return value in a local variable to
     * be able to free the srunner object prior to our
     * return from main.
     *
     * Doing this make is much easier to use valgrind to
     * pinpoint memory errors and leaks in our test cases,
     * as there are less "false positives" in the output.
     *
     * Otherwise, our process would simply exit without
     * first freeing the heap-allocated srunner object.
     *
     */
    int tests_failed = srunner_ntests_failed(main_test_suite_runner);

    /**
     * Free the srunner object we previously heap-allocated
     * during test suite initialization.
     *
     */
    srunner_free(main_test_suite_runner);

    /**
     * Return the number of failed tests as our return value
     * from main().
     *
     * @note This has the effect of zero failed tests being
     * equal to EXIT_SUCCESS, whereas any non-zero value
     * is interpreted in Unix-like systems as an error
     * indicator.
     *
     */
    return tests_failed;
}
