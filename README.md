### Programa simples que renderiza uma nave na tela. ###

O jogador pode controlar a nave com os botões:
[W] Cima
[S] Baixo
[A] Esquerda
[D] Direita

Para modificar o tamanho da janela é só modificar o arquivo:
"Project_Maverick\src\lib\game.h"

Linha de código:
mWindow(sf::VideoMode(valor do tamanho do eixo x, valor do tamanho do eixo y), "Nome que o usuário desejar vai ser inserido no topo da janela");

Exemplo:
mWindow(sf::VideoMode(1880, 1240), "SFML Space Shooter");

Para modificar a velocidade que a nave se movimenta na tela:
mPlayerSpeed(velocidade que desejar.f)

Exemplo:
mPlayerSpeed(220.f);


