// Este é o código inicial, sem nenhuma organização.
// A sua tarefa é refatorar este arquivo.

import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  String _cityName = 'São Paulo';
  double _temperature = 25.0;
  String _weatherDescription = 'Ensolarado';
  String _weatherIcon = '☀️';
  bool _isLoading = false;

  void _fetchWeather() {
    setState(() {
      _isLoading = true;
    });

    // Simulação de uma requisição de API
    Future.delayed(const Duration(seconds: 2), () {
      setState(() {
        _cityName = 'Rio de Janeiro';
        _temperature = 28.5;
        _weatherDescription = 'Chuva leve';
        _weatherIcon = '🌧️';
        _isLoading = false;
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('App do Clima'),
          centerTitle: true,
          backgroundColor: Colors.blueAccent,
        ),
        body: Center(
          child: _isLoading
              ? const CircularProgressIndicator()
              : Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    const SizedBox(height: 20),
                    // Este é o 'organism' principal do app
                    Container(
                      padding: const EdgeInsets.all(20),
                      margin: const EdgeInsets.symmetric(horizontal: 20),
                      decoration: BoxDecoration(
                        color: Colors.white,
                        borderRadius: BorderRadius.circular(15),
                        boxShadow: [
                          BoxShadow(
                            color: Colors.grey.withOpacity(0.5),
                            spreadRadius: 2,
                            blurRadius: 7,
                            offset: const Offset(0, 3),
                          ),
                        ],
                      ),
                      child: Column(
                        crossAxisAlignment: CrossAxisAlignment.stretch,
                        children: [
                          // Esta é a 'molécula' de localização
                          Text(
                            _cityName,
                            style: const TextStyle(
                              fontSize: 30,
                              fontWeight: FontWeight.bold,
                              color: Colors.black87,
                            ),
                            textAlign: TextAlign.center,
                          ),
                          const SizedBox(height: 10),
                          // Esta é a 'molécula' de ícone e temperatura
                          Row(
                            mainAxisAlignment: MainAxisAlignment.center,
                            children: [
                              Text(
                                _weatherIcon,
                                style: const TextStyle(fontSize: 60),
                              ),
                              const SizedBox(width: 10),
                              Text(
                                '${_temperature}°C',
                                style: const TextStyle(
                                  fontSize: 60,
                                  fontWeight: FontWeight.w200,
                                  color: Colors.black87,
                                ),
                              ),
                            ],
                          ),
                          const SizedBox(height: 10),
                          // Este é um 'átomo'
                          Text(
                            _weatherDescription,
                            style: const TextStyle(
                              fontSize: 20,
                              color: Colors.black54,
                            ),
                            textAlign: TextAlign.center,
                          ),
                        ],
                      ),
                    ),
                    const SizedBox(height: 40),
                    // Este é outro 'organism', a seção de botões
                    Column(
                      children: [
                        // Esta é uma 'molécula' de botão
                        ElevatedButton(
                          onPressed: _fetchWeather,
                          child: const Text('Atualizar Clima'),
                          style: ElevatedButton.styleFrom(
                            backgroundColor: Colors.lightBlue,
                            foregroundColor: Colors.white,
                            padding: const EdgeInsets.symmetric(horizontal: 30, vertical: 15),
                            textStyle: const TextStyle(fontSize: 16),
                            shape: RoundedRectangleBorder(
                              borderRadius: BorderRadius.circular(10),
                            ),
                          ),
                        ),
                        const SizedBox(height: 10),
                        // Outra 'molécula' de botão
                        ElevatedButton(
                          onPressed: () {},
                          child: const Text('Buscar Nova Cidade'),
                          style: ElevatedButton.styleFrom(
                            backgroundColor: Colors.white,
                            foregroundColor: Colors.lightBlue,
                            padding: const EdgeInsets.symmetric(horizontal: 30, vertical: 15),
                            textStyle: const TextStyle(fontSize: 16),
                            shape: RoundedRectangleBorder(
                              borderRadius: BorderRadius.circular(10),
                              side: const BorderSide(color: Colors.lightBlue),
                            ),
                          ),
                        ),
                      ],
                    ),
                  ],
                ),
        ),
      ),
    );
  }
}
