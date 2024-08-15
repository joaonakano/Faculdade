import React, { useEffect, useState } from 'react';
import raw from '../Assets/Recipes.json';
import './Styles/Home.css'

export default function Home() {
  const [Data, setData] = useState([]);
  const [verReceitas, setVerReceitas] = useState();
    

  useEffect(() => {
    setData(raw);
  }, []);

  const addRecipe = () => {
    setData([...Data,
        {
            id: 4,
            titulo: "Sopa de Macaco",
            ingredientes: "Macaco e agua",
            modoPreparo: "Ponha o Macaco na agua e ferva, bonna petit"
        }
    ])
  }

  const bloquearReceitas = () => {
    if (verReceitas) {
        setVerReceitas(false);
    } else {
        setVerReceitas(true);
    }
  }

  const listRecipes = () => {
    console.log(Data);
  }

  return(
  <>
    {verReceitas
    ? Data.map(item => {
        return(
          <>
              <p className="recipe clicavel" >{item.titulo}</p>
          </>
        );
      })
    : null
    }
    <button onClick={addRecipe}>Adicionar Receita</button>
    <button onClick={bloquearReceitas}>Ver Receitas</button>
  </>

  );
}