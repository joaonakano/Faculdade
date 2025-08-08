@extends('layout')

@section('title', 'Detalhes da Reserva')

@section('content')

<h1>Detalhes da Reserva</h1>

<p><strong>ID da Sala:</strong> {{ $reserva->sala_id }}</p>
<p><strong>Usuário:</strong> {{ $reserva->usuario }}</p>
<p><strong>Data:</strong> {{ $reserva->data }}</p>
<p><strong>Horário:</strong> {{ $reserva->horario }}</p>

<a href="{{ route('reservas.index') }}" class="btn btn-secondary">Voltar</a>

@endsection