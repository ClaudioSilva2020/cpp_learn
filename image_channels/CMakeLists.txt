cmake_minimum_required(VERSION 3.27)

project(
    image_channels
    VERSION 1.0.0
    LANGUAGES C CXX
)

# Adicionar diretório de inclusão da FreeImage
include_directories(/usr/include)

# Encontrar o pacote FreeImage
find_library(FREEIMAGE_LIB NAMES freeimage PATHS /usr/lib/x86_64-linux-gnu /usr/local/lib)
find_path(FREEIMAGE_INCLUDE_DIR NAMES FreeImage.h PATHS /usr/include)

# Verificar se FreeImage foi encontrado
if (FREEIMAGE_LIB AND FREEIMAGE_INCLUDE_DIR)
    message(STATUS "FreeImage encontrado: ${FREEIMAGE_LIB}")
else()
    message(FATAL_ERROR "Não foi possível encontrar a biblioteca FreeImage. Verifique a instalação.")
endif()

# Encontrar o pacote OpenCV
find_package(OpenCV REQUIRED)

# Adicionar o executável detect_image_type
add_executable(detect_image_type main.cpp)

# Linkar a biblioteca FreeImage
target_link_libraries(detect_image_type ${FREEIMAGE_LIB})

# Linkar a biblioteca OpenCV
target_link_libraries(detect_image_type ${OpenCV_LIBS})

# Incluir diretório de cabeçalhos do FreeImage
target_include_directories(detect_image_type PRIVATE ${FREEIMAGE_INCLUDE_DIR})
