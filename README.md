# gcc-plugin-for-oi

Some GCC plugins useful for OI training/judging.

Currently, only one plugin `no_opt_attr_plugin` is included.

## Build

Simply `make all`.

Or, if you are building the plugins for a gcc copy other than the system
compiler, use `make all TARGET_GCC=/path/to/gcc`.

## Description

* `no_opt_attr_plugin.so`: a plugin to disable
`__attribute__((optimize(...)))` and `#pragma GCC optimize ...`

## Usage

`gcc -fplugin=/path/to/some_plugin.so test.c`

## Acknowledgments

* GCC for providing plugin interface.
* Linux Kernel for providing headers in this repo.
