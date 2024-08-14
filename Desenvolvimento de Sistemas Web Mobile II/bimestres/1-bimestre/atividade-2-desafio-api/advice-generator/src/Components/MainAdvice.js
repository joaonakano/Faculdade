import React from 'react';
import Button from './Button';
import "./Styles/MainAdvice.css";

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
