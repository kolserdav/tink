ROOT_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
TARGET_BUILD=${ROOT_DIR}usr/target/build
BASE_BUILD=${ROOT_DIR}usr/base/build
TARGET_CLEAN=cd ${TARGET_BUILD} && rm -rf ./*
BASE_CLEAN=cd ${BASE_BUILD} && rm -rf ./* 
all:
	mkdir -p ${TARGET_BUILD} && ${TARGET_CLEAN} && cmake .. && cmake --build ./ && \
	mkdir -p ${BASE_BUILD} && ${BASE_CLEAN} && cmake .. && cmake --build ./
t:
	mkdir -p ${TARGET_BUILD} && ${TARGET_CLEAN} && cmake .. && cmake --build ./ 
b:
	mkdir -p ${BASE_BUILD} && ${BASE_CLEAN} && cmake .. && cmake --build ./
run-t:
	@${TARGET_BUILD}/request1
run-b:
	@${BASE_BUILD}/response
test:
	make run-b && make run-t
install:
	cd ${TARGET_BUILD} && make install
	cd ${BASE_BUILD} && make install
clean:
	${TARGET_CLEAN} && ${BASE_CLEAN} 
