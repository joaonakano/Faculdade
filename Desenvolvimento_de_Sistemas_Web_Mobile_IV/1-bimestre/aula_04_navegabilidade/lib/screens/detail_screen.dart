import 'package:flutter/material.dart';

class DetailScreen extends StatelessWidget {
  final int itemId;
  final String itemName;
  final int cliquesContador;
  
  // 1. Por que os parâmetros ficam entre chaves?
  // 2. Para que serve super.key?
  // 3. Super.key é obrigatória?
  // 4. Por que usa-se this.<param>?
  const DetailScreen({
    required this.itemId,
    required this.itemName,
    this.cliquesContador = 0,
    super.key
  });

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Detalhes: $itemName"),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            const Text(
              'Você está na Tela de Detalhes!',
              style: TextStyle(
                fontSize: 22,
                fontWeight: FontWeight.bold,
              ),
              // 5. Por que usamos um widget chamado TextAlign ao invés de passar diretamente?
              textAlign: TextAlign.center,
            ),

            const SizedBox(height: 20,),

           Text(
            'ID do Item: $itemId',
            style: TextStyle(fontSize: 18),
           ),

           Text(
            'Nome do Item: $itemName',
            style: TextStyle(fontSize: 18),
           ),

           Text(
            "Cliques na tela anterior: $cliquesContador",
            style: TextStyle(fontSize: 18),
           ),

           const SizedBox(height: 30,),

            ElevatedButton(
              onPressed: () {
                Navigator.pop(context);
              },
              child: const Text("Voltar para Tela Principal"),
            ),
          ],
        ),
      ),
    );
  }
}