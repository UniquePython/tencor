#ifndef TENCOR_ATTRIBUTES_H_
#define TENCOR_ATTRIBUTES_H_

#if !defined(__GNUC__) || !(defined(__linux__) || defined(__APPLE__))
#error "tencor currently supports only GCC or Clang on Linux and macOS"
#endif

// clang-format off
#define TENCOR_API             __attribute__((visibility("default")))
#define TENCOR_NODISCARD       __attribute__((warn_unused_result))
#define TENCOR_RETURNS_NONNULL __attribute__((returns_nonnull))
#define TENCOR_MALLOC          __attribute__((malloc))
#define TENCOR_ALLOC_SIZE(n)   __attribute__((alloc_size(n)))
#define TENCOR_ALLOC_ALIGN(n)  __attribute__((alloc_align(n)))
// clang-format on

#endif // TENCOR_ATTRIBUTES_H_
