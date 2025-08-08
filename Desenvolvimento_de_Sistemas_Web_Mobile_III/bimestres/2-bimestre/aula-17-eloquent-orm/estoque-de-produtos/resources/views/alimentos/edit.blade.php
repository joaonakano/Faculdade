@extends("layouts.main")

@section("titulo", "Atualizar Alimento")

@section('content')

    @section("titulo-pagina", "Editar Alimento")

    <form action="{{ route('alimentos.update', $alimento) }}" method="POST">

        @csrf
        @method('PUT')
        <input type="text" name="nome" placeholder="Nome" value="{{ $alimento->nome }}" required>
        <input type="number" name="quantidade" placeholder="Quantidade" value="{{ $alimento->quantidade}}" required>
        <input type="date" name="validade" value="{{ $alimento->validade }}">
        <input type="text" name="categoria" placeholder="Categoria" value="{{ $alimento->categoria }}" required>
        <button type="submit">Atualizar</button>
        
    </form>

@endsection