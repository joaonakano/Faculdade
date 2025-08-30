import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';

class ExpensesCreationScreen extends StatefulWidget {
  const ExpensesCreationScreen({super.key});

  @override
  State<ExpensesCreationScreen> createState() => _ExpensesCreationScreenState();
}

class _ExpensesCreationScreenState extends State<ExpensesCreationScreen> {
  String selectedCurrency = "";
  String selectedExpensesLimit = "";

  @override
  void initState() {
    super.initState();
    _loadSettings();
  }

  Future<void> _loadSettings() async {
    final prefs = await SharedPreferences.getInstance();
    setState(() {
      selectedCurrency = prefs.getString('selectedCurrency') ?? "Nenhuma moeda";
      selectedExpensesLimit =
          prefs.getString('selectedExpensesLimit') ?? "Nenhum limite"; //bagulho do demonio, mas funcionou
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text("...say that again?")),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text("Moeda escolhida: $selectedCurrency",
                style: const TextStyle(fontSize: 20)),
            const SizedBox(height: 12),
            Text("Limite de gastos: $selectedExpensesLimit",
                style: const TextStyle(fontSize: 20)),
          ],
        ),
      ),
    );
  }
}
