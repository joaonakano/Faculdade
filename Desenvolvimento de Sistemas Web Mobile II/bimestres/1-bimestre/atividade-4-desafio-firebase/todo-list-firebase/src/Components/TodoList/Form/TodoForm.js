import './index.css'

export default function TodoForm({ stateIdTarefa, setIdTarefa, stateTarefa, setTarefa, stateStatus, setStatus, handleTodoAddition, handleTodoSearch, handleTodoEdit }) {
    return(
        <div className='align-text-center'>
            <div className='main-form-field'>
                <h2 className='transparent-background black'>Menu de Tarefas</h2>

                <div className='wrapper-flex-container transparent-background'>
                    <fieldset>
                        <legend className=''>ID da Tarefa:</legend>
                        <input
                        className='transparent-background text-input'
                        placeholder="672"
                        value={stateIdTarefa}
                        onChange={e => {setIdTarefa(e.target.value)}} />
                    </fieldset>

                    <fieldset>
                        <legend className=''>Tarefa:</legend>
                        <input
                        className='transparent-background text-input'
                        type="text"
                        placeholder="Ir ao Hiper-Mercado"
                        value={stateTarefa}
                        onChange={e => {setTarefa(e.target.value)}}/>
                    </fieldset>
            
                    <fieldset className=''>
                        <legend>Escolha o Status:</legend>
                        <div className='transparent-background container-radio'>
                            <div className='transparent-background'>
                                <input
                                className='transparent-background'
                                type="radio" 
                                id="a fazer" 
                                name="status" 
                                value="a fazer" 
                                checked={stateStatus === 'a fazer'} 
                                onChange={e => {setStatus(e.target.value)}} 
                                />
                                <label className='transparent-background'>a fazer</label>
                            </div>
                            <div className='transparent-background'>
                                <input
                                className='transparent-background'
                                type="radio" 
                                id="concluido" 
                                name="status" 
                                value="concluido" 
                                checked={stateStatus === 'concluido'} 
                                onChange={e => {setStatus(e.target.value)}} 
                                />
                                <label className='transparent-background'>concluído</label>
                            </div>
                            <div className='transparent-background'>
                                <input
                                className='transparent-background'
                                type="radio" 
                                id="em andamento" 
                                name="status" 
                                value="em andamento" 
                                checked={stateStatus === 'em andamento'} 
                                onChange={e => {setStatus(e.target.value)}} 
                                />
                                <label className='transparent-background'>em andamento</label>
                            </div>
                        </div>
                    </fieldset>


                </div>

                <button className='transparent-background' onClick={handleTodoAddition}>Inserir</button>
                <button className='transparent-background' onClick={handleTodoSearch}>Buscar</button>
                <button className='transparent-background' onClick={handleTodoEdit}>Editar</button>
            </div>
        </div>
    );
}