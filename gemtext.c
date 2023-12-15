// md2gemtext - A markdown to gemtext converter
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

#include <mkdio.h>

#include "gemtext.h"
#include "utils.h"

void mdToGemtext(const char *mdtogem){
    FILE *mdfile = fopen(mdtogem, "r");
    if (mdtogem){
        int lineNumber = 1;
        int size;
        char line[256];
        while (fgets(line, sizeof(line), mdfile) != NULL) {
            // List's
            replaceSubstring(line, "-", "*");
            
            // URL's need some extra work...
            replaceSubstring(line, "[", "=> ");
            replaceSubstring(line, "](", " ");
            replaceSubstring(line, ")", "\n");

            // And so do images
            replaceSubstring(line, "![", "Sorry, but images cannot be added to Gemtext.");


            printf("%s\n", line);
        }

    }
}