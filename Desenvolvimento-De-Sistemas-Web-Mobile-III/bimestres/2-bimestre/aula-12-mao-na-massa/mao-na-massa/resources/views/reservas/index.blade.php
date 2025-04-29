@extends('layout')

@section('title', 'Lista de Reservas')

@section('content')

<h1>Lista de Reservas</h1>

<a href="{{ route('reservas.create') }}" class="btn btn-primary mb-3">Criar Nova Reserva</a>

<ul class="list-group">

    @foreach($reservas as $reserva)

        <li class="list-group-item d-flex justify-content-between align-items-center">
            {{ $reserva->usuario }}

            <div>
                <a href="{{ route('reservas.show', $reserva->id) }}" class="btn btn-sm btn-info">Ver</a>
                <a href="{{ route('reservas.edit', $reserva->id) }}" class="btn btn-sm btn-warning">Editar</a>

                <form action="{{ route('reservas.destroy', $reserva->id) }}" method="POST" style="display:inline;">

                    @csrf
                    @method('DELETE')

                    <button type="submit" class="btn btn-sm btn-danger">Excluir</button>

                </form>
                
            </div>

        </li>

    @endforeach

</ul>

@endsection