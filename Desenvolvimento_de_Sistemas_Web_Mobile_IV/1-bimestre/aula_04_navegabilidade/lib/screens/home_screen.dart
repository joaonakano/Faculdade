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
class _HomeScreenState extends State<HomeScreen> {
  int _contadorClique = 0;

  void _incrementarContador() {
    // Notifica ao interior do Flutter que o estado mudou
    setState(() {
      _contadorClique++;
    });
  }

  // 2. Por que existe um build dentro dessa classe estado?
  // 3. Será que eu preciso usar um build do sistema inteiro dentro do estado ou posso apenas adicionar o que ele deveria exibir
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Aula 04, Navegabilidade"),
      ),
      
      // 4. Para que serve o Center e por que ele precisa ser posto no inicio?
      body: Center(
        child: Column(
          // 5. Se existe o Widget Center(), por que alinhamento é importante?
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
            
            // 6. Por que não posso color o contador diretamente no texto igual faz no PHP?
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
                Navigator.push(
                  context,
                  // 8. Por que usamos MaterialPageRoute?
                  // 9. Para que serve o Builder?
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