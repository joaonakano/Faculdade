@extends('layout')

@section('title', 'Detalhes da Sala')

@section('content')

<h1>Detalhes da Sala</h1>

<p><strong>Nome:</strong> {{ $sala->nome }}</p>
<p><strong>Capacidade:</strong> {{ $sala->capacidade }}</p>

<a href="{{ route('salas.index') }}" class="btn btn-secondary">Voltar</a>

@endsection