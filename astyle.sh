#!/usr/bin/env bash

# Author: takuzoo3868
# Last Modified: 8 Jul 2018.

# NEED: $brew install astyle

astyle --style=google --mode=c --suffix=none -s4 -S -N -Y -M80 -p -j -k1 -U -H main.cpp