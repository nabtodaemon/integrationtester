cmake_minimum_required(VERSION 2.8)

set(UNABTO_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)

include(${UNABTO_ROOT}/build/cmake/unabto_files.cmake)

set(src
  ${unabto_core_src}
  ${unabto_module_crypto_generic_src}
  ${unabto_module_log_unix_src}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_main.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_network_adapter_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_dns_adapter_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_log_adapter_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_random_adapter_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_time_adapter_test.c

  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_aes_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_aes_cbc_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_sha256_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_hmac_sha256_test.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/unabto_aes128_sha256_test.c

)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${UNABTO_ROOT}/src/
)

#add_definitions(-g)

link_libraries(pthread)

add_executable(integrationtester ${src})
