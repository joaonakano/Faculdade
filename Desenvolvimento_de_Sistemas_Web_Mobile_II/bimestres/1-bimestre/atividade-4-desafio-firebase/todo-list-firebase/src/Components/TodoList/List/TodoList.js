import './index.css';

export default function TodoList({ stateTodoList, stateDetalhesUsuario, handleTodoRemove }) {
    const colorList = ["#FADADD","#AEC6CF","#77DD77","#FDFD96","#D6AEDD","#FFB3AB","#FFDAB9","#98FF98","#E6E6FA","#F5F5DC"];

    return(
        <div className="flex-container">
            {stateTodoList.map(item => {
                if(item.idAutor === stateDetalhesUsuario.uid) {
                    let randomColor = colorList[Math.floor(Math.random() * colorList.length)]
                    return(
                        <div className="flex-item" key={item.idTarefa} style={{backgroundColor: randomColor}}>
                            <div className='transparent-background top-card-container'>
                                <h3 className="transparent-background h3 black">{item.status}</h3>
                                <button className='remove-button' onClick={() => handleTodoRemove(item.idTarefa)}>X</button>
                            </div>
                            <h2 className="transparent-background h2 black">{item.tarefa}</h2>
                            <span className="transparent-background text black">ID: {item.idTarefa}</span>
                        </div>
                    )
                }
            })}
      </div>
    );
}

/*

*/