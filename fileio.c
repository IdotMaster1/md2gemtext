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

#include "fileio.h"
#include <stdio.h>

FILE* openMarkdownFile(const char *filename) {
    FILE *mdFile = fopen(filename, "r");
        if (!mdFile) {
            fprintf(stderr, "Error: Unable to open the Markdown file '%s'\n", filename);
        }
    return mdFile;
}