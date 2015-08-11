CC=g++ --std=c++0x
OBJ_DIR=obj
SRC_DIR=src

all:main

${OBJ_DIR}/tinyxml2.o:${SRC_DIR}/tinyxml2.cpp ${SRC_DIR}/tinyxml2.h
	$(CC) -o $@ -c $<

${OBJ_DIR}/config.o:${SRC_DIR}/config.cc ${SRC_DIR}/config.hh
	$(CC) -o $@ -c $<

main:${SRC_DIR}/main.cc ${OBJ_DIR}/config.o ${OBJ_DIR}/tinyxml2.o
	$(CC) -o $@ $^

