import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

class UserConfigScreen extends StatelessWidget {
  const UserConfigScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        leading: IconButton(onPressed: null, icon: Icon(Icons.arrow_back_ios)),
        //actions: [IconButton(onPressed: null, icon: Icon(Icons.settings))],
        title: const Text("Configurações", style: TextStyle(color: Colors.white),),
        backgroundColor: Colors.blue[400],
      ),
      body: Center(
        child: DropdownMenuWidget(),
      ),
    );
  }
}

class SliderWidget extends StatefulWidget {
  const SliderWidget({super.key});

  @override
  State<SliderWidget> createState() => _SliderWidgetState();
}

class _SliderWidgetState extends State<SliderWidget> {
  @override
  Widget build(BuildContext context) {
    return const Text("TESTE");
  }
} 

class DropdownMenuWidget extends StatefulWidget {
  const DropdownMenuWidget({super.key});

  @override
  State<DropdownMenuWidget> createState() => _DropdownMenuWidgetState();
}

class _DropdownMenuWidgetState extends State<DropdownMenuWidget> {
  final TextEditingController currencyController = TextEditingController();
  final TextEditingController expenseLimitController = TextEditingController();

  String? selectedCurrency;
  String? selectedExpenseLimit;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        //padding: EdgeInsets.all(100),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            DropdownMenu<String>(
              hintText: "Selecione uma Moeda",
              controller: currencyController,
              requestFocusOnTap: true,
              initialSelection: "JPY",
              label: const Text("Moeda"),
              dropdownMenuEntries: [
                DropdownMenuEntry(value: "BRL", label: "BRL"),
                DropdownMenuEntry(value: "USD", label: "USD"),
                DropdownMenuEntry(value: "EUR", label: "EUR"),
                DropdownMenuEntry(value: "GBP", label: "GBP"),
                DropdownMenuEntry(value: "JPY", label: "JPY"),
              ],
              onSelected: (String? moedaSelecionada) {
                setState(() {
                  selectedCurrency = moedaSelecionada;
                });
              },
            ),
            const SizedBox(height: 18,),
            TextField(
              controller: expenseLimitController,
              keyboardType: TextInputType.number,
              inputFormatters: <TextInputFormatter>[
                FilteringTextInputFormatter.allow(RegExp(r'[0-9]')),
                FilteringTextInputFormatter.digitsOnly
              ],
              decoration: InputDecoration(
                prefixIcon: Icon(Icons.monetization_on),
                suffixIcon: Icon(Icons.clear),
                labelText: 'Limite de gastos',
                border: OutlineInputBorder(),
              ),
              onSubmitted: (String limiteGastos) async {
                setState(() {
                  selectedExpenseLimit = limiteGastos;
                });
                await showDialog(
                  context: context,
                  builder: (BuildContext context) {
                    return AlertDialog(
                      title: const Text('Aviso'),
                      content: Text('Suas configurações foram salvas!\nMoeda Selecionada: $selectedCurrency\nLimite de Gastos: $selectedExpenseLimit'),
                      actions: <Widget>[
                        TextButton(onPressed: () {
                          Navigator.pop(context);
                          print('Funcionou');
                        }, child: const Text('OK'))
                      ],
                    );
                  });
              },
            )
          ],
        ),
      ),
    );
  }
}