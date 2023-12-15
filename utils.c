// bunkermatty's utils.c
// Copyright (C) 2023 bunkermatty

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <stdio.h>
#include <string.h>

#include "utils.h"

void replaceSubstring(char *source, const char *search, const char *replace) {
    // Find the thing your looking for (search) from the source
    char *found = strstr(source, search);

    while (found){
        // Figure out the length of the tail (which is everything after the substring)
        size_t tailLength = strlen(found + strlen(search));

        // Move the tail out of the way to make room for the replacement (replace)
        memmove(found + strlen(replace), found + strlen(search), tailLength + 1);

        // Copy the replacement (replace) with the substring found (search)
        memcpy(found, replace, strlen(replace));

        // Find the next occurence of search
        found = strstr(found + strlen(replace), search);
    }
}
