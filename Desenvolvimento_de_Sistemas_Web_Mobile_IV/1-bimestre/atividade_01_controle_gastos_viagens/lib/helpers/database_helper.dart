import 'package:atividade_01_controle_gastos_viagens/models/expense_model.dart';
import 'package:path/path.dart';
import 'package:sqflite/sqflite.dart';

class DatabaseHelper {
  // singleton
  static final DatabaseHelper _instance = DatabaseHelper._internal();
  
  // prevenindo a criação de mais de uma instancia porque é singleton
  DatabaseHelper._internal();

  // construtor singleton para devolver a instancia quando chamada a classe
  factory DatabaseHelper() {
    return _instance;
  }

  static Database? _database;

  Future<Database> get database async {
    if (_database != null) return _database!;
    _database = await _initDatabase();
    return _database!;
  }

  Future<Database> _initDatabase() async {
    final databasePath = await getDatabasesPath();
    final path = join(databasePath, 'expenses_database.db');

    return openDatabase(
      path,
      onCreate: (db, version) {
        return db.execute(
          'CREATE TABLE expenses(id INTEGER PRIMARY KEY, title TEXT, description TEXT, value REAL)',
        );
      },
      version: 1,
    );
  }

  Future<void> insertExpense(Expense expense) async {
    final db = await database;
    await db.insert(
      'expenses',
      expense.toMap(),
      conflictAlgorithm: ConflictAlgorithm.replace,
    );
  }

  Future<List<Expense>> getExpenses() async {
    final db = await database;
    final List<Map<String, dynamic>> expenseMaps = await db.query('expenses');
    return [
      for (final {
            'id': id as int,
            'title': title as String,
            'description': description as String,
            'value': value as double
          } in expenseMaps)
        Expense(id: id, value: value, title: title, description: description),
    ];
  }

  Future<int> getExpensesCount() async {
    final db = await database;
    final count = Sqflite.firstIntValue(
      await db.rawQuery('SELECT COUNT(*) FROM expenses'),
    );
    
    return count ?? 0;
  }
}