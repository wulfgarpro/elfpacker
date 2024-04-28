cc_library(
    name = "ep_errors",
    hdrs = ["ep_errors.h"],
    visibility = ["//visibility:private"],
)

cc_library(
    name = "ep_cli",
    hdrs = ["ep_cli.h"],
    srcs = ["ep_cli.c"],
    visibility = ["//visibility:private"],
)

cc_library(
    name = "ep_io",
    hdrs = ["ep_io.h"],
    srcs = ["ep_io.c"],
    deps = [":ep_errors"],
    visibility = ["//visibility:private"],
)

cc_binary(
    name = "elfpacker",
    srcs = ["main.c"],
    deps = [":ep_errors", ":ep_cli", ":ep_io"],
    copts = ["-Wall", "-Wextra", "-Werror"],
    visibility = ["//visibility:public"],
)

