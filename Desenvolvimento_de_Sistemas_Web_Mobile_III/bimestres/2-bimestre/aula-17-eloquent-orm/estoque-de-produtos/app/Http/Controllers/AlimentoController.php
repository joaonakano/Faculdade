<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Models\Alimento;

class AlimentoController extends Controller
{
    public function index(Request $request)
    {
        $query = Alimento::query();

        if ($request->filtro === 'expirando_em_breve') {
            $hoje = now()->startOfDay();

            $query->whereNotNull('validade')
                ->where('validade', '>=', $hoje)
                ->orderBy('validade', 'asc');
        } else {
            $query->orderBy('created_at', 'desc');
        }
            
        if ($request->filtro_categoria) {
            $query->where('categoria', '=', $request->filtro_categoria)
            ->orderBy('nome', 'asc');
        } 

        $alimentos = $query->paginate(5);
        
        return view('alimentos.index', compact('alimentos'));
    }

    public function store(Request $request)
    {
        $request->validate([
            "nome" => 'required',
            "quantidade" => "required|integer",
            "validade" => "nullable|date",
            "categoria" => "required|alpha"
        ]);

        Alimento::create($request->all());

        return redirect()->route('alimentos.index')->with('status', 'Produto cadastrado com sucesso!');
    }

    public function create()
    {
        return view('alimentos.create');
    }
    
    public function edit(Alimento $alimento)
    {
        return view('alimentos.edit', compact("alimento"));
    }
    
    public function update(Request $request, Alimento $alimento)
    {
        $request->validate([
            "nome" => 'required',
            "quantidade" => "required|integer",
            "validade" => "nullable|date",
            "categoria" => "required|alpha" // Adicionar possivelmente a validacao de array para opcoes dentro do padrao aceito
        ]);

        $alimento->update($request->all());

        return redirect()->route('alimentos.index')->with('status', "Produto alterado com sucesso!");
    }

    public function destroy(Alimento $alimento)
    {
        $alimento->delete();

        return redirect()->route('alimentos.index')->with('status', "Produto removido com sucesso!");
    }
}
