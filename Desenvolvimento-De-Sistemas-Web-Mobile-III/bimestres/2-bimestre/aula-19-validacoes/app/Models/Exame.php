<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Exame extends Model
{
    protected $fillable = [
        'nome',
        'tipo_exame',
        'data_coleta',
        'laudo'
    ];
}
