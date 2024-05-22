import React, { useState, useEffect } from 'react';

function App(){
  const [tarefas, setTarefas] = useState([]);

  const [input, setInput] = useState("");

  useEffect(() => {
    const tarefasStorage = localStorage.getItem('tarefas');

    if(tarefasStorage){
      setTarefas(JSON.parse(tarefasStorage));
    }
  },[]);
  
  useEffect(() => {
    localStorage.setItem('tarefas', JSON.stringify(tarefas));
  }, [tarefas]);
  
  function adicionarTarefa() {
    setTarefas([...tarefas, input]);
    setInput("");
  }

  return(
    <>
      <ul>
        {tarefas.map(tarefa => (
          <li key={tarefa}>{tarefa}</li>
        ))}
      </ul>
      <input type='text' value={input} onChange={stringUser => setInput(stringUser.target.value)}/>
      <button type='button' onClick={adicionarTarefa}>Adicionar</button>
    </>
  );
}

export default App;