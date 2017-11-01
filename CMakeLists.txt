cmake_minimum_required(VERSION 2.8)
project(integrationtester C ASM)

set(UNABTO_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)

include(${UNABTO_ROOT}/build/cmake/unabto_files.cmake)

set(UNABTO_CRYPTO_MODULE_OPENSSL_ARMV4 0)
set(UNABTO_CRYPTO_MODULE_GENERIC 0)

set(src ${unabto_core_src})

if (DEFINED UNABTO_CRYPTO_MODULE)
  if (${UNABTO_CRYPTO_MODULE} STREQUAL "openssl_armv4")
    message("Using openssl_arm4 crypto module")
    set(UNABTO_CRYPTO_MODULE_OPENSSL_ARMV4 1)
    set(src ${src} ${unabto_module_crypto_openssl_armv4_src})
  else()
    message("Using generic crypto module")
    set(UNABTO_CRYPTO_MODULE_GENERIC 1)
    set(src ${src} ${unabto_module_crypto_generic_src})
  endif()
else()
  message("Using generic crypto module")
  set(UNABTO_CRYPTO_MODULE_GENERIC 1)
  set(src ${src} ${unabto_module_crypto_generic_src})
endif()

set(src ${src}
  ${unabto_module_log_unix_src}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_aes_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_aes_cbc_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_sha256_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_hmac_sha256_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_aes128_sha256_test.c

  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_dummy_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_time_adapter_test.c

  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_main.c
  )

include_directories(
  ${UNABTO_ROOT}/src 
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  )

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/unabto_integrationtester_config.h.in"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_integrationtester_config.h"
  )

add_definitions(-std=c99 -D_POSIX_C_SOURCE=199309L)

link_libraries(pthread)

add_executable(${PROJECT_NAME} "${src}")

