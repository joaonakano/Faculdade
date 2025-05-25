<h1>Cadastrar um Exame</h1>

@if ($errors->any())
    @foreach ($errors->all() as $error)
        <p>{{ $error }}</p>
    @endforeach
@endif

<form action="{{ route('exames.create') }}" method="POST">
    @csrf
    <div>
        <label for="nome">Insira o Paciente:</label>
        <input type="text" name="nome" placeholder="Paciente" required>
    </div>
    <div>
        <label for="tipo_exame">Insira o Tipo de Exame:</label>
        <select name="tipo_exame" required>
            <option value="sequenciamento">Sequenciamento</option>
            <option value="pcr">PCR</option>
            <option value="microarray">Microarray</option>
        </select>
    </div>
    <div>
        <label for="data_coleta">Insira a Data de Coleta:</label>
        <input type="date" name="data_coleta" required>
    </div>
    <div>
        <label for="laudo">Insira um Laudo:</label><br>
        <textarea placeholder="Laudo" name="laudo" rows="4" cols="50"></textarea>
    </div>
    <button type="submit">Registrar</button>
</form>