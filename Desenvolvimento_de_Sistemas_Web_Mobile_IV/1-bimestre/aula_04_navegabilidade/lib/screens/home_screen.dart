import 'package:flutter/material.dart';
import 'package:aula_04_navegabilidade/screens/detail_screen.dart';

class HomeScreen extends StatefulWidget {
  const HomeScreen({super.key});

  @override
  // Substituimos a criação de estados padrao dessa classe
  // Definimos um tipo genérico com o nome dessa classe
  // Adicionamos o construtor de estados privado
  State<HomeScreen> createState() => _HomeScreenState();
}

// Aqui criamos a classe que servirá de estado
// 1. Para que serve a droga do <T>? E por que ele referencia a classe Stateful Widget anterior?
// Comumente garante a preservação de dados com apenas tipos explicitamente configurados
// Serve para o ESTADO saber de qual STATEFULWIDGET ele pertence, assim, previnindo uso de casting
class _HomeScreenState extends State<HomeScreen> {
  int _contadorClique = 0;

  void _incrementarContador() {
    // Notifica ao interior do Flutter que o estado mudou
    setState(() {
      _contadorClique++;
    });
  }

  // 2. Por que existe um build dentro dessa classe estado?
  // Porque se existisse um build dentro do StatefulWidget, o principio de campos IMUTAVEIS entraria em jogo e possivelmente nao existiria forma de atualizar dados
  // Ao definir um build dentro do estado, estamos seguindo a regra do WIDGET ser IMUTAVEL, informando dados constantes no momento da execucao.
  // Ao atualizar o estado, um rebuild é feito com os novos valores.

  // 3. Será que eu preciso usar um build do sistema inteiro dentro do estado ou posso apenas adicionar o que ele deveria exibir
  // Não é boa prática. Pode trazer impacto de performance (app inteiro atualizando ao inves de apenas um ou outro campo). Quebra o principio de isolamento de "interesses" (concerns)
  // Cara, se nao é boa pratica, por que o applicativo inteiro foi feito no build?
  // Parece que foi feito, mas nao é boa prática
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Aula 04, Navegabilidade"),
      ),
      
      // 4. Para que serve o Center e por que ele precisa ser posto no inicio?
      // É um widget facilitador que centraliza o filho no layout principal
      body: Center(
        child: Column(
          // 5. Se existe o Widget Center(), por que alinhamento é importante?
          // Boa pergunta, não sei responder com propriedade.
          // Parece que o Column alinha vários filhos verticalmente e o Center alinha um filho dentro de um espaço delimitado nele mesmo (BOX)
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            const Text(
              "Bem-vindo(a) ao Projeto Integrador!",
              style: TextStyle(
                fontSize: 24,
                fontWeight: FontWeight.bold
              ),
              textAlign: TextAlign.center,
            ),

            const SizedBox(height: 30,),

            const Text(
              "Cliques no botão de navegação:",
              style: TextStyle(fontSize: 18),
            ),
            
            // 6. Por que não posso colocar o contador diretamente no texto igual faz no PHP?
            // O contador é uma variável que atualiza seu valor com o tempo, o texto de label é uma constante e exige que os valores sejam imutáveis e igualmente constantes
            // Escolha do programador, deixou separado para ficar visualmente bonito
            Text(
              '$_contadorClique',
              style: TextStyle(
                fontSize: 48,
                fontWeight: FontWeight.bold
              ),
            ),
            
            const SizedBox(height: 20,),

            ElevatedButton(
              onPressed: () {
                _incrementarContador();

                // 7. Por que usamos Navigator.push ao invés de redirecionamentos normais?
                // No desenvolvimento mobile, é muito comum usar o STACK NAVIGATION, o principio de uso dele é facil: adiciona-se rotas sobre rotas e quando o usuário desejar, basta remover a camada mais ao topo e retornar à rota anterior
                Navigator.push(
                  context,
                  // 8. Por que usamos MaterialPageRoute?
                  // Na verdade, ele é uma função que exibe um "popup" que preenche a tela inteira como um quadro em branco pronto para ser estilizado

                  // 9. Para que serve o Builder?
                  // O builder na verdade pode ser varias coisas dependendo de onde for usado. No entanto, aqui no MaterialPageRoute, o builder sinaliza ao framework para construir um widget que segue algumas definições
                  MaterialPageRoute(
                    builder: (context) => DetailScreen(
                      itemId: 42,
                      itemName: 'Item Secreto',
                      cliquesContador: _contadorClique
                    )
                  )
                );
              },
              child: const Text("Ir para os detalhes do Item"),
            ),

            const SizedBox(height: 20,),

            ElevatedButton(
              onPressed: () {
                // 10. O que é o pushReplacement?
                // É um método do Navigator capaz de colocar uma nova rota na STACK e apagar a rota anterior
                Navigator.pushReplacement(
                  context,
                  MaterialPageRoute(
                    builder: (context) => const HomeScreen()
                  )
                );
              },
              style: ElevatedButton.styleFrom(backgroundColor: Colors.deepPurple),
              child: const Text('Simular Reset/Logout', style: TextStyle(color: Colors.white),),
            ),
          ],
        )
      ),
    );
  }
}