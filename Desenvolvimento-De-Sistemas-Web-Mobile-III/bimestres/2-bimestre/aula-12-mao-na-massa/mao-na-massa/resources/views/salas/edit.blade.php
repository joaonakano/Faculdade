@extends('layout')

@section('title', 'Editar Sala')

@section('content')

<h1>Editar Sala</h1>

<form action="{{ route('salas.update', $sala->id) }}" method="POST">
    
    @csrf
    @method('PUT')

    <div class="mb-3">
        
        <label for="nome" class="form-label">Nome:</label>
        <input type="string" name="nome" id="nome" class="form-control" value="{{ $sala->nome }}" required>
        
        <label for="capacidade" class="form-label">Capacidade:</label>
        <input type="number" name="capacidade"  id="capacidade" class="form-control" min="0" value="{{ $sala->capacidade }}" required>

    </div>

    <button type="submit" class="btn btn-primary">Atualizar</button>

    <a href="{{ route('salas.index') }}" class="btn btn-secondary">Cancelar</a>

</form>

@endsection