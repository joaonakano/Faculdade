import React from 'react';

// Componente responsável por renderizar Botões que carregam estilos, placeholders e funções (já com o ID unico do Conselho configurado para cada renderização)
export default function Button({className, label, onClick})
{   
    return(
        <button className={className} onClick={onClick}>{label}</button>
    )
}