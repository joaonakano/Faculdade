import React, { useEffect, useState } from 'react';

export default function App() {
  const [nutri, setNutri] = useState([]);

  useEffect(()=>{
    let url = 'https://sujeitoprogramador.com/rn-api/?api=posts';

    fetch(url) // Comando para enviar uma Requisição
    .then((r)=> r.json()) // Recebe a resposta em JSON
    .then((json) => setNutri(json)) // Salva a resposta na const nutri
  }, []);

  return(
    <>
      <header>
        <strong>React Nutri</strong>
      </header>

      {nutri.map((item)=>{ // Percorrendo o array JSON
        return(
          <article key={item.id}>
            <strong>{item.titulo}</strong><br/>
            <img src={item.capa} alt={item.titulo}/>
            <p>{item.subtitulo}</p>
            <button>Acessar</button>
            <br/><br/>
          </article>
        );
      })}
    </>
  );
}