<?php

namespace App\Http\Controllers;

use App\Models\Reserva;
use Illuminate\Http\Request;

class ReservaController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        $reservas = Reserva::all();                                                                  // Pega todos os 'modelos' do DB. (1-O que sao modelos?)
        return view('reservas.index', compact('reservas'));                    // Retorna uma view para o 'reservas.index' com os dados coletados anteriormente dos 'modelos'.
    }

    /**
     * Show the form for creating a new resource.
     */
    public function create()
    {
        return view('reservas.create');                                                        // Retorna uma view para a página de registro de reservas.
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(Request $request)
    {
        $request->validate(['sala_id'=>'required', 'usuario'=>'required', 'data'=>'required', 'horario'=>'required']); // Valida se os campos 'sala_id','usuario', 'data' e 'horario' foram preenchidos.
        Reserva::create($request->all());                                                           // Cria um novo 'modelo' com os inputs da 'request'.
        return redirect()->route('reservas.index')->with('success', 'Reserva registrada com sucesso!'); // Redireciona o usuário para a página 'reservas' com uma mensagem de sucesso.
    }

    /**
     * Display the specified resource.
     */
    public function show(Reserva $reserva)
    {
        return view('reservas.show', compact('reserva'));                     // Retorna uma view para a página 'reservas.show' com o conteúdo da reserva. (1-O que é o Reserva $reserva?)
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(Reserva $reserva)
    {
        return view('reservas.edit', compact('reserva'));                     // Retorna uma view para a página 'reservas.edit' com o conteúdo da reserva.
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, Reserva $reserva)
    {
        $request->validate(['sala_id'=>'required', 'usuario'=>'required', 'data'=>'required', 'horario'=>'required']); // Valida se os campos 'sala_id', 'usuario', 'data', e 'horario' foram preenchidos.
        $reserva->update($request->all());                                                          // Atualiza o modelo 'Reserva' com as informações dos inputs da 'request'.
        return redirect()->route('reservas.index')->with('success', 'Reserva atualizada com sucesso!'); // Redireciona o usuário para a página 'reservas' com uma mensagem de sucesso. (1-Como funciona o with?)
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Reserva $reserva)
    {
        $reserva->delete();                                                                         // Apaga o 'modelo' da database.
        return redirect()->route('reservas.index')->with('success', 'Reserva excluída com sucesso!'); // Redireciona o usuário para a página 'reservas' com uma mensagem de sucesso.
    }
}
