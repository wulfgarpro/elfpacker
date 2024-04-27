cc_library(
    name = "errors",
    hdrs = ["errors.h"],
    visibility = ["//visibility:private"],
)

cc_library(
    name = "cli",
    hdrs = ["cli.h"],
    srcs = ["cli.c"],
    visibility = ["//visibility:private"],
)

cc_binary(
    name = "elfpacker",
    srcs = ["main.c"],
    deps = [":errors", ":cli"],
    copts = ["-Wall", "-Wextra", "-Werror"],
    visibility = ["//visibility:public"],
)

