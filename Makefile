.PHONY: all debug release run test clean rebuild format check-format tidy install

SOURCES := $(shell find src include tests examples \
	\( -name "*.cpp" -o -name "*.hpp" \))

CPP_SOURCES := $(shell find src tests -name "*.cpp")

all: debug

debug:
	cmake --preset debug
	cmake --build --preset debug

release:
	cmake --preset release
	cmake --build --preset release

run:
	./build/debug/CppTemplateApp

test:
	ctest --test-dir build/debug --output-on-failure --progress

format:
	clang-format -i $(SOURCES)

check-format:
	clang-format --dry-run --Werror $(SOURCES)

tidy:
	clang-tidy -p build/debug $(CPP_SOURCES)

install:
	cmake --install build/debug

clean:
	rm -rf build

rebuild: clean debug

ci: debug check-format tidy test