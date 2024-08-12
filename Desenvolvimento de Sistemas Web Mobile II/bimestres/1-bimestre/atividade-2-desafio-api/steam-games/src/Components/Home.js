import React, { useState, useEffect } from 'react';
import axios from 'axios';

export default function Home()
{
    const [Data, setData] = useState({
        id: '',
        advice: ''
    });

    useEffect(()=>{
        axios.get('https://api.adviceslip.com/advice')
        .then(response=>{
            setData({
                id: response.data.slip.id,
                advice: response.data.slip.advice
            });
        })
        .catch(err=>{
            console.log(`We've got an error while processing the request: ${err}`);
        })
    }, []);

    return(
        <>
            <h1>{Data.id}</h1>
            <p>{Data.advice}</p>
        </>
    );

}