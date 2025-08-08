<h1>Exames</h1>

<a href="{{ route("exames.create") }}">Novo Exame</a>

<div>
    @foreach ($exames as $exame)
        <div>
            <p><strong>{{ $exame->nome }}</strong> -
            {{ $exame->tipo_exame }} -
            {{ $exame->data_coleta }}
        </div>
    @endforeach
</div>