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

#include <stdio.h>

#include "fileio.h"
#include "gemtext.h"

int main(int argc, char *argv[]) {
    if (argc == 2){
        FILE *mdFile = openMarkdownFile(argv[1]);
        if (mdFile) {
            mdToGemtext(argv[1]);
        }
    }
    else if (argc > 2){
        printf("Too many arguments!\n");
    }
    else {
        printf("Please provide the filename!\nUsage: ./md2gemtext troll.md\n");
    }
 
    return 0;
}
