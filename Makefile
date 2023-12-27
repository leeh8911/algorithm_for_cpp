PROJECT_NAME = $(notdir $(CURDIR))
release = release
debug = "debug"

ifeq ($(config), release) 
	config = Release
else
	config = Debug
endif

.PHONY: format
format:
	clang-format src/**/*.cpp src/**/*.h test/**/*.cpp -i

.PHONY: build
build:
	mkdir build || echo "already exist build" &&\
	cd build && \
	cmake -DCMAKE_BUILD_TYPE=$(config) .. && \
	cmake --build .

.PHONY: run-test
run-test:
	cd build && \
	test\$(config)\$(PROJECT_NAME)_test.exe

.PHONY: test
test: build run-test