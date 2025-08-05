import 'package:flutter/material.dart';

void main() {
  runApp(const MeuProjetoIntegradorApp());
}

class MeuProjetoIntegradorApp extends StatelessWidget {
  const MeuProjetoIntegradorApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Meu Projeto Integrador Flutter',
      theme: ThemeData(primarySwatch: Colors.lightGreen),
      home: const TelaInicialProjeto(),
      debugShowCheckedModeBanner: false,
    );
  }
}

class TelaInicialProjeto extends StatelessWidget {
  const TelaInicialProjeto({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Boas-vindas!'), centerTitle: true),

      body: SizedBox.expand(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center, // VERTICAL
          crossAxisAlignment: CrossAxisAlignment.center, // HORIZONTAL
          children: [
            const Text(
              'Bem-vindo ao meu Projeto',
              style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
              textAlign: TextAlign.center,
            ),
            const SizedBox(height: 20),
            Container(
              padding: const EdgeInsets.all(15.0),
              decoration: BoxDecoration(
                color: Colors.amber,
                borderRadius: BorderRadius.circular(10.0),
                border: Border.all(color: Colors.black45),
              ),
              child: const Text(
                'Esta é a primeira tela construída com Flutter.',
                textAlign: TextAlign.center,
                style: TextStyle(fontSize: 16),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
