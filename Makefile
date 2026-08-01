.PHONY: all debug release coverage run test clean rebuild format \
        check-format tidy install ci

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

coverage:
	cmake --preset coverage
	cmake --build --preset coverage

	ctest \
		--test-dir build/coverage \
		--output-on-failure \
		--progress

	gcovr \
		--root . \
		--exclude tests \
		--exclude build \
		--html-details coverage.html \
		--xml coverage.xml

run:
	./build/debug/CppTemplateApp

test:
	ctest \
		--test-dir build/debug \
		--output-on-failure \
		--progress

format:
	clang-format -i $(SOURCES)

check-format:
	clang-format --dry-run --Werror $(SOURCES)

tidy:
	clang-tidy \
		-header-filter="^$(PWD)/(include|src)" \
		-p build/debug \
		$(CPP_SOURCES)

install:
	cmake --install build/debug

clean:
	rm -rf build

rebuild: clean debug

ci: debug check-format tidy test