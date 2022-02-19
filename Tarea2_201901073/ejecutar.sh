#!/bin/bash
flex --header-file=scanner.h -o scanner.cpp lexer.l
bison -o parser.cpp --defines=parser.h sintactico.y