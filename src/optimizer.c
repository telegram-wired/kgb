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

#include <stdio.h>

unsigned char map[] = {
    0x7f, 0x45 ,0x4c, 0x46, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    2, 0, 3, 0, 0x20, 0, 1, 0, 0x20, 0, 1, 0, 4, 0, 0, 0,
    0xb3, 0, 0x31, 0xc0, 0x40, 0xcd, 0x80, 0, 0x34, 0, 0x20, 0, 1
};

int 
main(int argc, char *argv[])
{
    if (argc < 1) {
        fprintf(stderr, "error: missing argument.\n"
            "usage: kgb-optimize executable");
        return 1;
    }
    FILE *file = fopen(argv[1], "w");
    fwrite(map, sizeof(map), 1, file);
    fclose(file);
}
