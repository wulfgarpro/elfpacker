#!/usr/bin/env bash

set -eo pipefail

log() {
  echo "$(date '+%Y-%m-%d %H:%M:%S') - $1"
}

usage() {
  echo "Usage: $0 {build-debug|build-release|run-debug|run-release|clean|debug-gdb}"
  exit 1
}

if [ "$#" -eq 0 ]; then
  usage
fi

case $1 in
  build-debug)
    log "Building the project in debug mode..."
    bazel build //src:elfpacker --config=debug
    ;;
  build-release)
    log "Building the project in release mode..."
    bazel build //src:elfpacker --config=release
    ;;
  run-debug)
    log "Running the project in debug mode..."
    bazel run //src:elfpacker --config=debug -- "$@"
    ;;
  run-release)
    log "Running the project in release mode..."
    bazel run //src:elfpacker --config=release -- "$@"
    ;;
  clean)
    log "Cleaning build artifacts..."
    bazel clean
    ;;
  debug-gdb)
    log "Launching GDB to debug the project..."
    bazel build //src:elfpacker --config=debug
    gdb --args bazel-bin/src/elfpacker "$@"
    ;;
  *)
    usage
    ;;
esac
