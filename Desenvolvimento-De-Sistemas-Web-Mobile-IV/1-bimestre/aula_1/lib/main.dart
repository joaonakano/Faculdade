import "package:flutter/material.dart";

void main() {
  runApp(const AulaUm());
}

class AulaUm extends StatelessWidget {
  const AulaUm({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "Aula 1",
      home: const PaginaPrincipal(),
      debugShowCheckedModeBanner: false,
    );
  }
}

class PaginaPrincipal extends StatelessWidget {
  const PaginaPrincipal({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: 
        AppBar(
          title: const Text("Boas-vindas!"),
          centerTitle: true,
        ),
        
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            const Text(
              "Bem-vindo ao Meu Projeto Integrador!",
              style: TextStyle(
                fontWeight: FontWeight.bold,
                fontSize: 24,
              ),
            ),

            SizedBox(height: 20,),

            Container(
              decoration: BoxDecoration(
                color: Colors.blueAccent.withOpacity(0.1),
                border: Border.all(color: Colors.blueAccent),
                borderRadius: BorderRadius.circular(10)
              ),
              padding: EdgeInsets.all(12),
              margin: EdgeInsets.symmetric(horizontal: 20.0),
              child: const Text(
                "Esta é a nossa primeira tela construída com Flutter. Explore!",
                textAlign: TextAlign.center,
                style: TextStyle(
                  fontSize: 16
                ),
              ),
            ),

            SizedBox(height: 30,),

            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                Icon(Icons.star, color: Colors.orangeAccent, size: 35,),

                Text(
                  "Começando a jornada!",
                  style: TextStyle(
                    fontStyle: FontStyle.italic,
                    fontSize: 18
                  )
                ),

                Icon(Icons.code, color: Colors.grey, size: 35),
              ],
            ),

            SizedBox(height: 20,),
            
            const CardProximaJornada(
              cardTitle: "Próximos Passos",
              cardMessage: "Na próxima aula, vamos adicionar interatividade."
            ),
          ],
        ),
      ),
    );
  }
}

class CardProximaJornada extends StatelessWidget {
  final String cardTitle;
  final String cardMessage;

  const CardProximaJornada({
    super.key,
    required this.cardTitle,
    required this.cardMessage
  });

  @override
  build(BuildContext context) {
    return Container(
      padding: EdgeInsets.all(15),
      margin: const EdgeInsets.symmetric(horizontal: 20, vertical: 20),
      decoration: BoxDecoration(
        borderRadius: BorderRadius.circular(10),
        boxShadow: [
          BoxShadow(
            color: Colors.grey.shade300,
            offset: Offset(0, 3),
            blurRadius: 5,
            spreadRadius: 2
          ),
        ],
        color: Colors.white,
      ),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Text(
            cardTitle,
            style: TextStyle(
              color: Colors.deepPurple,
              fontSize: 18,
              fontWeight: FontWeight.bold,
            ),
          ),
          SizedBox(height: 5,),
          Text(
            cardMessage,
            style: TextStyle(fontSize: 14, color: Colors.black87),),
        ],
      ),
    );
  }
}