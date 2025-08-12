import 'package:flutter/material.dart';
import 'package:aula_04_navegabilidade/screens/home_screen.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "Aula 04",
      home: const HomeScreen(),
      debugShowCheckedModeBanner: false,
    );
  }
}