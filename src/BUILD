cc_library(
    name = "errors",
    hdrs = ["errors.h"],
)

cc_library(
    name = "cli",
    hdrs = ["cli.h"],
    srcs = ["cli.c"],
)

cc_binary(
    name = "main",
    srcs = ["main.c"],
    deps = [":errors", ":cli"],
    visibility = ["//visibility:public"],
)

