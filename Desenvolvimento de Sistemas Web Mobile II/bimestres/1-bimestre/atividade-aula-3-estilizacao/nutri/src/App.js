import './App.css';
import React, { useState, useEffect } from 'react';

export default function App() {
  const [nutri, setNutri] = useState([]); // Criação de um Hook para atualizar o array de dados

  useEffect(()=>{ // Uso do Hook para consumir a API, converter para JSON e depois atualizar o array de dados
    fetch('https://sujeitoprogramador.com/rn-api/?api=posts') // Comando para enviar uma requisição a uma página
    .then((res)=>{ // res = o retorno da função fetch como parâmetro
      return res.json();  // Comando para executar um parse nos dados como JSON
    })
    .then((res)=>{  // res = o retorno da arrow function anterior como parâmetro
      setNutri(res); // Comando para atualizar o array de dados com o JSON obtido
    })
  }, []);
  
  return(
    <div className="secao-grid">
      <article className="main">
        <header>
          <h1 className="main-title header-title">Nutri</h1>
        </header>
        <div className="main-category">
          <span className="category">Tecnologia</span>
        </div>
        <h1 className="main-title">Consumo de uma API</h1>
        <p className="date">10/07/1996</p>
        <img className="main-image" src="https://images.pexels.com/photos/792381/pexels-photo-792381.jpeg" alt=""/>
        <p className="main-text">Voluptate dolore irure occaecat minim aliquip veniam tempor et sunt anim. Minim velit exercitation culpa irure labore. Sunt pariatur exercitation ullamco tempor est do incididunt consequat deserunt laborum culpa sint duis ad. Pariatur nulla minim est pariatur proident amet nisi eiusmod commodo sunt. Irure ex elit sint dolore anim ad occaecat. Duis voluptate magna minim elit elit sint occaecat labore ea culpa ex esse enim eu.</p>
        <p className="main-text">Voluptate dolore irure occaecat minim aliquip veniam tempor et sunt anim. Minim velit exercitation culpa irure labore. Sunt pariatur exercitation ullamco tempor est do incididunt consequat deserunt laborum culpa sint duis ad. Pariatur nulla minim est pariatur proident amet nisi eiusmod commodo sunt. Irure ex elit sint dolore anim ad occaecat. Duis voluptate magna minim elit elit sint occaecat labore ea culpa ex esse enim eu.</p>
        <p className="main-text">Voluptate dolore irure occaecat minim aliquip veniam tempor et sunt anim. Minim velit exercitation culpa irure labore. Sunt pariatur exercitation ullamco tempor est do incididunt consequat deserunt laborum culpa sint duis ad. Pariatur nulla minim est pariatur proident amet nisi eiusmod commodo sunt. Irure ex elit sint dolore anim ad occaecat. Duis voluptate magna minim elit elit sint occaecat labore ea culpa ex esse enim eu.</p>
      </article>
      <aside>
        <h2 className="categoria">Veja também sobre Saúde</h2>
        <div className="container">
          {nutri.map((item)=>{  // Iteração no array de dados, utilizando como parametro ITEM cada estrutura obtida
            return( 
              <>
              <article key={item.id} className="post-container">
                <img src={item.capa} alt={item.titulo}/>
                <div className="post-texto">
                  <span class="category">{item.categoria}</span><br/>
                  <h2 class="title">{item.titulo}</h2>
                </div>
              </article>
              <hr/>
              </>
            );
          })}
        </div>
      </aside>
    </div>
  )
}