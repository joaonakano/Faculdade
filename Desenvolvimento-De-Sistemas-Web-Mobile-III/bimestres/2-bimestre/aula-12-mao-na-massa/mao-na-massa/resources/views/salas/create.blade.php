@extends('layout')

@section('title', 'Criar Sala')

@section('content')

<h1>Criar Sala</h1>

<form action="{{ route('salas.store') }}" method="POST">

    @csrf
    <div class="mb-3">
        
        <label for="nome" class="form-label">Nome:</label>
        <input type="string" name="nome" id="nome" class="form-control" required>
        
        <label for="capacidade" class="form-label">Capacidade:</label>
        <input type="number" name="capacidade"  id="capacidade" min="0" class="form-control" required>

    </div>

    <button type="submit" class="btn btn-success">Salvar</button>

    <a href="{{ route('salas.index') }}" class="btn btn-secondary">Voltar</a>
    
</form>

@endsection