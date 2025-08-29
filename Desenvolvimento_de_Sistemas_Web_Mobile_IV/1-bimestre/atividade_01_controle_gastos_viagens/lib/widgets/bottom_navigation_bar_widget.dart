
import 'package:flutter/material.dart';

class BottomNavigationBarWidget extends StatefulWidget {
  const BottomNavigationBarWidget({super.key});

  @override
  State<BottomNavigationBarWidget> createState() => _BottomNavigationBarWidgetState();
}

class _BottomNavigationBarWidgetState extends State<BottomNavigationBarWidget> {
  int _selectedIndex = 0;
  
  void _onItemTapped(int index) {
    setState(() {
      _selectedIndex = index;
    });

    switch (index) {
      case 0:
        Navigator.pushNamed(context, '/');
      case 1:
        Navigator.pushNamed(context, '/'); // alterar para a rota depois
      case 2:
        Navigator.pushNamed(context, '/config');
      default:
        Navigator.pushNamed(context, '/');
    }
  }

  @override
  Widget build(BuildContext context) {
    return BottomNavigationBar(items: const <BottomNavigationBarItem>[
        BottomNavigationBarItem(icon: Icon(Icons.dashboard_customize), label: "Dashboard"),
        BottomNavigationBarItem(icon: Icon(Icons.add_box_outlined), label: "Nova Despesa"),
        BottomNavigationBarItem(icon: Icon(Icons.settings), label: "Configurações"),
      ],
      currentIndex: _selectedIndex,
      selectedItemColor: Colors.blue[400],
      onTap: _onItemTapped,
    );
  }
}