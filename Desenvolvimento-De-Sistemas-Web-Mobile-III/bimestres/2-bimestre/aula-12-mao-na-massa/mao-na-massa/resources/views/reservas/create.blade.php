@extends('layout')

@section('title', 'Criar Reserva')

@section('content')

<h1>Criar Nova Reserva</h1>

<form action="{{ route('reservas.store') }}" method="POST">

    @csrf
    <div class="mb-3">

        <label for="sala_id" class="form-label">Sala:</label>
        <input type="number" name="sala_id" id="sala_id" class="form-control" min="0" required>

        <label for="usuario" class="form-label">Usuario:</label>
        <input type="text" name="usuario" id="usuario" class="form-control" required>

        <label for="data" class="form-label">Data:</label>
        <input type="date" name="data" id="data" class="form-control" required>

        <label for="horario" class="form-label">Horario:</label>
        <input type="time" name="horario" id="horario" class="form-control" required>

    </div>

    <button type="submit" class="btn btn-success">Salvar</button>

    <a href="{{ route('reservas.index') }}" class="btn btn-secondary">Voltar</a>

</form>

@endsection