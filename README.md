# Jogo da Moeda com Interface Gráfica (GTK)

Um simples jogo que simula o lançamento de uma moeda e exibe o resultado (cara ou coroa) em uma interface gráfica utilizando GTK em C.

## Instalação

Certifique-se de ter o GTK instalado no seu sistema. No Ubuntu, você pode instalar o GTK com o seguinte comando:

```bash
sudo apt-get install libgtk-3-dev
```

Compile o código usando um compilador C, como `gcc`:

```bash
gcc jogodamoeda.c -o jogodamoeda `pkg-config --cflags --libs gtk+-3.0`
```

## Uso

Execute o programa compilado:

```bash
./jogodamoeda
```

## Tecnologias Utilizadas

- C
- GTK

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para fazer fork do projeto e abrir pull requests.

## Licença

Este projeto está sob a [Licença MIT]