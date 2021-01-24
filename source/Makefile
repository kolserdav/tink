GET_ENV = $(shell grep $(1)  ../node/.env | sed -e 's/$(1)=//g' | sed -e 's/#.*//g')
EXE = $(call GET_ENV,TARGET_EXECUTE)
RAW = $(call GET_ENV,BASE_EXECUTE)
ROOT_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))

TARGET_BUILD = ${ROOT_DIR}usr/target/build
BASE_BUILD = ${ROOT_DIR}usr/base/build

TARGET_CLEAN = cd ${TARGET_BUILD} && rm -rf ./*
BASE_CLEAN = cd ${BASE_BUILD} && rm -rf ./*

all:
	echo ${foo} && \
	mkdir -p ${TARGET_BUILD} && ${TARGET_CLEAN} && cmake -DEXECUTE:STRING=${EXE} .. && cmake --build ./ && \
	mkdir -p ${BASE_BUILD} && ${BASE_CLEAN} && cmake -DEXECUTE:STRING=${RAW} .. && cmake --build ./
t:
	mkdir -p ${TARGET_BUILD} && ${TARGET_CLEAN} && cmake .. && cmake --build ./ 
b:
	mkdir -p ${BASE_BUILD} && ${BASE_CLEAN} && cmake .. && cmake --build ./
run-t:
	@${TARGET_BUILD}/${EXE}
dev-t:
	NODE_ENV=development ${TARGET_BUILD}/${EXE}
run-b:
	@${BASE_BUILD}/${RAW}
test:
	make run-b && make run-t
install:
	cd ${TARGET_BUILD} && make install
	cd ${BASE_BUILD} && make install
clean:
	${TARGET_CLEAN} && ${BASE_CLEAN} 
