import 'package:flutter/material.dart';
import 'package:aula_04_navegabilidade/screens/detail_screen.dart';

class HomeScreen extends StatefulWidget {
  const HomeScreen({super.key});

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  int _contadorClique = 0; // Estado local para o contador

  void _incrementarContador() {
    setState(() { // Notifica o Flutter que o estado mudou
      _contadorClique++;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Tela Principal'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            const Text(
              'Bem-vindo ao Projeto Integrador!',
              style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
              textAlign: TextAlign.center,
            ),
            const SizedBox(height: 30),

            // Exemplo de Contador com setState
            const Text(
              'Cliques no botão de navegação:',
              style: TextStyle(fontSize: 18),
            ),
            Text(
              '$_contadorClique',
              style: const TextStyle(fontSize: 48, fontWeight: FontWeight.bold),
            ),
            const SizedBox(height: 20),

            ElevatedButton(
              onPressed: () {
                _incrementarContador(); // Incrementa o contador
                // Navegar para a tela de detalhes, passando dados
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => DetailScreen(
                      itemId: 42,
                      itemName: 'Item Secreto',
                      cliquesContador: _contadorClique, // Passando o estado do contador
                    ),
                  ),
                );
              },
              child: const Text('Ir para Detalhes do Item'),
            ),
            const SizedBox(height: 20),

            // Exemplo de pushReplacement - útil após login ou reset
            ElevatedButton(
              onPressed: () {
                // Simula um "logout" ou "reset" do app, retornando à tela principal
                Navigator.pushReplacement(
                  context,
                  MaterialPageRoute(builder: (context) => const HomeScreen()), // Redireciona para a própria Home, mas substitui na pilha
                );
                ScaffoldMessenger.of(context).showSnackBar(
                  const SnackBar(content: Text('Simulando reset/logout!')),
                );
              },
              style: ElevatedButton.styleFrom(backgroundColor: Colors.red),
              child: const Text('Simular Reset/Logout'),
            ),
          ],
        ),
      ),
    );
  }
}

