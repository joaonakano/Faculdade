import React from 'react';

import Button from './Button';

export default function Advice({id, advice, handleLike, handleDislike})
{   
    return(
        <div className="">
            <h1>{id}</h1>
            <p>{advice}</p>

            { handleLike
            ? <Button id={`like-${id}`} label="Favoritar" onClick={handleLike}/>
            : null
            }

            { handleDislike
            ? <Button id={`dislike-${id}`} label="Desfavoritar" onClick={handleDislike} />
            : null
            }
        </div>
    )
}


// <DislikeButton id={`dislike-${id}`} label="Remover Conselho" onClick={deleteAdvice(id)}/>
