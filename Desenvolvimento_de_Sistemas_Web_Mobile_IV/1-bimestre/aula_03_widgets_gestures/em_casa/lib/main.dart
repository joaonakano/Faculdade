// ignore_for_file: avoid_print

import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  /* CODIGO ABAIXO NAO FUNCIONA. MOTIVO: NAO TEM MATERIAL APP NA RAIZ, APENAS O SCAFFOLD
  @override
  build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text("Meu primeiro App Sozinho"),),
      body: const Column(
        crossAxisAlignment: CrossAxisAlignment.center,
        children: [
          Text("Teste!")
        ],
      ),
    );
  }
  */

  /*
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "Meu primeiro app sem ajuda",
      home: Scaffold(
        appBar: AppBar(
          title: const Text("Home"),
        ),
        body: const Text("Texto inicial"),
      ),
    );
  }
  */

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Inputs e Interatividade',
      theme: ThemeData(
        colorSchemeSeed: Colors.deepPurple,
      ),
      home: const FormularioSimplesPage(),
      debugShowCheckedModeBanner: false,
    );
  }
}

// Stateful Widget
class FormularioSimplesPage extends StatefulWidget {
  const FormularioSimplesPage({super.key});

  @override
  State<FormularioSimplesPage> createState() => _FormularioSimplesPageState();
}

// State Widget Definition
class _FormularioSimplesPageState extends State<FormularioSimplesPage> {
  final GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  // Controllers
  final TextEditingController _nomeController = TextEditingController();
  final TextEditingController _senhaController = TextEditingController();
  final TextEditingController _emailController = TextEditingController();

  // Controlador de Visibilidade
  bool _isPasswordVisible = true;

  // Mensagem de Gesto
  // ignore: unused_field, prefer_final_fields
  String _toqueMensagem = 'Ainda nenhum toque detectado.';

  @override
  void dispose() {
    _nomeController.dispose();
    _senhaController.dispose();
    _emailController.dispose();
    super.dispose();
  }

  void _enviarFormulario() {
    if (_formKey.currentState!.validate()) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
          content: Text("Usuário registrado com sucesso!\nNome: ${_nomeController.text}\nE-mail: ${_emailController.text}"),
          backgroundColor: Colors.lightGreen,
        )
      );

      // Campo destinado a armazenar os valores no Banco de Dados
      print('Dados a enviar:');
      print('Nome: ${_nomeController.text}');
      print('Email: ${_emailController.text}');
      print('Senha: ${_senhaController.text}');
    } else {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text("Não foi possível enviar o formulário. Corrija os erros e tente novamente"),
          backgroundColor: Colors.redAccent,
        ),
      );
      //_formKey.currentState!.reset();
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Entrada de Dados e Interatividade"),
      ),
      body: SingleChildScrollView(
        padding: const EdgeInsets.all(20.0),
        child: Form(
          key: _formKey,
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: [
              const Text(
                "Cadastre-se",
                style: TextStyle(
                  color: Colors.deepPurple,
                  fontWeight: FontWeight.bold,
                  fontSize: 28
                ),
                textAlign: TextAlign.center,
              ),
              
              const SizedBox(
                height: 25,
              ),

              TextField(
                controller: _nomeController,
                decoration: const InputDecoration(
                  labelText: "Nome Completo",
                  hintText: "João Silva",
                  prefixIcon: Icon(Icons.person_4),
                  border: OutlineInputBorder(),
                ),
                onChanged: (text) {
                  // Espaço destinado a validar em tempo-real o input
                },
              ),

              const SizedBox(
                height: 25,
              ),

              TextFormField(
                controller: _emailController,
                decoration: const InputDecoration(
                  labelText: "E-mail",
                  hintText: "john@doe.com.br",
                  prefixIcon: Icon(Icons.email),
                  border: OutlineInputBorder(),
                ),
                onChanged: (text) {
                  // Espaço destinado a validar em tempo-real o input
                },
                validator: (email) {
                  if (email == null || email.isEmpty) {
                    return 'O e-mail é obrigatório';
                  }

                  if (!email.contains('@') || !email.contains('.')) {
                    return 'Digite um e-mail válido';
                  }

                  return null;
                },
              ),
              
              const SizedBox(
                height: 25,
              ),

              TextFormField(
                controller: _senhaController,
                obscureText: _isPasswordVisible,
                decoration: InputDecoration(
                  labelText: "Senha",
                  hintText: "Mínimo 6 caracteres",
                  prefixIcon: const Icon(Icons.lock),
                  suffixIcon: IconButton(
                    onPressed: () {
                      setState(() {
                        _isPasswordVisible = !_isPasswordVisible;
                      });
                    },
                    icon: Icon(_isPasswordVisible ? Icons.visibility_off : Icons.visibility ),
                  ),
                  border: const OutlineInputBorder(),
                ),
                onChanged: (text) {
                  // Espaço destinado a validar em tempo-real o input
                },
                validator: (senha) {
                  if (senha == null || senha.isEmpty) {
                    return "Digite uma senha válida";
                  }

                  if (senha.length < 6) {
                    return "Digite uma senha de ao menos 6 dígitos";
                  }

                  return null;
                },
              ),

              const SizedBox(
                height: 30,
              ),

              ElevatedButton.icon(
                onPressed: _enviarFormulario,
                label: const Text(
                  "Enviar",
                  style: TextStyle(fontSize: 18),
                ),
                icon: const Icon(Icons.send_rounded),
                style: ElevatedButton.styleFrom(
                  padding: const EdgeInsets.symmetric(vertical: 15),
                  shape: RoundedRectangleBorder(
                    borderRadius: BorderRadius.circular(10),
                  )
                )
              ),

              const SizedBox(
                height: 20,
              ),

              TextButton(
                onPressed: () {
                  ScaffoldMessenger.of(context).showSnackBar(
                    const SnackBar(content: Text("Termos aceitos!"))
                  );
                },
                child: const Text("Leia os Termos de Uso")
              ),

              const SizedBox(
                height: 30,
              ),

              GestureDetector(
                onTap: () {
                  setState(() {
                    _toqueMensagem = "Single Tap!";
                  });

                  ScaffoldMessenger.of(context).showSnackBar(
                    const SnackBar(
                      content: Text("Você deu um clique")
                    )
                  );
                },
                onDoubleTap: () {
                  setState(() {
                    _toqueMensagem = "Double Tap!";
                  });

                  ScaffoldMessenger.of(context).showSnackBar(
                    const SnackBar(
                      content: Text("Você deu dois cliques")
                    )
                  );
                },
                onLongPress: () {
                  setState(() {
                    _toqueMensagem = "Long Pressed!";
                  });
                  ScaffoldMessenger.of(context).showSnackBar(
                    const SnackBar(content: Text("Você pressionou o contâiner")),
                  );
                },
                child: Container(
                  padding: const EdgeInsets.all(20),
                  color: Colors.deepPurple.shade100,
                  alignment: Alignment.center,
                  child: Column(
                    children: [
                      const Icon(Icons.touch_app_sharp, size: 50, color: Colors.deepPurple),
                      const SizedBox(height: 10,),
                      Text(
                        _toqueMensagem,
                        textAlign: TextAlign.center,
                        style: const TextStyle(fontSize: 16, color: Colors.deepPurple)
                      )
                    ],
                  )
                ),
              ),

              const SizedBox(
                height: 20,
              ),

              ElevatedButton(
              onPressed: () {
                ScaffoldMessenger.of(context).showSnackBar(
                  SnackBar(
                    content: Text("Nome digitado (TextField): ${_nomeController.text}")
                  ),
                );
              },
              child: const Text("Ver nome inserido")
              ),
            ],
          ),
        ),
      ),
    );
  }
}