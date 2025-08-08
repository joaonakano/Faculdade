@extends('layout')

@section('title', 'Editar Reserva')

@section('content')

<h1>Editar Reserva</h1>

<form action="{{ route('reservas.update', $reserva->id) }}" method="POST">

    @csrf
    @method('PUT')

    <div class="mb-3">

        <label for="sala_id" class="form-label">Sala:</label>
        <input type="number" name="sala_id" id="sala_id" class="form-control" min="0" value="{{ $reserva->sala_id }}" required>

        <label for="usuario" class="form-label">Usuario:</label>
        <input type="text" name="usuario" id="usuario" class="form-control" value="{{ $reserva->usuario }}" required>

        <label for="data" class="form-label">Data:</label>
        <input type="date" name="data" id="data" class="form-control" value="{{ $reserva->data }}" required>

        <label for="horario" class="form-label">Horario:</label>
        <input type="time" name="horario" id="horario" class="form-control" value="{{ $reserva->horario }}" required>

    </div>

    <button type="submit" class="btn btn-primary">Atualizar</button>

    <a href="{{ route('reservas.index') }}" class="btn btn-secondary">Cancelar</a>

</form>

@endsection