import { useState, useEffect } from 'react'

import "./custom.scss";
import Task from '../Task/index.js';

export default function TaskList() {
    // Hook 1 - useState
    const [listaTarefas, setListaTarefas] = useState([]);
    const [tarefaConcluida, setTarefaConcluida] = useState(false);
    const [nomeTarefa, setNomeTarefa] = useState("");
    const [contador, setContador] = useState(0);

    // Funcao para adicionar tarefa (Input: title e completed)
    function adicionarTarefa() {
        // Pega-se a lista de objetos que ja existe e adiciona um novo objeto com ID (state CONTADOR), TITLE (state nomeTarefa) e COMPLETED (state tarefaConcluida)
        setListaTarefas([...listaTarefas, 
            {
            id: contador,
            title: nomeTarefa,
            completed: tarefaConcluida,
            }
        ]);
        
        // Retornando ao estado padrao dos Hooks
        setTarefaConcluida(false);
        setNomeTarefa("");
        setContador(contador + 1);
    }

    // Hook 2 - useEffect - Retorna como Lista de Tarefas o que tem no localStorage, se ja existe informacoes la, depois da renderizacao
    useEffect(() => {
        const tarefasStorage = JSON.parse(localStorage.getItem('tarefas'));

        tarefasStorage?
        setListaTarefas(tarefasStorage):
        setListaTarefas([]);
    }, []);
    
    // Hook 2 - useEffect - Atualiza e retorna no console.log o localStorage depois de cada atualizacao do estado
    useEffect(() => {
        if (listaTarefas.length > 0) {
            localStorage.setItem('tarefas', JSON.stringify(listaTarefas));
            console.log(JSON.parse(localStorage.getItem('tarefas')));
        }
    }, [listaTarefas]);
    
    
    return (
        <>
            <section className="todo">
                <h1>Tarefas</h1>
                 <ul>
                    {listaTarefas.map(tarefa => (
                        <Task title={tarefa.title} completed={tarefa.completed} key={tarefa.id}/>
                    ))}
                 </ul>
            </section>

            <section className="form">
                <input
                    type='text'
                    placeholder='Nome da Tarefa'
                    value={nomeTarefa}
                    onChange={(e) => setNomeTarefa(e.target.value)}
                />
                <div className="checkbox-container">
                    <label>Marcar como Concluida?</label>
                    <input
                        type='checkbox'
                        title='Tarefa Concluida?'
                        checked={tarefaConcluida}
                        onChange={(e) => setTarefaConcluida(e.target.checked)}
                    />
                </div>
                <button onClick={adicionarTarefa}>Adicionar Tarefa</button>
            </section>
        </>
    );
}



/* 

O que precisa entrar na funcao de criar tarefa?
    - titulo (String) e completed (Boolean)

O que precisa sair na funcao de criar tarefa?
    - A adicao das informacoes como um Objeto no estado de ListaTarefas

*/
