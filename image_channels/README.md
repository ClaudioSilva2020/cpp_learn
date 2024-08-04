# Testes com técnicas de imagens para obter tipo de canais

## Método FreeImage
* Método utilizado que obtem a profundidade dos bits por pixels de uma imagem
e devolve valores como 8 ou 24 onde 8 representa o bits por pixel o que significa 
que a imagem é GRAY_SCALE.

## Método Opencv
* Método que utiliza a lib do opencv para obter a quantidade de canais de uma imagem.
Se a imagem possui 8 canais, a mesma é GRAY_SCALE. Pórem se possui 24 canais, pode ser
COLORIDA, portanto, dependendo do valor da diferença entre cada canal pode ser considerada
como GRAY_SCALE também.
* O que esse programa de teste com o OPENCV faz é justamente realizar esse calculo para obter 
a o tipo de imagem se é COLODIRA ou PRETO e BRANCO.