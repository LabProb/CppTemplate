.PHONY: \
	all \
	debug \
	release \
	coverage \
	sanitize \
	run \
	test \
	format \
	check-format \
	tidy \
	install \
	clean \
	rebuild \
	ci

SOURCES := $(shell find src include tests examples \
	\( -name "*.cpp" -o -name "*.hpp" \))

CPP_SOURCES := $(shell find src tests -name "*.cpp")

all: debug

# ----------------------------------------------------------
# Build
# ----------------------------------------------------------

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
		--exclude "src/main.cpp" \
		--html-details coverage.html \
		--xml coverage.xml

sanitize:
	cmake --preset sanitize
	cmake --build --preset sanitize --clean-first

	ctest \
		--test-dir build/sanitize \
		--output-on-failure \
		--progress

# ----------------------------------------------------------
# Run
# ----------------------------------------------------------

run:
	./build/debug/CppTemplateApp

test:
	ctest \
		--test-dir build/debug \
		--output-on-failure \
		--progress

# ----------------------------------------------------------
# Static analysis
# ----------------------------------------------------------

format:
	clang-format -i $(SOURCES)

check-format:
	clang-format --dry-run --Werror $(SOURCES)

tidy:
	cmake --build build/debug --target tidy

# ----------------------------------------------------------
# Install
# ----------------------------------------------------------

install:
	cmake --install build/debug

# ----------------------------------------------------------
# Utilities
# ----------------------------------------------------------

clean:
	rm -rf build

rebuild: clean debug

ci: debug check-format tidy test