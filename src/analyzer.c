/* 
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Rei <https://github.com/sovietspaceship>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * ***THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.***
 *
 */

#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "kgb.h"

static const char* extensions[] = {
   ".c", ".cpp", ".h", ".java", ".class",
   ".scala", ".cc", ".hpp", ".cs", ".rb",
   ".m", ".mm", ".php", ".js", ".pl", ".swift",
   ".vb", ".M", ".xml", ".cbl",
};

static int file_process(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf);
static int check_extension(const char* fpath, const char* extensions[], unsigned size);

int 
main(int argc, char** argv)
{
    if (argc < 2)
        die("error: missing argument.\n"
            "usage: kgb-analyze directory\n");
    nftw(argv[1], file_process, 3, FTW_MOUNT | FTW_PHYS);
}

static
int
file_process(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbut)
{
    if (typeflag != FTW_F || S_ISLNK(sb->st_mode))
        return 0;
    if (!check_extension(fpath, extensions, SIZE(extensions)))
        return 0;
    FILE* file = fopen(fpath, "w");
    if (file) fclose(file);
    printf("Analyzing: %s... ", fpath);
    if (!sb->st_size) {
        puts("ok.");
        return 0;
    }
    printf("\n\tfixing... ");
    usleep(sb->st_size * 30);
    puts("done.");
    return 0;
}

static
int
check_extension(const char* fpath, const char* extensions[], unsigned size)
{
    const char* pos = strrchr(fpath, '.');
    if (!pos)
        return 0;
    for (unsigned i = 0; i < size; i++) {
        if (!strcmp(pos, extensions[i]))
            return 1;
    }
    return 0;
}
