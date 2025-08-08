import React from 'react';
import Button from './Button';
import "./Styles/MainAdvice.css";

// Componente com o GERADOR de Conselhos da Página, ele recebe os PROPS com o Conselho Gerado e a função de CURTIR Conselhos para ser aplicada no OnClick dos componente do Botão
export default function MainAdvice({ advice, handleLike })
{   
    return(
        <div className="advice-container">

            <div className="advice align-self-center">
                <p className="word clear-background">"{advice}"</p>
            </div>

            <Button className="roboto-mono action-button like-button clear-background align-self-center h3" label="Curtir Conselho" onClick={handleLike}/>
        </div>
    )
}
