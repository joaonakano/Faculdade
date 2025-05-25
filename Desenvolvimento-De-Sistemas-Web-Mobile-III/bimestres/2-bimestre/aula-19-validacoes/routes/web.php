<?php

use App\Http\Controllers\ExameController;
use Illuminate\Support\Facades\Route;

Route::get('/', [ExameController::class, 'index'])->name("exames.index");
Route::get('/exames/create', [ExameController::class, 'create'])->name("exames.create");
Route::post('/exames/create', [ExameController::class, 'store'])->name("exames.store");