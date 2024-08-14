import React from 'react';

export default function Button({id, label, onClick})
{   
    return(
        <button id={id} onClick={onClick}>{label}</button>
    )
}