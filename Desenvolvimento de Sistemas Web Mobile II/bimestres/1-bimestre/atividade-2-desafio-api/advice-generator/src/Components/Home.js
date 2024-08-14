import React, { useState, useEffect } from 'react';     // Importação das Bibliotecas necessárias
import axios from 'axios';

import MainAdvice from './MainAdvice';                  // Importação dos componentes vitais da Home: Header, MainAdvice e LikedAdvices
import LikedAdvice from './LikedAdvice';
import Header from './Header';
import Footer from './Footer';

import './Styles/Home.css'

export default function Home()                          // Deixando o componente Home vísivel em todo o repositório 
{   
    const url = `https://api.adviceslip.com/advice?${new Date().getTime()}`;    // Constante que armazena a URL da API concatenada com a função de geração de horário (O motivo é permitir múltiplas requisições da maneira mais facilitada)
    
    const [advicesArray, setAdvice] = useState([]);     // Variável mais importante do código: uma lista que armazena todos os Conselhos puxados do localStorage

    const [Data, setData] = useState({                  // Criando uma variável Data para armazenar os dados da API
        id: '',                                         // Objeto JavaScript para filtrar e selecionar os dados necessários ID e CONSELHO das requisições
        advice: ''
    });

    // FUNÇÃO QUE REALIZA REQUISIÇÕES AO SERVIDOR DE CONSELHOS
    const fetchData = (retryCounter = 1) => {           // Função responsável por enviar as Requisições                                           
        axios.get(url)                                  // Utilizando a Biblioteca Axios para manipular essa requisição para o api.adviceslip.com
        .then(response => {                             // Em seguida armazenamos o retorno já padronizado em JSON pelo AXIOS
            const { id, advice } = response.data.slip   // Filtro que capta apenas o ID e o ADVICE da resposta à requisição
            setData({ id, advice });                    // Atualiza-se o estado do Data com o que foi retornado da requisição já filtrado
        })
        .catch(err => {                                 // Se for possível algum erro de conexão, o erro é exibido no console e passa por uma validação
            if (retryCounter <= 3 ) {                   // A validação é esta: Se o contador de tentativas for menor ou igual a 3 tentativas, então ele está permitido a tentar realizar mais uma requisição
                console.log(`Requisição falhou ${retryCounter}/3. Tentando uma nova requisição`)
                fetchData(retryCounter + 1);            // Atualização desse contador de requests
            }
            console.log("Número máximo de requisições permitidas atingidas. Não foi possível obter os dados", err); // Se não for possível mesmo enviar as requisições, alerta-se o Console
        })
    }

    // HOOKS PARA ATUALIZAR E RECUPERAR DADOS DO LOCALSTORAGE
    useEffect(() => {
        fetchData();                                    // Call da função de requisição
        const localStorageData = JSON.parse(localStorage.getItem('advices'));   // Em seguida, armazenamos tudo que tem no localStorage no item 'advices'

        localStorageData                                // Operador ternário que valida se veio algo do localStorage ou não
        ? setAdvice(localStorageData)                   // Se veio algo, então o Array de Conselhos é atualizado com esses dados
        : setAdvice([]);                                // Se não veio nada, então atualizasmos o Array de Conselhos com um array vazio
    }, []);                                             // Executa-se apenas na primeira renderização
    
    useEffect(() => {                                   // Hook que atualiza o LocalStorage com toda a modificação feita no Array de Conselhos
        localStorage.setItem('advices', JSON.stringify(advicesArray));
    }, [advicesArray]);                                 // Toda vez que o advicesArray é modificado (ADD ou REMOVE), é atualizado o localStorage

    // PRINCIPAIS FUNÇÕES DOS BOTÕES
    const [showAdviceList, setShowAdviceList] = useState(); // Uma variável que armazena um booleano para ativar ou desativar a visualização dos Conselhos Curtidos

    const handleShowAdviceListClick = () => {           // Função responsável por validar se o botão de Listagem de Conselhos Curtidos foi pressionado antes ou não
        showAdviceList                                  // Operador ternário que faz a validação da variável Mostrar Lista de Conselhos
        ? setShowAdviceList(false)                      // Se verdadeiro, ou seja, se esse botão foi pressionado anteriormente e a visualização está ativa, movemos para falso a fim de bloquear um posterior componente
        : setShowAdviceList(true);                      // Se dalso, ou seja, se esse botão não foi pressionado anteriormente e a visualização está inativa, movemos para verdadeiro a fim de desbloquear um posterior componente
    }

    const deleteAllAdvices = () => {                    // Função responsável por apagar tudo que está armazenado no LocalStorage
        localStorage.clear();                           // Limpa-se o localStorage
        setAdvice([]);                                  // Em seguida adicionamos um Array vazio para evitar conflitos
        console.log("LocalStorage has been cleared!");  // Mensagem no Console que o LocalStorage foi apagado com sucesso
    }
    
    const dislikeAdvice = (adviceId) => {               // Função responsável por apagar um Conselho Curtido, ela recebe o ID do componente a ser removido como parâmetro
        if (verifyIdOnLocalStorage(adviceId)) {         // Uma função validador verifica se o ID do Conselho a ser removido existe no LocalStorage
            const updatedAdviceArray = advicesArray.filter(item => item.id !== adviceId);   // Se existe, criamos um array atualizado filtrando por itens que não contenham o ID informado como parâmetro
            setAdvice(updatedAdviceArray);              // Atualizamos o Array de Conselhos com o array já filtrado
        }
    }

    const newAdvice = () => {                           // Função responsável por gerar um novo Conselho
        fetchData();                                    // Envia-se uma nova requisição para a API para obter um conselho novo
        if (showAdviceList === true) {                   // Validador que verifica se o booleano da Visualização da Lista de Conselhos Curtidos é verdadeiro, ou seja, se o usuário estiver na página de Listagem dos Conselhos Curtidos, ele será automaticamente para a página principal: Gerador de Conselhos
            handleShowAdviceListClick();                // Função que inverte o valor do booleano da Visualização da Lista de Conselhos Curtidos para falso, ocultando sua visualização portanto
        }
    }

    const likeAdvice = (adviceId, adviceText) => {      // Função responsável por Curtir o Conselho Gerado, ela recebe como parâmetros o ID e TEXTO do Conselho a ser armazenado
        if (!verifyIdOnLocalStorage(adviceId)) {        // Validador que verifica se o ID inserido no parâmetro existe no LocalStorage, se sim, não tem por que nós armazenarmos novamente
            setAdvice([...advicesArray, {               // Em caso negativo e o ID não existe no localStorage, atualizamos o Array de Conselhos com os valores já existentes + o ID e o CONSELHO novos
                id: adviceId,
                advice: adviceText
            }]);
        }
    }

    // VERIFICADOR
    const verifyIdOnLocalStorage = (id) => {            // Função que valida se um ID existe no LocalStorage, ela recebe como parâmetro o ID a ser verificado
        return advicesArray.some(item => item.id === id);   // O Array de Conselhos funciona como um espelho do que existe no LocalStorage, então, verifica-se neste array a presença do ID do parâmetro e retorna um booleano
    }

    // RENDERIZADOR
    const renderAdviceList = () => {                    // Função que verifica e renderiza a Lista de Conselhos Curtidos
        if (advicesArray.length > 0) {                  // Se o Array de Conselhos for maior que zero, significa que há conselhos salvos no LocalStorage, então iteramos nesse array para exibí-los
            return advicesArray.map(item => ( 
                <LikedAdvice key={item.id} advice={item.advice} handleDislike={() => {dislikeAdvice(item.id, item.advice)}}/>   // Muito importante prestar atenção nos PROPS da função desse Componente, eles carregam e enviam o ID e o Texto do Conselho para as funções aqui da Home
            ));
        } else {
            return <p>Você não tem conselhos salvos. Experimente curtir um!</p>;
        }
    }

    return(
        <div>
            <link rel="preconnect" href="https://fonts.googleapis.com"></link>
            <link rel="preconnect" href="https://fonts.gstatic.com"></link>
            <link href="https://fonts.googleapis.com/css2?family=Roboto+Mono:ital,wght@0,100..700;1,100..700&display=swap" rel="stylesheet"></link>
            
            <div className="center roboto-mono">
                <Header handleFullDeletion={deleteAllAdvices} handlesShowAdviceListClick={handleShowAdviceListClick} handleNewAdvice={newAdvice} isListVisible={showAdviceList}/>                    
                {showAdviceList                         // Operador ternário responsável por alternar entre a Lista de Conselhos Curtidos e o Gerador de Conselhos, utiliza-se como condicional a váriavel ExibirListaDeConselhos
                    ? renderAdviceList()                // Se o booleano que valida se a Lista deve aparecer for Verdadeira, renderiza a Lista de Conselhos, caso contrário exibe-se o Gerador de Conselhos
                    : <MainAdvice advice={Data.advice} handleLike={() => {likeAdvice(Data.id, Data.advice)}}/>  // Muito importante prestar atenção nos PROPS da função, eles carregam e enviam o ID e o Texto do Conselho para as funções aqui da Home
                }
            </div>
            <Footer />
        </div>
    );

}
