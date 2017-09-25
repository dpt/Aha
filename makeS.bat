@rem Makes assembly language files for the Aha! program.
@if .%1 == . goto error1
@if not exist %1.h goto error2
g++ -S -g -O2 -DINC='"%1.h"' -DOFILE='"%1.out"' -Wall -s aha.c
@goto exit
:error1
@echo Need one argument, the name of the .h file.
@goto exit
:error2
@echo File %1.h does not exist.
:exit
