import React from 'react';
import Button from './Button';
import "./Styles/LikedAdvice.css";

// Componente com a LISTA de Conselhos da Página, ele recebe os PROPS com o texto do Conselho e a função de DESCURTIR Conselhos para ser aplicada no OnClick dos componente do Botão
export default function LikedAdvice({ advice, handleDislike })
{   
    return(
        <div className="grid-container">
            <div className="likedadvices-container">
                <p className="word clear-background">"{advice}"</p>
                <Button className="roboto-mono align-self-center dislike-button" label="x" onClick={handleDislike} />
            </div>
        </div>
    )
}
