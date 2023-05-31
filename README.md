## Aprendendo sobre colisão 2D na prática

<p align="center">
  <img src="assets/me.png" />
</p>

### Um pouco Sobre Mim
 Me chamos Gelson Gomes Rodrigues, e sou desenvolvedor C/C++ a mais de 15 anos, e apaixonado por engines de jogos, buscando sempre aprender nas novas ferramentas, mas sem deixar o parte de programação raiz que o C/C++ sempre exigiu.
 Atualmente trabalhando com sistemas distribuidos e desenvendo arquitetura de novos produtos.

### Objetivo do Curso

Aprender a modelar os exemplos que sempre permeiaram nossos livros de fisica e matematica, dando uma abordagem mais prática em como construir os exemplos, e não apenas em usar o conceito em um jogo/simulação final.
O gif abaixo demonstra o que iremos encontrar no decorrer desse curso que será fragmentado em várias partes, mas sempre com progressão.
Nesse gif, ao invés de apensar visualizarmos os exemplos, iremos construi-los, ou seja, vamos modelar e implementar uma seta com com direção, criar um botão usando um retangulo, etc....
<p align="center">
  <img src="assets/sat_examples.gif" /> 
</p>


O proximo gif, já demonstra os conceitos aplicados na box2d lite, uma versão simplificada da engine box2D, mas com coneitos avançados para muitos desenvolvedores.

<p align="center">
  <img src="assets/box2lite.gif" /> 
</p>

### Tecnologias utilizadas:


  - ``C++17``
  - ``Cmake 3.20``
  - ``Vscode 1.78.2 (Com tasks e launch.js)``
  - ``Apple clang version 14.0.3 (clang-1403.0.22.14.1)``
  - ``GoogleTest(https://github.com/google/googletest)``
  - ``Render (Glew,Glad,ImgGui)``
  - ``Html5 com javascript Vanilla(mesmo código de C++ porém aplicado em um canvas)``

### Estrutura do projeto

```
├── cpp_project
    ├── libGelEngine (Lib responsavel por toda a parte da fisica e matematica aplicada)
        └── src
        └── test
    ├── libGelRenderIO ( Criação de um render generico, podendo adicionar outros frameworks, como Sdl2, glut...)
        └── src
        └── test
    ├── projGelCollision2D ( Executavel contendo toda a lógica para Colisão 2D)
        └── src
          └── main.cpp
        └── test
    ├── README.md
├── html5_project  ( Replica do projeto apenas para exemplificar em outra linguagem)
      ├── libGelEngine 
      ├── libGelRenderIO
      ├── projGelCollision2D
          ├── main.js
    ├──index.html
```

### Padroes do código ultilizado

  - <b>enum</b> - Initialize com <b>E</b>Nome
  - <b>strucut, class,namespace</b> - Segue o padrão <b>P</b>ascal<b>C</b>ase, primeira letra maiuscula.
  - <b>variavel, função, metodo</b> - padrão <b>c</b>amel<b>C</b>ase
  - <b>interface</b> - Initialize com <b>I</b>Nome
  - <b>variavel em javascript</b> - padrão <b>c</b>amel<b>C</b>ase porém adicionar os tipos antes da variavel:
    . string - <b>str</b>Name
    . integer - <b>int</b>Name
    . floag, double - <b>nb</b>Name
    . boolean -  <b>bl</b>Name
    . class - <b>cls</b>Name
    . object - <b>obj</b>Name
   
    

### Refencias(livros, sites e videos):
https://gamesfromwithin.com/when-is-it-ok-not-to-tdd
https://www.metanetsoftware.com/technique/tutorialA.html
https://github.com/erincatto/box2d-lite

 


        



    
     