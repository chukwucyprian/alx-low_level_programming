#!/bin/bash
wget -P . https://github.com/chukwucyprian/alx-low_level_programming/raw/master/0x18-dynamic_libraries/_printf.so
export LD_PRELOAD=$PWD/_printf.so
