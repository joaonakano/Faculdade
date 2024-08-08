import React, { useState, useEffect } from 'react';
import axios from 'axios';
import './App.css';

const App=()=>{
  const [Frase, setFrase] = useState({
    Icon: '',
    Frase: ''
  });

  useEffect(()=>{
    axios.get('https://api.chucknorris.io/jokes/random')
    .then(res=>{
      let dataChuck = res.data;
      setFrase({Icon: dataChuck.icon_url, Frase: dataChuck.value});
    })
    .catch(err=>{
      console.log(err);
    })
  },[]);

  function HandleClick(){
    window.location.reload();
  }

  return(
    <div className="main-content">
      <h1>Frases do Mito dos Mitos: Bols-... Chuck Norris!</h1>
      <img src={Frase.Icon} alt="imagem" onClick={HandleClick} />
      <p>{Frase.Frase}</p>
    </div>
  );
  
}



export default App;