import React from 'react';
import Button from './Button';
import "./Styles/LikedAdvice.css";

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
