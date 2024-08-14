import React, { useState, useEffect } from 'react';     // Importação das Bibliotecas necessárias
import axios from 'axios';

import MainAdvice from './MainAdvice';
import LikedAdvice from './LikedAdvice';
import Header from './Header';

import './Styles/Home.css'

export default function Home()                          // Deixando o componente Home vísivel em todo o repositório 
{   
    const url = `https://api.adviceslip.com/advice?${new Date().getTime()}`;
    
    const [advicesArray, setAdvice] = useState([]);

    const [Data, setData] = useState({                  // Criando uma variável Data para armazenar os dados da API
        id: '',                                         // Objeto JavaScript para filtrar e selecionar os dados necessários ID e CONSELHO
        advice: ''
    });

    // FUNÇÃO QUE REALIZA REQUISIÇÕES AO SERVIDOR DE CONSELHOS
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

    // HOOKS PARA ATUALIZAR E RECUPERAR DADOS DO LOCALSTORAGE
    useEffect(() => {
        fetchData();                                    // Call da função de requisição
        const localStorageData = JSON.parse(localStorage.getItem('advices'));

        localStorageData
        ? setAdvice(localStorageData)
        : setAdvice([]);
    }, []);
    
    useEffect(() => {
        localStorage.setItem('advices', JSON.stringify(advicesArray));
    }, [advicesArray]);                                 // Toda vez que o advicesArray é modificado (ADD ou REMOVE), é atualizado o localStorage

    
    // PRINCIPAIS FUNÇÕES DOS BOTÕES
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
        if (showAdviceList == true) {
            handleShowAdviceListClick();
        }
    }

    const likeAdvice = (adviceId, adviceText) => {
        if (!verifyIdOnLocalStorage(adviceId)) {
            setAdvice([...advicesArray, {
                id: adviceId,
                advice: adviceText
            }]);
        }
    }

    // VERIFICADOR
    const verifyIdOnLocalStorage = (id) => {
        return advicesArray.some(item => item.id === id);
    }

    return(
        <div>
            <link rel="preconnect" href="https://fonts.googleapis.com"></link>
            <link rel="preconnect" href="https://fonts.gstatic.com"></link>
            <link href="https://fonts.googleapis.com/css2?family=Roboto+Mono:ital,wght@0,100..700;1,100..700&display=swap" rel="stylesheet"></link>
            
            <div className="center roboto-mono">
                <Header handleFullDeletion={deleteAllAdvices} handlesShowAdviceListClick={handleShowAdviceListClick} handleNewAdvice={newAdvice}/>                    
                {showAdviceList
                    ? advicesArray.map(item => {
                        return(<LikedAdvice key={item.id} advice={item.advice} handleDislike={() => {dislikeAdvice(item.id, item.advice)}}/>)
                    })
                    : <MainAdvice advice={Data.advice} handleLike={() => {likeAdvice(Data.id, Data.advice)}}/>
                }
            </div>
        </div>
    );

}
