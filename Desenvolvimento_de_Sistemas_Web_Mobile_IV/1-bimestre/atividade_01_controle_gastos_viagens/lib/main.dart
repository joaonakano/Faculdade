import 'package:atividade_01_controle_gastos_viagens/screens/expenses_screen.dart';
import 'package:atividade_01_controle_gastos_viagens/screens/user_config_screen.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(const MainApp());
}

class MainApp extends StatelessWidget {
  const MainApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      routes: {
        '/': (context) => const ExpensesScreen(),
        '/config': (context) => const UserConfigScreen(),
      },
      debugShowCheckedModeBanner: false,
    );
  }
}

