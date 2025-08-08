<?php

namespace App\Http\Controllers;

use App\Models\Exame;
use Illuminate\Http\Request;
use Illuminate\Validation\Rule;
use Validator;

class ExameController extends Controller
{
    public function index() {
        $exames = Exame::all();

        return view('exames.index', compact('exames'));
    }

    public function create(Request $request) {
        return view('exames.create');
    }

    public function store(Request $request) {

        // Validação com mensagens customizadas
        $validator = Validator::make($request->all(), [
            "nome" => "required|alpha|max:100",
            
            "tipo_exame" => [
                "required",
                //Rule::in(["sequenciamento", "pcr", "microarray"])
                "in:sequenciamento,pcr,microarray"
            ],
            
            "data_coleta" => [
                'required',
                Rule::date()->afterOrEqual(today())
            ],

            "laudo" => "max:500",
        ], [
            'nome.required' => 'O nome do paciente é obrigatório',
            'nome.alpha' => 'O nome do paciente deve contar apenas letras',
            'nome.max' => 'O nome do paciente deve conter menos de 100 caracteres',
            'tipo_exame.required' => 'O tipo de exame é obrigatório',
            'tipo_exame.in' => 'O tipo de exame não é um tipo válido',
            'data_coleta.required' => 'A data de coleta deve ser obrigatória',
            'data_coleta.after_or_equal' => 'A data do exame deve ser atual ou posterior',
            'laudo.max' => 'O laudo deve conter menos de 500 caracteres'
        ]);

        if ($validator->fails()) {
            return redirect()->route('exames.create')->withErrors($validator)->withInput();
        }

        Exame::create($request->all());
        
        return redirect()->route('exames.index')->with('status', 'Cadastro realizado com sucesso!');
    }

    public function update(Request $request, Exame $exame) {

    }

    public function edit(Request $request) {

    }

    public function destroy(Request $request, Exame $exame) {

    }
}
