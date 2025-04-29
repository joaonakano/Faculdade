<?php

use App\Http\Controllers\ReservaController;
use App\Http\Controllers\SalaController;
use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('welcome');
});

Route::get('/greeting', function () {
    return 'Hello World!';
});

Route::resource('/reservas', ReservaController::class);         // O que é o 'ReservaController::class'?
Route::resource('/salas', SalaController::class);