import React, { Component } from 'react';
import './style.css';
import cronometro from './assets/cronometro.png';

// Criar Classe App que herda Component
class App extends Component {
  // Método Construtor
  constructor(props){
    // Receberá os atributos
    super(props);
    // Criar estado
    this.state = {
      numero: 0,
      botao: 'INICIAR'
    };
    // Criar variáveis auxiliares
    this.timer = null;
    this.ligar = this.ligar.bind(this);
    this.limpar = this.limpar.bind(this);
  }

  // Criar função ligar
  ligar() {
    let state = this.state;

    if(this.timer !== null) {
      clearInterval(this.timer);
      this.timer = null;
      state.botao = 'INICIAR';
    } else {
      // Função anônima
      this.timer = setInterval(()=>{
        // Estado com escopo
        let state = this.state;
        
        if ((state.numero-Math.trunc(state.numero)) >= 0.58 && (state.numero-Math.trunc(state.numero)) <= 0.60) {
          state.numero = Math.round(state.numero);
        } else {
          state.numero += 0.01;
        }

        // Devemos atualizar o estado
        this.setState(state);
      }, 100);
      state.botao = 'PARAR';
    }
    // Devemos atualizar o estado
    this.setState(state);
  }

  limpar(){
    if(this.timer !== null) {
      clearInterval(this.timer);
      this.timer = null;
    } else {
      let state = this.state;
      state.numero = 0;
      state.botao = 'INICIAR';
      this.setState(state);
    }
  }

  // Criar a interface
  render(){
    return(
      // Criar uma classe de HTML != classe do JavaScript
      <div className='container'>
        <img src={cronometro} className='img'/>
        <a className='timer'>{this.state.numero.toFixed(2)}</a>
        <div className='areaBtn'>
          <a className='botao' onClick={this.ligar}>{this.state.botao}</a>
          <a className='botao' onClick={this.limpar}>LIMPAR</a>
        </div>
      </div>
    );
  }
}

export default App;