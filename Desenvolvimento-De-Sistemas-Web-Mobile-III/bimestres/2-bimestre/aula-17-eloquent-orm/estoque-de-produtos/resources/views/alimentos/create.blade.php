@extends('layouts.main')

@section('titulo', 'Registro de Alimento')

@section('content')

    @section('titulo-pagina', 'Registro de Alimento')

    <form action="{{ route('alimentos.store') }}" method="POST">

        @csrf
        <input type="text" name="nome" placeholder="Nome" required>
        <input type="number" name="quantidade" placeholder="Quantidade" required>
        <input type="date" name="validade">
        <label>Escolha uma categoria para o alimento:</label>
        <select type="select" name="categoria" required>
            <option value="frutas">Frutas</option>
            <option value="legumes">Legumes</option>
            <option value="carnes">Carnes</option>
            <option value="diversos">Diversos</option>
            <option value="outros" selected>Outros</option>
        </select>
        <button type="submit">Salvar</button>
        
    </form>

@endsection