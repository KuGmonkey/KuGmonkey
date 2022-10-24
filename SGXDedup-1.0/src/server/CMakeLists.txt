#src/server

set(SGX_OPENSSL_LIBRARY_PATH /opt/intel/sgxssl/lib64)
set(SGX_OPENSSL_OBJ sgx_usgxssl)
link_directories(${SGX_OPENSSL_LIBRARY_PATH})

add_library(keyServer STATIC keyServer.cpp)
add_library(dataSR STATIC dataSR.cpp)
add_library(dedupCore STATIC dedupCore.cpp)
add_library(storage STATIC storageCore.cpp)

add_executable(server-sgx ServerMain.cpp)
target_link_libraries(server-sgx ${SERVER_OBJ} ${LINK_OBJ} ${SGX_OPENSSL_OBJ})
