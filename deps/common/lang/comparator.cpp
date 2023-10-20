/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by wangyunlai on 2021/6/11.
//

#include <string.h>
#include <algorithm>
#include "common/defs.h"

namespace common {


int compare_int(void *arg1, void *arg2)
{
  int v1 = *(int *)arg1;
  int v2 = *(int *)arg2;
  return v1 - v2;
}

int compare_float(void *arg1, void *arg2)
{
  float v1 = *(float *)arg1;
  float v2 = *(float *)arg2;
  float cmp = v1 - v2;
  if (cmp > EPSILON) {
    return 1;
  }
  if (cmp < -EPSILON) {
    return -1;
  }
  return 0;
}

int compare_string(void *arg1, int arg1_max_length, void *arg2, int arg2_max_length)
{
  const char *s1 = (const char *)arg1;
  const char *s2 = (const char *)arg2;
  int maxlen = std::min(arg1_max_length, arg2_max_length);
  int result = strncmp(s1, s2, maxlen);
  if (0 != result) {
    return result;
  }

  if (arg1_max_length > maxlen) {
    return s1[maxlen] - 0;
  }

  if (arg2_max_length > maxlen) {
    return 0 - s2[maxlen];
  }
  return 0;
}

bool compare_match(const char* pattern, const char* text) {
    if (*pattern == '\0' && *text == '\0') {
        return true; // Both strings are empty, match successful.
    }

    if (*pattern == '%' && *(pattern + 1) == '\0') {
        return true; // Pattern ends with '%', match successful.
    }

    if (*pattern == '%' && *(pattern + 1) != '\0') {
        // If the pattern has a '%' and it's not the last character, we need to find a match.
        while (*text != '\0') {
            if (common::compare_match(pattern + 1, text)) {
                return true; // Match found.
            }
            text++;
        }
        return false; // No match found.
    }

    if (*pattern == *text || *pattern == '_') {
        // If characters match or pattern is '_', move to the next characters.
        return common::compare_match(pattern + 1, text + 1);
    }

    return false; // No match.
}

int compare_string_like(const char *text, const char *pattern)
{
  return common::compare_match(pattern, text);
}

} // namespace common
