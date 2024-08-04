/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <FreeImage.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <vector>

#define MAX_IMAGE 3

const char* IMG_F19_G = "/home/ped-5391/Documentos/cpp_learn/image_channels/data/f19_2_gray.jpeg";
const char* IMG_F18_G = "/home/ped-5391/Documentos/cpp_learn/image_channels/data/f18_gray.jpeg";
const char* IMG_F19_RGB = "/home/ped-5391/Documentos/cpp_learn/image_channels/data/f19_2_rgb.jpeg";

class OpencvImage {
private:
    std::vector<cv::Mat> imgs;
    uint8_t img_numbers;
    bool isGrayScale(const cv::Mat& image);
public:
    OpencvImage(const std::vector<std::string>& imagePaths);
    ~OpencvImage();
    void OpencvImageGetInfo();
};

OpencvImage::OpencvImage(const std::vector<std::string>& imagePaths) : img_numbers(imagePaths.size()) {
    for (const auto& path : imagePaths) {
        cv::Mat img = cv::imread(path);
        if (img.empty()) {
            std::cerr << "Erro ao carregar a imagem: " << path << std::endl;
            continue;
        }
        imgs.push_back(img);
    }
}

OpencvImage::~OpencvImage() {}

bool OpencvImage::isGrayScale(const cv::Mat& image) {
    if (image.channels() == 1) {
        return true;
    }

    if (image.channels() == 3) {
        for (int y = 0; y < image.rows; y++) {
            for (int x = 0; x < image.cols; x++) {
                cv::Vec3b pixel = image.at<cv::Vec3b>(y, x);
                if (pixel[0] != pixel[1] || pixel[1] != pixel[2]) {
                    return false;
                }
            }
        }
        return true;
    }

    return false;
}

void OpencvImage::OpencvImageGetInfo() {
    for (const auto& img : imgs) 
    {
        std::cout << "Informações da imagem:" << std::endl;
        if (isGrayScale(img)) {
            std::cout << "A imagem é em preto e branco." << std::endl;
        } else {
            std::cout << "A imagem é colorida." << std::endl;
        }
        std::cout << "" << std::endl;
    }
}

uint8_t free_image_get_info(const std::string& img) {
    if (img.empty()) {
        return -1;
    }

    FreeImage_Initialise();

    std::string color_type;
    FREE_IMAGE_FORMAT formato = FreeImage_GetFileType(img.c_str(), 0);
    if (formato == FIF_UNKNOWN) {
        std::cerr << " --> Formato de imagem desconhecido <--" << std::endl;
        return 1;
    }

    FIBITMAP* imagem = FreeImage_Load(formato, img.c_str());
    if (!imagem) {
        std::cerr << " --> Erro ao carregar a imagem <-- " << std::endl;
        return 1;
    }

    int largura = FreeImage_GetWidth(imagem);
    int altura = FreeImage_GetHeight(imagem);
    int bpp = FreeImage_GetBPP(imagem);

    if (bpp == 8) {
        color_type = "preto e branco!!";
    } else if (bpp == 24) {
        color_type = "colorida!!";
    }

    std::cout << "########################## Método FreeImage ##########################" << std::endl;
    std::cout << "Informações da imagem:" << std::endl;
    std::cout << "Nome do arquivo: " << img << std::endl;
    std::cout << "Formato: " << FreeImage_GetFormatFromFIF(formato) << std::endl;
    std::cout << "Largura: " << largura << " pixels" << std::endl;
    std::cout << "Altura: " << altura << " pixels" << std::endl;
    std::cout << "Bits por pixel (BPP): " << bpp << std::endl;
    std::cout << "A imagem é " << color_type << std::endl;
    std::cout << "" << std::endl;

    FreeImage_Unload(imagem);
    FreeImage_DeInitialise();

    return 0;
}

int displayMenu() {
    int choice;
    std::cout << "Escolha a opção desejada:" << std::endl;
    std::cout << "1. Processar imagens com FreeImage" << std::endl;
    std::cout << "2. Processar imagens com OpenCV" << std::endl;
    std::cout << "3. Processar imagens com ambos" << std::endl;
    std::cout << "4. Sair" << std::endl;
    std::cout << "Sua escolha: ";
    std::cin >> choice;
    return choice;
}

int main() {
    int choice = displayMenu();
    if (choice == 4) {
        return 0;
    }
    std::vector<std::string> imagePaths = {IMG_F19_G, IMG_F18_G, IMG_F19_RGB};

    switch (choice) {
        case 1:
            for (const auto& path : imagePaths) 
            {
                free_image_get_info(path);
            }
            break;
        case 2: 
        {
            std::cout << "########################## Método Opencv ##########################" << std::endl;
            std::cout << "######################### Para as imagens #########################" << std::endl;
            for (const auto& path : imagePaths) 
            {
                std::cout << path << std::endl;
            }
            OpencvImage opencvImage(imagePaths);
            opencvImage.OpencvImageGetInfo();
            break;
        }
        case 3:
            for (const auto& path : imagePaths) 
            {
                free_image_get_info(path);
            }
            std::cout << "------------------------------------------------------" << std::endl;
            std::cout << "########################## Método Opencv ##########################" << std::endl;
            std::cout << "######################### Para as imagens #########################" << std::endl;
            for (const auto& path : imagePaths) 
            {
                std::cout << path << std::endl;
            }
            {
                OpencvImage opencvImage(imagePaths);
                opencvImage.OpencvImageGetInfo();
            }
            break;
        default:
            std::cout << "Escolha inválida. Tente novamente." << std::endl;
    }

    return 0;
}
