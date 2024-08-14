import React from 'react';

export default function Button({className, label, onClick})
{   
    return(
        <button className={className} onClick={onClick}>{label}</button>
    )
}