#!/usr/bin/env bash

set -eo pipefail

case $1 in
build)
  bazel build //src:main
  ;;
run)
  bazel run //src:main
  ;;
test)
  bazel test //tests:main
  ;;
clean)
  bazel clean
  ;;
*)
  echo "Usage: $0 {build|run|test|clean}"
  exit 1
  ;;
esac
