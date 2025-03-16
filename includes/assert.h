/*
   assert.h -- Hyperdrive's debug assertions.

   Copyright 2025 by Sylvain Nieuwlandt (for Kingdom of Dreams)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#ifndef HD_ASSERT_H
#define HD_ASSERT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
   HD_ASSERT will print a failure message on stdout (with filename, line, and function) and exit
   the program with code 1 if the condition is false.

   If the macro _DEBUG isn't defined, then this macro does nothing (noop operation).
*/
#ifdef _DEBUG
#define HD_ASSERT(cond)                                                                                                     \
   if (false == cond) {                                                                                                     \
      printf("FAILURE : Assertion failed in %s (%s:%d) \n", __func__, __FILE__, __LINE__);                                  \
      exit(1);                                                                                                              \
   }
#else
#define HD_ASSERT(cond) (void)0;
#endif

/**
   HD_ASSERT_OK assert that the given value is equals to 0.
*/
#define HD_ASSERT_OK(value) HD_ASSERT(value == 0)

/**
   HD_ASSERT_NOT_NULL asserts that the given value isn't equals to NULL.
*/
#define HD_ASSERT_NOT_NULL(ptr) HD_ASSERT(ptr != NULL)

#endif