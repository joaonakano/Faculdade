import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

/// O pontapé inicial para inicializar o aplicativo é a função runApp()
/// Passamos um OBJETO que servirá de widget mais acima da hierarquia
/// Pode ser CONST, NEW ou apenas o nome da classe seguida de parênteses ()

class MyApp extends StatelessWidget {
/// A classe serve como contâiner para os outros widgets ao mesmo tempo que é ela mesma um widget
/// As classes derivam de classes abstratas como StatelessWidget, StatefulWidget, etc

  const MyApp({super.key});
  /// Construtor CONSTANTE (compile-time evalued) que passa uma uma chave à superclasse. Lembrando que usam-se os colchetes para possibilitar a definição diretamente na chamada do construtor: construtor(key: abc)

  @override
  Widget build(BuildContext context) {
  /// Sobrescrição do método BUILD da classe abstrata, geralmente usa-se a notação @override para sinalizar melhor ao compilador do flutter
  /// O BUILDCONTEXT é um objeto da classe ELEMENTO, que possui informações valiosas sobre onde aquele nó está em relação à árvore de elementos. Representa a localização de um widget
  
    return MaterialApp(
    /// Um MaterialApp é um widget que reúne as funcionalidades obrigatórias mais comuns de aplicações que usam o Material Design
      title: 'Inputs e Interatividade',
      // Título que fica acima da snapshot do aplicativo, não é o título da página ou algo parecido

      theme: ThemeData(
        colorSchemeSeed: Colors.amber,
      ),

      home: const FormularioSimplesPage(),
      /// A rota padrão do aplicativo ao inicializar
      
      debugShowCheckedModeBanner: false,
    );
  }
}

class FormularioSimplesPage extends StatefulWidget {
  const FormularioSimplesPage({super.key});

  @override
  State<FormularioSimplesPage> createState() => _FormularioSimplesPageState();
  /// Instanciação de um estado que será filho do widget atual (State<T>), no caso, _FormularioSimplesPageState
  /// Fat arrow function (=>) retorna um objeto STATE _FormularioSimplesPageState sempre que esse widget for posto na Árvore de Widgets
}

class _FormularioSimplesPageState extends State<FormularioSimplesPage> {
/// Codificação efetiva do estado a ser utilizado no widget. O State<Type> significa que o estado está explicitamente atrelado à classe FormularioSimplesPage, impedindo o uso dos métodos de seu objeto em outro widget não mencionado

}