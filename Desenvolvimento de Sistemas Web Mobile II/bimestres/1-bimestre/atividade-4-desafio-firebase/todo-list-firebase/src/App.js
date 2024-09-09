import React, { useState, useEffect } from 'react';
import { db, auth } from './firebaseConnection.js';

import "./styles/App.css";

import Welcome from "./Components/User/Welcome/Welcome";
import UserForm from "./Components/User/Form/UserForm";
import TodoForm from "./Components/TodoList/Form/TodoForm";
import TodoList from "./Components/TodoList/List/TodoList";

import {
  doc,
  collection,
  addDoc,
  getDocs,
  updateDoc,
  deleteDoc,
  onSnapshot,  
  setDoc
} from 'firebase/firestore';

import {
  createUserWithEmailAndPassword,
  signInWithEmailAndPassword,
  signOut,
  onAuthStateChanged
} from 'firebase/auth';

export default function App() {
  const [tarefa, setTarefa] = useState('');
  const [status, setStatus] = useState('');
  const [idTarefa, setIdTarefa] = useState('');
  const [idAutor, setIdAutor] = useState('');

  const [email, setEmail] = useState('');
  const [senha, setSenha] = useState('');
  
  const [usuario, setUsuario] = useState(false);
  const [detalhesUsuario, setDetalhesUsuario] = useState({});

  const [todoList, setTodoList] = useState([]);

  useEffect(() => {
    async function todoListFetch(){
      const data = onSnapshot(collection(db, "todoList"), snapshot => {
        let listaDeAfazeres = [];
        snapshot.forEach(doc => {
          listaDeAfazeres.push({
            idContent: doc.id,
            idTarefa: doc.data().idTarefa,
            titulo: doc.data().titulo,
            tarefa: doc.data().tarefa,
            status: doc.data().status,
            idAutor: doc.data().idAutor
          });
        });
        setTodoList(listaDeAfazeres);
      });
    }
    todoListFetch();
  }, []);

  useEffect(() => {
    async function verificarLogin() {
      onAuthStateChanged(auth, user => {
        if (user) {
          setUsuario(true);
          setDetalhesUsuario({
            uid: user.uid,
            email: user.email
          });
          setIdAutor(user.uid);
        } else {
          setUsuario(false);
        }
      })
    }
    verificarLogin();
  },[]);

  async function novoUsuario() {
    await createUserWithEmailAndPassword(auth, email, senha)
    .then(() => {
      alert("Usuário cadastrado com sucesso!");
      setEmail("");
      setSenha("");
    })
    .catch(err => {
      if (err.code === 'auth/weak-password') {
        alert("Senha fraca! Utilize uma senha mais segura.");
      }

      if (err.code === 'auth/email-already-in-use') {
        alert("E-mail já cadastrado! Tente novamente com um e-mail diferente ou acesse sua conta.")
      }
    });
  }

  async function logarUsuario() {
    await signInWithEmailAndPassword(auth, email, senha)
    .then(value => {
      alert("Usuário logado com sucesso!");
      setUsuario(true);
      setDetalhesUsuario({
        uid: value.user.uid,
        email: value.user.email
      });
      setEmail("");
      setSenha("");
    })
    .catch(err => {
      if (err.code === 'auth/invalid-email') {
        alert("E-mail invalido! Utilize um e-mail válido.");
      }

      if (err.code === 'auth/invalid-password') {
        alert("Senha incorreta! Insira uma senha válida para este usuário.");
      }
    });
  }

  async function fazerLogout() {
    await signOut(auth);
    setUsuario(false);
    setDetalhesUsuario({});
  }

  // (C)reate
  async function adicionarTarefa() {
    if(todoList.find(item => item.idTarefa === idTarefa)) {
      alert("O ID já existe no Banco de Dados!");
    } else {
      await setDoc(doc(db, "todoList", idTarefa), {
        tarefa: tarefa,
        status: status,
        idAutor: idAutor,
        idTarefa: idTarefa
      })
      .then(() => {
        alert("Registro realizado com sucesso!");
        setStatus("");
        setTarefa("");
      })
      .catch(err => {
        console.log(err);
      })
    }
  }

  // (R)ead
  async function buscarTodoList() {
    const config = collection(db, "todoList");
    await getDocs(config)
    .then(snapshot => {
      let lista = [];
      snapshot.forEach(doc => {
        lista.push({
          idContent: doc.id,
          idTarefa: doc.data().idTarefa,
          titulo: doc.data().titulo,
          tarefa: doc.data().tarefa,
          status: doc.data().status,
          idAutor: doc.data().idAutor
        });
      });
      setTodoList(lista);
      alert("Tarefas recuperadas com sucesso!");
    })
    .catch(err => {
      console.log(err);
    })
  }

  // (U)pdate
  async function editarTarefa() {
    const tarefaEditada = doc(db, "todoList", idTarefa);

    await updateDoc(tarefaEditada, {
      tarefa: tarefa,
      status: status
    })
    .then(() => {
      alert("Tarefa editada com sucesso!");
      setStatus('');
      setTarefa('');
    })
    .catch(err => {
      console.log(err);
    });
  }

  // (D)elete
  async function removerTarefa(id) {
    const tarefaDeletada = doc(db, "todoList", id);
    await deleteDoc(tarefaDeletada)
    .then(() => {
      return;
    })
    .catch(err => {
      console.log(err);
    })
  }

  return(
    <div className="grid-container">
      <div className="header header-container">
        <h1>Todo-List com Firebase</h1>
      </div>
      <aside>
        {usuario
          ? (<Welcome dataUser={detalhesUsuario} handleLogout={fazerLogout} />)
          : (<UserForm stateEmail={email} setEmail={setEmail} stateSenha={senha} setSenha={setSenha} handleRegister={novoUsuario} handleLogin={logarUsuario} />)
        }
      </aside>
      <div className='todo-form-container'>
        <TodoForm stateIdTarefa={idTarefa} setIdTarefa={setIdTarefa} stateTarefa={tarefa} setTarefa={setTarefa} stateStatus={status} setStatus={setStatus} handleTodoAddition={adicionarTarefa} handleTodoSearch={buscarTodoList} handleTodoEdit={editarTarefa} />
      </div>
      <main>
        <TodoList stateTodoList={todoList} stateDetalhesUsuario={detalhesUsuario} handleTodoRemove={removerTarefa} />
      </main>
    </div>
  );
}