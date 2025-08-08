@extends('layout')

@section('title', 'Lista de Salas')

@section('content')

<h1>Lista de Salas</h1>

<a href="{{ route('salas.create') }}" class="btn btn-primary mb-3">Criar Nova Sala</a>

<ul class="list-group">

    @foreach($salas as $sala)

        <li class="list-group-item d-flex justify-content-between align-items-center">
            {{ $sala->nome }}

            <div>

                <a href="{{ route('salas.show', $sala->id) }}" class="btn btn-sm btn-info">Ver</a>
                <a href="{{ route('salas.edit', $sala->id) }}" class="btn btn-sm btn-warning">Editar</a>
            
                <form action="{{ route('salas.destroy', $sala->id) }}" method="POST" style="display:inline;">

                    @csrf
                    @method('DELETE')

                    <button type="submit" class="btn btn-sm btn-danger">Excluir</button>
                
                </form>
                
            </div>
        
        </li>
    
    @endforeach

</ul>

@endsection