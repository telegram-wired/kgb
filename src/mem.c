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

#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
#include "kgb.h"

void *
malloc(size_t size)
{
    static void* (*_malloc)(size_t);
    if (!_malloc) {
        _malloc = dlsym(RTLD_NEXT, "malloc");
        if (!_malloc)
            die("error: can't find 'malloc' symbol in executable file.");
    }
    void *p = _malloc(size);
    fprintf(stderr, "memory leak at %lx, size %lu.\n", (size_t)p, size);
    return p;
}

void
free(void* mem)
{
    static void (*_free)(void*);
    if (!_free) {
        _free = dlsym(RTLD_NEXT, "free");
        if (!_free)
            die("error: can't find 'free' symbol in executable file.");
    }
    _free(mem);
    fprintf(stderr, "fixed leak at %lx.\n", (size_t)mem);
}

