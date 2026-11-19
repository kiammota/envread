# envread

**A minimal C library for reading `.env` files.**

`envread` is a lightweight library designed to load environment variables from `.env` files and retrieve their values through a simple API.

## API

```c
FILE* envread_init(const char* path);
char* envread(const char* key);
void envread_close(void);
```

## Features

- Minimal API
- Lightweight implementation
- No external dependencies
- Written in C

## Usage

```c
#include "envread.h"

int main(void)
{
    envread_init(".env");

    char* port = envread("PORT");

    envread_close();
    return 0;
}
```
