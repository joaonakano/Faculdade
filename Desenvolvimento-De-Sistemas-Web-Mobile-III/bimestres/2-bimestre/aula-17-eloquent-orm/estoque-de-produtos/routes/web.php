<?php

use App\Http\Controllers\AlimentoController;
use Illuminate\Support\Facades\Route;

Route::get('/', [AlimentoController::class, 'index'])->name('alimentos.index');

Route::get('/create', [AlimentoController::class, 'create'])->name('alimentos.create');
Route::get('/{alimento}/edit', [AlimentoController::class, 'edit'])->name('alimentos.edit');

Route::post('/', [AlimentoController::class, 'store'])->name('alimentos.store');
Route::put('/{alimento}', [AlimentoController::class, 'update'])->name('alimentos.update');

Route::delete('/{alimento}', [AlimentoController::class, 'destroy'])->name('alimentos.destroy');