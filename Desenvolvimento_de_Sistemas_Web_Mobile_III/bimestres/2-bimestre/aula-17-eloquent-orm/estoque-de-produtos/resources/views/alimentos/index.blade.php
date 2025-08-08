@extends('layouts.main')

@section('titulo', 'Listagem de Alimentos')

@section('content')

    @section('titulo-pagina', 'Listagem de Alimentos')

    @if(session('status'))
        <div class="alert alert-success">
            {{ session('status') }}
        </div>
    @endif

    <div class="mb-3 d-flex flex-wrap align-items-center gap-2">
        <a href="{{ route('alimentos.index') }}" class="btn btn-secondary">Todos Alimentos</a>
        <a href="{{ route('alimentos.index', ['filtro' => 'expirando_em_breve']) }}" class="btn btn-primary">Expirando em Breve</a>
        <a href="{{ route('alimentos.create') }}" class="btn btn-success">Adicionar Novo Alimento</a>

        <form action="{{ route('alimentos.index', ['filtro_categoria' => '']) }}" method="GET" class="d-flex align-items-center gap-2">
            <input type="hidden" name="filtro" value="{{ request('filtro') }}">
            <input 
                type="text" 
                name="filtro_categoria" 
                class="form-control" 
                placeholder="Categoria"
                style="max-width: 200px;"
            >
            <button type="submit" class="btn btn-primary">Pesquisar</button>
        </form>
    </div>

    <ul class="list-group">
        @forelse($alimentos as $alimento)
            <li class="list-group-item">
                @if ($alimento->quantidade < 3)
                    <div class="alert alert-warning p-2 mb-2">
                        <strong>Estoque Baixo!</strong>
                    </div>
                @endif

                <div class="d-flex justify-content-between align-items-center">
                    <div>
                        <strong>{{ $alimento->nome }}</strong><br>
                        Quantidade: {{ $alimento->quantidade }}<br>
                        Validade: {{ $alimento->validade ? \Carbon\Carbon::parse($alimento->validade)->format('d/m/Y') : 'Sem validade' }}<br>
                        Categoria: {{ $alimento->categoria }}
                    </div>

                    <div class="text-end">
                        <a href="{{ route('alimentos.edit', $alimento) }}" class="btn btn-sm btn-warning me-1">Editar</a>

                        <form action="{{ route('alimentos.destroy', $alimento) }}" method="POST" class="d-inline">
                            @csrf
                            @method('DELETE')
                            <button type="submit" class="btn btn-sm btn-danger">Excluir</button>
                        </form>
                    </div>
                </div>
            </li>
        @empty
            <li class="list-group-item text-center">Nenhum alimento encontrado.</li>
        @endforelse
    </ul>

    <div class="mt-3">
        {{ $alimentos->appends(request()->query())->links('pagination::bootstrap-4') }}
    </div>

@endsection
