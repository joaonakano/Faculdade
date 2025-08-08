import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class SecondApp extends StatelessWidget {
  const SecondApp({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text("Nova Página!")),
      body: Center(
        child: ElevatedButton(
          onPressed: () {
            Navigator.pop(context);
          },
          child: const Text('Voltar'))
      )
    );
  }
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Inputs e Interatividade',
      theme: ThemeData(primarySwatch: Colors.deepPurple),
      home: const FormularioPage(),
    );
  }
}

class FormularioPage extends StatefulWidget {
  const FormularioPage({super.key});

  @override
  State<FormularioPage> createState() => _FormularioPageState();
}

class _FormularioPageState extends State<FormularioPage> {
  // chave global
  final GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  // controllers
  final TextEditingController _nomeController = TextEditingController();
  final TextEditingController _emailController = TextEditingController();
  final TextEditingController _senhaController = TextEditingController();

  bool _isPasswordObscured = true;

  // gesture detector
  String _toqueMensagem = 'Nenhum toque detectado.';

  @override
  void dispose() {
    // liberar recursos do controlador
    _nomeController.dispose();
    _senhaController.dispose();
    _emailController.dispose();
    super.dispose();
  }

  void _enviarFormulario() {
    // acionar validação dos TextFormFields
    if (_formKey.currentState!.validate()) {
      // se todos os campos forem válidos
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
          content: Text(
            'Formulário Válido!\nNome: ${_nomeController.text}\nEmail: ${_emailController.text}',
          ),
          backgroundColor: Colors.green,
        ),
      );
    } else {
      // caso haja erro de validação
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
          content: Text('Por favor, kill me!'),
          backgroundColor: Colors.red,
        ),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text(
          'Entrada de Dados e Interatividade',
          style: TextStyle(color: Colors.white),
        ),
        backgroundColor: Colors.deepPurple,
      ),
      // permite rolar a tela se o teclado aparecer
      body: SingleChildScrollView(
        padding: EdgeInsets.all(20),
        child: Form(
          key: _formKey,
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: <Widget>[
              // titulo da seção
              Text(
                'Cadastre-se',
                textAlign: TextAlign.center,
                style: TextStyle(
                  fontSize: 28,
                  fontWeight: FontWeight.bold,
                  color: Colors.deepPurple,
                ),
              ),
              const SizedBox(height: 25),
              // Campo de Texto
              TextField(
                controller: _nomeController,
                decoration: const InputDecoration(
                  labelText: 'Nome Completo',
                  hintText: 'Ex: João Nakano',
                  border: OutlineInputBorder(),
                  prefixIcon: Icon(Icons.person),
                ),
              ),
              const SizedBox(height: 25),
              // Campo de Texto
              TextFormField(
                controller: _emailController,
                keyboardType: TextInputType.emailAddress,
                decoration: const InputDecoration(
                  labelText: 'E-mail',
                  hintText: 'Ex: john@doe.com',
                  border: OutlineInputBorder(),
                  prefixIcon: Icon(Icons.email),
                ),
                validator: (value) {
                  if (value == null || value.isEmpty) {
                    return 'O e-mail é obrigatório';
                  }

                  if (!value.contains('@') || !value.contains('.')) {
                    return 'Digite um e-mail válido';
                  }

                  return null; // Se for válido
                },
              ),
              const SizedBox(height: 25),
              // Campo de Texto
              TextFormField(
                controller: _senhaController,
                obscureText: _isPasswordObscured ?? false,
                decoration: InputDecoration(
                  labelText: 'Senha',
                  hintText: 'Mínimo 6 caracteres',
                  border: OutlineInputBorder(),
                  prefixIcon: Icon(Icons.lock),
                  suffixIcon: IconButton(
                    icon: Icon(
                      _isPasswordObscured
                          ? Icons.visibility_off
                          : Icons.visibility,
                    ),
                    onPressed: () {
                      setState(() {
                        _isPasswordObscured = !_isPasswordObscured;
                      });
                    },
                  ),
                ),
                validator: (value) {
                  if (value == null || value.isEmpty) {
                    return 'A senha é obrigatória';
                  }

                  if (value.length < 6) {
                    return 'A senha deve conter ao menos 6 caracteres.';
                  }

                  return null; // Se for válido
                },
              ),
              const SizedBox(height: 25),
              // Botão de Envio
              ElevatedButton.icon(
                onPressed: _enviarFormulario,
                icon: Icon(Icons.send, color: Colors.white),
                label: Text(
                  'Enviar Cadastro',
                  style: TextStyle(fontSize: 18, color: Colors.white),
                ),
                style: ElevatedButton.styleFrom(
                  backgroundColor: Colors.deepPurple,
                  shape: RoundedRectangleBorder(
                    borderRadius: BorderRadius.circular(10),
                  ),
                ),
              ),
              SizedBox(
                height: 25,
              ),
              GestureDetector(
                onTap: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(builder: (context) => const SecondApp())
                  );
                },
                child: Container(
                  color: Colors.amber,
                  padding: const EdgeInsets.all(8),
                  child: Text("Ir para a página"),
                )
              )
            ],
          ),
        ),
      ),
    );
  }
}
