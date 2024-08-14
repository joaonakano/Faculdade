import React, { useState, useEffect } from 'react';     // Importação das Bibliotecas necessárias
import axios from 'axios';

import Button from './Button';
import Advice from './Advice';

export default function Home()                          // Deixando o componente Home vísivel em todo o repositório 
{   
    const [Data, setData] = useState({                  // Criando uma variável Data para armazenar os dados da API
        id: '',                                         // Objeto JavaScript para filtrar e selecionar os dados necessários ID e CONSELHO
        advice: ''
    });

    const [advicesArray, setAdvice] = useState([]);

    const url = `https://api.adviceslip.com/advice?${new Date().getTime()}`;

    const fetchData = (retryCounter = 1) => {           // Função responsável por enviar as Requisições                                           
        axios.get(url)                                  // Utilizando a Biblioteca Axios para manipular essa requisição para o api.adviceslip.com
        .then(response => {                             // Em seguida armazenamos o retorno já padronizado em JSON pelo AXIOS
            const { id, advice } = response.data.slip
            setData({ id, advice });                    // Seleciona-se as informações necessárias e atualiza-se o estado do Objeto Data com o que foi retornado da requisição
        })
        .catch(err => {                                 // Se for possível algum erro de conexão, o erro é exibido no console e tenta-se realizar a requisição novamente
            if (retryCounter <= 3 ) {
                console.log(`Requisição falhou ${retryCounter}/3. Tentando uma nova requisição`)
                fetchData(retryCounter + 1);
            }
            console.log("Número máximo de requisições permitidas atingidas. Não foi possível obter os dados", err);
        })
    }

    const [showAdviceList, setShowAdviceList] = useState();

    const handleShowAdviceListClick = () => {
        showAdviceList
        ? setShowAdviceList(false)
        : setShowAdviceList(true);
    }

    const deleteAllAdvices = () => {
        localStorage.clear();
        setAdvice([]);
        console.log("LocalStorage has been cleared!");
    }
    
    const dislikeAdvice = (adviceId) => {
        if (verifyIdOnLocalStorage(adviceId)) {
            const updatedAdviceArray = advicesArray.filter(item => item.id !== adviceId);
            setAdvice(updatedAdviceArray);
        }
    }

    const newAdvice = () => {
        fetchData();
    }

    const likeAdvice = (adviceId, adviceText) => {
        if (!verifyIdOnLocalStorage(adviceId)) {
            setAdvice([...advicesArray, {
                id: adviceId,
                advice: adviceText
            }]);
        }
    }

    const verifyIdOnLocalStorage = (id) => {
        return advicesArray.some(item => item.id === id);
    }

    useEffect(() => {
        const localStorageData = JSON.parse(localStorage.getItem('advices'));

        localStorageData
        ? setAdvice(localStorageData)
        : setAdvice([]);
    }, []);
    
    useEffect(() => {
        localStorage.setItem('advices', JSON.stringify(advicesArray));
    }, [advicesArray]);                                 // Toda vez que o advicesArray é modificado (ADD ou REMOVE), é atualizado o localStorage

    useEffect(() => {                                   // Utilizando o Hook useEffect para realizar uma requisição para a API
        fetchData(url);                                 // Call da função de requisição
    }, []);

    return(
        <>
            <Advice id={Data.id} advice={Data.advice} handleLike={() => {likeAdvice(Data.id, Data.advice)}}/>
            <Button label="Apagar Todos Conselhos" onClick={deleteAllAdvices}/>
            <Button label="Novo Conselho" onClick={newAdvice}/>
            <Button label="Exibir/Ocultar Pins" onClick={handleShowAdviceListClick}/>
            {showAdviceList
            ? advicesArray.map(item => {
                    return(
                        <Advice key={item.id} id={item.id} advice={item.advice} handleDislike={() => {dislikeAdvice(item.id, item.advice)}}/>
                    )
                })
            : null
            }
        </>
    );

}



/*
IDEIAS QUE EU TIVE PARA ESTE APLICATIVO

- Um botao que é responsável por atualizar APENAS o componente, não a página - FEITO
- Armazenar conselhos que você gostou - FEITO
- Exibir uma lista de conselhos curtidos - FEITO
- Poder remover um conselho curtido - FEITO
- Armazenar no localStorage as curtidas para não sofrerem flush após a reinicialização do componente - FEITO

*/